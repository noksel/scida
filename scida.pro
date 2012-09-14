#-------------------------------------------------
#
# Project created by QtCreator 2012-07-29T17:06:24
#
#-------------------------------------------------

QT       += core gui

TARGET = scida
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    grphset.cpp \
    channel.cpp \
    channely.cpp \
    channelx.cpp \
    rndchx.cpp \
    rndchy.cpp \
    device.cpp \
    rnddev.cpp \
    rndsettingswindow.cpp \
    createmeasurement.cpp \
    measurement.cpp \
    msrmntwindow.cpp

HEADERS  += mainwindow.h \
    grphset.h \
    channel.h \
    channely.h \
    channelx.h \
    rndchx.h \
    rndchy.h \
    device.h \
    rnddev.h \
    rndsettingswindow.h \
    createmeasurement.h \
    measurement.h \
    msrmntwindow.h

FORMS    += mainwindow.ui \
    grphset.ui \
    rndsettingswindow.ui \
    createmeasurement.ui \
    msrmntwindow.ui

RESOURCES += \
    res.qrc
win32{
INCLUDEPATH += C:/KDAB/KDChart-2.4.3w7din/include
INCLUDEPATH +=C:/KDAB/KDChart 2.4.3 Source/include
LIBS += -LC:/KDAB/KDChart-2.4.3w7din/lib -lkdchartd2 -ltesttools

}
