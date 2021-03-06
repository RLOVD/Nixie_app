QT       += core gui
QT += bluetooth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    module_bluetoth/characteristicinfo.cpp \
    module_bluetoth/device.cpp \
    module_bluetoth/deviceinfo.cpp \
    module_bluetoth/serviceinfo.cpp

HEADERS += \
    mainwindow.h \
    module_bluetoth/characteristicinfo.h \
    module_bluetoth/device.h \
    module_bluetoth/deviceinfo.h \
    module_bluetoth/serviceinfo.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Temp_text
