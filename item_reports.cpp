#include "item_reports.h"
#include "ui_item_reports.h"

item_reports::item_reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::item_reports)
{
    ui->setupUi(this);
}

item_reports::~item_reports()
{
    delete ui;
}
