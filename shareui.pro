TEMPLATE = lib

TARGET = $$qtLibraryTarget(toheinkshareplugin)
target.path = /usr/lib/nemo-transferengine/plugins

qml.path = /usr/share/toheink-shareui/qml
qml.files = qml/shareui.qml \
    qml/notification.png

QT += dbus
CONFIG += plugin link_pkgconfig
PKGCONFIG += nemotransferengine-qt5

HEADERS += \
    toheinktransferiface.h \
    toheinkplugininfo.h \
    toheinkmediatransfer.h \
    converter.h

SOURCES += \
    toheinktransferiface.cpp \
    toheinkplugininfo.cpp \
    toheinkmediatransfer.cpp \
    converter.cpp


OTHER_FILES += rpm/shareui.spec \
    qml/notification.png \
    qml/shareui.qml

INSTALLS += target qml
