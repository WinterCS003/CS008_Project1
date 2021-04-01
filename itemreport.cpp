#include "itemreport.h"
#include "ui_itemreport.h"

itemreport::itemreport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemreport)
{
    ui->setupUi(this);
}

itemreport::itemreport(QWidget *parent,
                       sales_container* my_sales) :
    QWidget(parent),
    ui(new Ui::itemreport),
    mySales(my_sales)
{
    ui->setupUi(this);
}

itemreport::~itemreport()
{
    delete ui;
}


