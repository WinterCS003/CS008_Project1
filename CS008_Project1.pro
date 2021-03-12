QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    item.cpp \
    member.cpp \
    sales.cpp \
    sales_container.cpp \
    main.cpp \
    mainwindow.cpp \
    sales_report.cpp

HEADERS += \
    sales.h \
    item.h \
    members.h \
    sales_container.h \
    mainwindow.h \
    sales_report.h

FORMS += \
    mainwindow.ui \
    sales_report.ui

# Default rules for deployment.
# Please Work...
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
