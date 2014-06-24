#include "toheinkplugininfo.h"

ToheinkPluginInfo::ToheinkPluginInfo(): m_ready(false)
{
}

ToheinkPluginInfo::~ToheinkPluginInfo()
{

}

QList<TransferMethodInfo> ToheinkPluginInfo::info() const
{
    return m_infoList;
}

void ToheinkPluginInfo::query()
{
    TransferMethodInfo info;

    QStringList capabilities;
    capabilities << QLatin1String("image/*");

    info.displayName     = QLatin1String("Toheink");
    info.methodId        = QLatin1String("ToheinkSharePlugin");
    info.shareUIPath     = QLatin1String("/usr/share/toheink-shareui/qml/shareui.qml");
    info.capabilitities  = capabilities;
    m_infoList.clear();
    m_infoList << info;

    m_ready = true;
    Q_EMIT infoReady();
}

bool ToheinkPluginInfo::ready() const
{
    return m_ready;
}
