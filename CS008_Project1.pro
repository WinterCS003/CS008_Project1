QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    # sales classes
    item_reports.cpp \
    itemreport.cpp \
    managemembers.cpp \
    sales/sales.cpp \
    sales/sales_container.cpp \
    # item classes
    item.cpp \
    inventory.cpp \
    # member classes
    member.cpp \
    members_container.cpp \
    # forms
    main.cpp \
    mainwindow.cpp \
    make_sale/make_sale.cpp \
    sales_report/daily_sales.cpp \
    inventorytracker.cpp \
    sales_report/yearly_sales.cpp

HEADERS += \
    item_reports.h \
    itemreport.h \
    managemembers.h \
    sales_report/daily_sales.h \
    sales_report/yearly_sales.h \
    vector.h \
    # sales classes
    sales/sales.h \
    sales/sales_container.h \
    # item classes
    item.h \
    inventory.h \
    # member classes
    member.h \
    members_container.h \
    #forms
    mainwindow.h \
    make_sale/make_sale.h \
    inventorytracker.h

FORMS += \
    item_reports.ui \
    itemreport.ui \
    mainwindow.ui \
    inventorytracker.ui \
    make_sale/make_sale.ui \
    managemembers.ui \
    sales_report/daily_sales.ui \
    sales_report/yearly_sales.ui

# Default rules for deployment.
# Please Work...
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
