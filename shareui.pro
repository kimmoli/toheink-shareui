TEMPLATE = lib

TARGET = $$qtLibraryTarget(toheinkshareplugin)
target.path = /usr/lib/nemo-transferengine/plugins

QT += dbus
CONFIG += plugin link_pkgconfig
PKGCONFIG += nemotransferengine-qt5

HEADERS += \
    toheinktransferiface.h \
    toheinkplugininfo.h \
    toheinkmediatransfer.h

SOURCES += \
    toheinktransferiface.cpp \
    toheinkplugininfo.cpp \
    toheinkmediatransfer.cpp


OTHER_FILES += rpm/shareui.spec

INSTALLS += target
