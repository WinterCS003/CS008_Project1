#include "sales_report.h"
#include "ui_sales_report.h"

sales_report::sales_report(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sales_report)
{
    ui->setupUi(this);
}

sales_report::~sales_report()
{
    delete ui;
}

