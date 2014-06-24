#include "toheinktransferiface.h"
#include "toheinkplugininfo.h"
#include "toheinkmediatransfer.h"

#include <QtPlugin>

ToheinkSharePlugin::ToheinkSharePlugin()
{

}

ToheinkSharePlugin::~ToheinkSharePlugin()
{

}

QString ToheinkSharePlugin::pluginId() const
{
    return QLatin1String("ToheinkSharePlugin");
}

bool ToheinkSharePlugin::enabled() const
{
    return true;
}

TransferPluginInfo *ToheinkSharePlugin::infoObject()
{
    return new ToheinkPluginInfo;
}

MediaTransferInterface *ToheinkSharePlugin::transferObject()
{
    return new ToheinkMediaTransfer;
}
