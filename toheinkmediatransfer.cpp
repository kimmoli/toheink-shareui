#include "toheinkmediatransfer.h"
#include "converter.h"

ToheinkMediaTransfer::ToheinkMediaTransfer(QObject *parent) :
    MediaTransferInterface(parent)
{
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
    return QUrl::fromLocalFile("/usr/share/toheink-shareui/qml/notification.png");
}

void ToheinkMediaTransfer::cancel()
{
    setStatus(MediaTransferInterface::TransferCanceled);
}

void ToheinkMediaTransfer::start()
{
    _mediaName = mediaItem()->value(MediaItem::Url).toString().replace("file://", "");

    /* tell that we are starting this */
    setStatus(MediaTransferInterface::TransferStarted);

    Converter* converter = new(Converter);

    converter->convert(_mediaName, QString("/tmp/img.xbm"));

    system("tail -n +4 /tmp/img.xbm | xxd -r -p > /tmp/epd/display");
    system("echo U > /tmp/epd/command");

    /* Progress ?? */
    // setProgress(qreal(0.0));

    /* In case of error */
    if (0)
        setStatus(MediaTransferInterface::TransferInterrupted);

    /* Finished */
    setStatus(MediaTransferInterface::TransferFinished);

    delete converter;

}
