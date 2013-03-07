#-------------------------------------------------
#
# Project created by QtCreator 2011-10-31T02:57:00
#
#-------------------------------------------------

QT       += core gui webkit network widgets webkitwidgets

TARGET = IUpdate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    itsbrowser.cpp \
    docinterface.cpp \
    Templates/html_template.cpp \
    logwindow.cpp \
    errordialog.cpp

HEADERS  += mainwindow.h \
    itsbrowser.h \
    docinterface.h \
    Templates/html_template.h \
    logwindow.h \
    DocumentInterface.h \
    errordialog.h

FORMS    += mainwindow.ui \
    logwindow.ui \
    errordialog.ui

RESOURCES += \
    res.qrc

# The application version
VERSION = 13.01

# Define the preprocessor macro to get the application version in our application.
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
