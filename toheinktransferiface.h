#ifndef TOHEINKTRANSFERIFACE_H
#define TOHEINKTRANSFERIFACE_H

#include <TransferEngine-qt5/transferplugininterface.h>
#include <TransferEngine-qt5/transferplugininfo.h>
#include <TransferEngine-qt5/transfermethodinfo.h>
#include <TransferEngine-qt5/mediatransferinterface.h>

class ToheinkSharePlugin : public QObject, public TransferPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "harbour.toheink.transfer.plugin")
    Q_INTERFACES(TransferPluginInterface)
public:
    ToheinkSharePlugin();
    ~ToheinkSharePlugin();

    QString pluginId() const;
    bool enabled() const;
    TransferPluginInfo *infoObject();
    MediaTransferInterface *transferObject();
};

#endif // TOHEINKTRANSFERIFACE_H
