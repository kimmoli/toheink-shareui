#ifndef TOHEINKMEDIATRANSFER_H
#define TOHEINKMEDIATRANSFER_H

#include <TransferEngine-qt5/mediatransferinterface.h>
#include <TransferEngine-qt5/mediaitem.h>

#include <QString>
#include <QVariant>

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
    QString _mediaName;

public slots:
    void	cancel();
    void	start();

};

#endif // TOHEINKMEDIATRANSFER_H
