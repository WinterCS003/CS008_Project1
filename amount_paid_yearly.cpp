#include "amount_paid_yearly.h"
#include "ui_amount_paid_yearly.h"

amount_paid_yearly::amount_paid_yearly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::amount_paid_yearly)
{
    ui->setupUi(this);
}

amount_paid_yearly::amount_paid_yearly(QWidget *parent, Members_Container* m)
    : QDialog(parent),
      ui(new Ui::amount_paid_yearly)
{
    ui->setupUi(this);
    ui->title->show();
    ui->basic->show();
    ui->preferred->show();
    ui->submit->show();
    ui->close->show();

    members = m;
}

amount_paid_yearly::~amount_paid_yearly()
{
    delete ui;
}

void amount_paid_yearly::on_submit_clicked()
{
    int flag = 2;
    if(ui->basic->isChecked() && ui->preferred->isChecked())
    {
        flag = 2;
    }
    else if(ui->preferred->isChecked())
    {
        flag = 1;
    }
    else if(ui->basic->isChecked())
    {
        flag = 0;
    }
    else
    {
        flag = 2;
    }

    generate_report(flag);
}

void amount_paid_yearly::on_close_clicked()
{
    amount_paid_yearly::close();
}

void amount_paid_yearly::generate_report(int flag)
{
    Members_Container basic;
    Members_Container prefer;
    Members_Container both;

    // check if no members
    if (members->get_members_count() == 0)
    {
        QMessageBox::warning(this, "Warning: ", "There are no members. ");
        return;
    }

    for (int i=0; i < members->get_members_count(); i++) {
        if (flag == 0) {
            basic.add_member(members[i].get_member(i));
        }
        else if (flag == 1) {
            prefer.add_member(members[i].get_member(i));
        }
        else {
            both.add_member(members[i].get_member(i));
        }
    }

    for (int i=0; i < basic.get_members_count(); i++) {
        // Member name
        report_output += "Member Name: ";
        report_output += basic.get_member(i).get_name().c_str();
        report_output += "\n";

        // member type :
        report_output += "Member Type: basic \n";

        // member amount total
        report_output += "Total amount spent per year: ($)";
        report_output += basic.get_member(i).get_total_spend();
        report_output += "\n\n";
    }

    for (int i=0; i < prefer.get_members_count(); i++) {
        report_output += "Member name: ";
        report_output += prefer.get_member(i).get_name().c_str();
        report_output += "\n";

        report_output += "Member Type: preferred \n";

        report_output += "Total amount spent per year: ($)";
        report_output += prefer.get_member(i).get_total_spend();
        report_output += "\n\n";
    }

    for (int i=0; i < both.get_members_count(); i++) {
        report_output += "Member name: ";
        report_output += both.get_member(i).get_name().c_str();
        report_output += "\n";

        report_output += "Member Type: both \n";

        report_output += "Total amount spent per year: ($)";
        report_output += both.get_member(i).get_total_spend();
        report_output += "\n\n";
    }

    ui->report->show();
    ui->report->setText(report_output);
}


