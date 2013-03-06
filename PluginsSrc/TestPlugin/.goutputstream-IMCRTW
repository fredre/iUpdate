#-------------------------------------------------
#
# Project created by QtCreator 2012-07-18T20:59:37
#
#-------------------------------------------------

QT       -= gui

TARGET = TestPlugin
TEMPLATE = lib

DEFINES += TESTPLUGIN_LIBRARY

SOURCES += testplugin.cpp

HEADERS += testplugin.h\
        TestPlugin_global.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEE6DBE61
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = TestPlugin.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
