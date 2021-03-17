#include "sales_report.h"
#include "ui_sales_report.h"

sales_report::sales_report(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sales_report)
{
    ui->setupUi(this);
    ui->output->hide();
}

sales_report::sales_report(QWidget *parent, const sales_container& sc)
    : QMainWindow(parent)
    , ui(new Ui::sales_report)
{
    ui->setupUi(this);
    ui->output->hide();

    report = sc;
}

sales_report::~sales_report()
{
    delete ui;
}

void sales_report::generate_daily_sales_report(std::string date)
{
    report_output = report_output.fromStdString(("Date: " + date + "\n"));

    for(size_t i = 0; i < report.size(); i++)
    {
        if(date == report[i].getDate())
        {
            //report_output += report[i];
        }
    }

    ui->output->show();
    ui->output->setText(report_output);
}

void sales_report::error()
{
    ui->output->setText("No sales made");
}

void sales_report::on_submit_clicked()
{
    ui->date->hide();
    ui->dateEdit->hide();
    ui->member_type->hide();
    ui->submit->hide();

    QDate date = ui->dateEdit->date();
    QString sDate = date.toString("MMddyyyy");
    std::string sdDate = sDate.toStdString();
    bool preferred = false;

    if(ui->member_type->isChecked())
    {
        preferred = true;
    }

    generate_daily_sales_report(sdDate);
}
