#include "sales_report.h"
#include "ui_sales_report.h"

sales_report::sales_report(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sales_report)
{
    ui->setupUi(this);
    generate_daily_sales_report();
}

sales_report::~sales_report()
{
    delete ui;
}

void sales_report::generate_daily_sales_report()
{
    report_output += "help\n";
    report_output += "I need somebody help!\n";

    ui->output->setText(report_output);
}
