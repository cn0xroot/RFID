#-------------------------------------------------
#
# Project created by QtCreator 2012-10-13T11:53:20
#
#-------------------------------------------------

QT       += core gui

TARGET = USBReader
TEMPLATE = app


SOURCES += main.cpp \
    usbreaderdemo.cpp

HEADERS  += \
    function.h \
    usbreaderdemo.h

FORMS    += \
    usbreaderdemo.ui

RESOURCES += \
    usbreaderdemo.qrc

unix:!macx:!symbian: LIBS += -L$$PWD/ ./libfunction.so

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
