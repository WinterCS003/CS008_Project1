#include "amount_paid_yearly.h"
#include "ui_amount_paid_yearly.h"

/*************************************************************
 * amount_paid_yearly(QWidget *parent = nullptr);
 *      CTOR; initialize class objects to null
 * -----------------------------------------------------------
 *      Parameters: parent (QWidget*) // IN: ptr to window
 * -----------------------------------------------------------
 *      Returns: none
**************************************************************/
amount_paid_yearly::amount_paid_yearly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::amount_paid_yearly)
{
    ui->setupUi(this);
}

/*************************************************************
 * amount_paid_yearly(QWidget *parent = nullptr,
 *                    Members_Container* m);
 *      CTOR; initialize class attributes, hides label/buttons
 * -----------------------------------------------------------
 *      Parameters: parent (QWidget*) // IN: ptr to window
 *                  m (Member_Container*) // IN: ptr to all members
 * -----------------------------------------------------------
 *      Returns: none
**************************************************************/
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

/*************************************************************
 * ~amount_paid_yearly()
 *      destructor; frees memory used by ui (window)
 * -----------------------------------------------------------
 *      Parameters: none
 * -----------------------------------------------------------
 *      Returns: none
**************************************************************/
amount_paid_yearly::~amount_paid_yearly()
{
    delete ui;
}

/****************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will generate a report of all items
 *     or a single items based on member type (basic or preferred)
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated
 ***************************************************************/
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

    if (members->get_members_count() == 0)
    {
        QMessageBox::warning(this, "Warning: ", "There are no members. ");
        return;
    }
    else
    {
        generate_report(flag);
    }

}

/****************************************************************
 * void on_close_clicked();
 *
 *   Accessor; This will close window when close (push button)
 *   is clicked on.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none (return back to main window)
 ***************************************************************/
void amount_paid_yearly::on_close_clicked()
{
    amount_paid_yearly::close();
}

void amount_paid_yearly::generate_report(int flag)
{
    Members_Container basic;
    Members_Container prefer;
    Members_Container both;
    string output = "";

    for (int i=0; i < members->get_members_count(); i++) {
        if (flag == 0) {
            basic.add_member(members[i].get_member(i));
        }
        if (flag == 1) {
            prefer.add_member(members[i].get_member(i));
        }
        if (flag == 2) {
            both.add_member(members[i].get_member(i));
        }
    }

    if (flag == 0) {
        for (int i=0; i < basic.get_members_count(); i++) {
            // Member name
            output += "Member Name: ";
            output += basic.get_member(i).get_name().c_str();
            output += "\n";

            // member type :
            output += "Member Type: basic \n";

            // member amount total
            output += "Total amount spent per year: ($)";
            output += basic.get_member(i).get_total_spend();
            output += "\n\n";
        }

    }

    else if (flag == 1) {
        for (int i=0; i < prefer.get_members_count(); i++) {
            output += "Member name: ";
            output += prefer.get_member(i).get_name().c_str();
            output += "\n";

            output += "Member Type: preferred \n";

            output += "Total amount spent per year: ($)";
            output += prefer.get_member(i).get_total_spend();
            output += "\n\n";
        }

    }

    else {
        for (int i=0; i < both.get_members_count(); i++) {
            output += "Member name: ";
            output += both.get_member(i).get_name().c_str();
            output += "\n";

            output += "Member Type: both \n";

            output += "Total amount spent per year: ($)";
            output += both.get_member(i).get_total_spend();
            output += "\n\n";
        }

    }
    report_output = QString::fromStdString(output);
    ui->report->setText(report_output);
    ui->report->show();
}


