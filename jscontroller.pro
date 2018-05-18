#-------------------------------------------------
#
# Project created by QtCreator 2017-08-15T16:29:10
#
#-------------------------------------------------

QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = jscontroller
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += \
    ../JoystickLibrary/cpp/build/src/libJoystickLibrary.a \
    /usr/lib/x86_64-linux-gnu/libudev.so \
    /usr/lib/x86_64-linux-gnu/libevdev.so

INCLUDEPATH += \
    include \
    JoystickLibrary/cpp/include \
    /usr/include/libevdev-1.0

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mjpegclient.cpp \
    src/joystickclient.cpp

HEADERS += \
    include/mainwindow.h \
    include/mjpegclient.h \
    JoystickLibrary/cpp/include/Enumerator.hpp \
    JoystickLibrary/cpp/include/Extreme3DProService.hpp \
    JoystickLibrary/cpp/include/JoystickService.hpp \
    JoystickLibrary/cpp/include/Types.hpp \
    include/mainwindow.h \
    include/mjpegclient.h \
    include/joystickclient.h

FORMS += \
        mainwindow.ui
