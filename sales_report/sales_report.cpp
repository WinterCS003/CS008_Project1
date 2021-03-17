#include "sales_report.h"
#include "ui_sales_report.h"

sales_report::sales_report(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::sales_report)
{
    ui->setupUi(this);
    ui->output->hide();
    ui->back->hide();
}

sales_report::sales_report(QWidget *parent, const sales_container& sc)
    : QMainWindow(parent)
    , ui(new Ui::sales_report)
{
    ui->setupUi(this);
    ui->output->hide();
    ui->output->backward();
    ui->back->hide();

    report = sc;
}

sales_report::~sales_report()
{
    delete ui;
}

void sales_report::on_submit_clicked()
{
    switchScreen();

    QDate date = ui->dateEdit->date();
    QString sDate = date.toString("MM/dd/yyyy");
    std::string sdDate = sDate.toStdString();
    bool preferred = false;

    if(ui->member_type->isChecked())
    {
        preferred = true;
    }

    generate_daily_sales_report(sdDate);
}

void sales_report::switchScreen()
{
    if(ui->output->isHidden())
    {
        ui->date->hide();
        ui->dateEdit->hide();
        ui->member_type->hide();
        ui->submit->hide();
        ui->output->show();
        ui->back->show();
    }
    else
    {
        ui->output->hide();
        ui->date->show();
        ui->dateEdit->show();
        ui->member_type->show();
        ui->submit->show();
        ui->back->hide();
    }
}

void sales_report::generate_daily_sales_report(std::string date)
{
    report_output = report_output.fromStdString(("Date: " + date + "\n"));

    for(size_t i = 0; i < report.size(); i++)
    {
        if(date == report[i].getDate())
        {
            report_output += "Item Name: ";
            report_output += report[i].getItem().c_str();
            report_output += "\n";
        }
    }

    // if no entries for given date are found
    if(report_output.size() == 17.0)
    {
        report_output += "No sales made\n";
    }

    ui->output->show();
    ui->output->setText(report_output);
}

void sales_report::on_back_clicked()
{
    switchScreen();
}
