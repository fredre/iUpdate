#-------------------------------------------------
#
# Project created by QtCreator 2012-09-11T10:28:26
#
#-------------------------------------------------

QT       += core testlib

QT       -= gui

TARGET = UnitTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    testdocinterfacecsv.cpp\
    ../../../docinterface.cpp

HEADERS += \
    testdocinterfacecsv.h\
    ../../../docinterface.h
