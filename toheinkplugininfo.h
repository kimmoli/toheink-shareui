#ifndef TOHEINKPLUGININFO_H
#define TOHEINKPLUGININFO_H

#include <TransferEngine-qt5/transferplugininfo.h>
#include <TransferEngine-qt5/transfermethodinfo.h>

class ToheinkPluginInfo : public TransferPluginInfo
{
    Q_OBJECT
public:
    ToheinkPluginInfo();
    ~ToheinkPluginInfo();
    QList<TransferMethodInfo> info() const;
    void query();
    bool ready() const;

private:
    QList<TransferMethodInfo> m_infoList;
    bool m_ready;

};

#endif // TOHEINKPLUGININFO_H
