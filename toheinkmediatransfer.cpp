#include "toheinkmediatransfer.h"

ToheinkMediaTransfer::ToheinkMediaTransfer(QObject *parent) :
    MediaTransferInterface(parent)
{
    _iface = new QDBusInterface(SERVER_SERVICE, SERVER_PATH, SERVER_INTERFACE, QDBusConnection::sessionBus(), this);

    QDBusConnection::sessionBus().connect(SERVER_SERVICE, SERVER_PATH, SERVER_INTERFACE,
                                          "uploadFailed", this, SIGNAL(uploadMediaFailed(QString,QString)));
    QDBusConnection::sessionBus().connect(SERVER_SERVICE, SERVER_PATH, SERVER_INTERFACE,
                                          "uploadFinished", this, SIGNAL(uploadMediaFinished(QString,QString,QString)));
    QDBusConnection::sessionBus().connect(SERVER_SERVICE, SERVER_PATH, SERVER_INTERFACE,
                                          "uploadStarted", this, SIGNAL(uploadMediaStarted(QString,QString,QString)));
    QDBusConnection::sessionBus().connect(SERVER_SERVICE, SERVER_PATH, SERVER_INTERFACE,
                                          "uploadProgress", this, SIGNAL(uploadMediaProgress(QString,QString,int)));
}

ToheinkMediaTransfer::~ToheinkMediaTransfer()
{

}

bool ToheinkMediaTransfer::cancelEnabled() const
{
    return false;
}

QString ToheinkMediaTransfer::displayName() const
{
    return QString("Toheink");
}

bool ToheinkMediaTransfer::restartEnabled() const
{
    return false;
}

QUrl ToheinkMediaTransfer::serviceIcon() const
{
    return QUrl::fromLocalFile("/usr/share/harbour-toheink-server/images/notification.png");
}

void ToheinkMediaTransfer::uploadMediaProgress(const QString &jid, const QString &msgId, int percent)
{
    Q_UNUSED(jid);
    if (msgId == _messageId) {
        if (percent < 100) {
            qreal s_progress = (qreal)percent / (qreal)100;
            setProgress(s_progress);
        }
        else {
            setStatus(MediaTransferInterface::TransferFinished);
        }
    }
}

void ToheinkMediaTransfer::uploadMediaFinished(const QString &jid, const QString &msgId, const QString &remoteUrl)
{
    Q_UNUSED(jid);
    Q_UNUSED(remoteUrl);
    if (msgId == _messageId) {
        setStatus(MediaTransferInterface::TransferFinished);
    }
}

void ToheinkMediaTransfer::uploadMediaStarted(const QString &jid, const QString &msgId, const QString &localUrl)
{
    Q_UNUSED(jid);
    if (localUrl == _mediaName) {
        _messageId = msgId;
        setStatus(MediaTransferInterface::TransferStarted);
    }
}

void ToheinkMediaTransfer::uploadMediaFailed(const QString &jid, const QString &msgId)
{
    Q_UNUSED(jid);
    if (msgId == _messageId) {
        setStatus(MediaTransferInterface::TransferInterrupted);
    }
}

void ToheinkMediaTransfer::cancel()
{
    setStatus(MediaTransferInterface::TransferCanceled);
}

void ToheinkMediaTransfer::start()
{
    _mediaName = mediaItem()->value(MediaItem::Url).toString().replace("file://", "");
    if (_iface) {
        QStringList jids = mediaItem()->value(MediaItem::Description).toString().split(",");
        _iface->call(QDBus::NoBlock, "sendMedia", jids, _mediaName);
    }
}
