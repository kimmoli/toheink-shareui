#ifndef TOHEINKMEDIATRANSFER_H
#define TOHEINKMEDIATRANSFER_H

#include <TransferEngine-qt5/mediatransferinterface.h>
#include <TransferEngine-qt5/mediaitem.h>

#include <QtDBus/QtDBus>

#define SERVER_INTERFACE "harbour.toheink.server"
#define SERVER_SERVICE "harbour.toheink.server"
#define SERVER_PATH "/"

class ToheinkMediaTransfer : public MediaTransferInterface
{
    Q_OBJECT
public:
    ToheinkMediaTransfer(QObject * parent = 0);
    ~ToheinkMediaTransfer();

    bool	cancelEnabled() const;
    QString	displayName() const;
    bool	restartEnabled() const;
    QUrl	serviceIcon() const;

private:
    QDBusInterface *_iface;
    QString _mediaName;
    QString _messageId;

private slots:
    void uploadMediaProgress(const QString &jid, const QString &msgId, int percent);
    void uploadMediaFinished(const QString &jid, const QString &msgId, const QString &remoteUrl);
    void uploadMediaStarted(const QString &jid, const QString &msgId, const QString &localUrl);
    void uploadMediaFailed(const QString &jid, const QString &msgId);

public slots:
    void	cancel();
    void	start();

};

#endif // TOHEINKMEDIATRANSFER_H
