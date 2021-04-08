#include "amount_paid_yearly.h"
#include "ui_amount_paid_yearly.h"

/****************************************************************
 * amount_paid_yearly(QWidget *parent = nullptr);
 *   Constructor; Initialize class attributes to null
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *   Return: none
 ***************************************************************/
amount_paid_yearly::amount_paid_yearly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::amount_paid_yearly)
{
    ui->setupUi(this);
}

/****************************************************************
 * amount_paid_yearly(QWidget* parent,
 *                    Members_Container* m,
 *                    sales_container* sc);
 *   Constructor; Initializes attributes with parameters
 *   Parameters: QWidget* parent, // IN - pointer to widget window
 *               Members_Container* m // IN - pointer to members container
 *               sales_container* sc // IN - pointer to sales container
 *   Return: none
 ***************************************************************/
amount_paid_yearly::amount_paid_yearly(QWidget *parent,
                                       Members_Container* m,
                                       sales_container* sc)
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
    all_sales = sc;
}

/****************************************************************
 * ~amount_paid_yearly();
 *   Destructor; deletes ui pointer
 *   Parameters: none
 *   Return: none
 ***************************************************************/
amount_paid_yearly::~amount_paid_yearly()
{
    delete ui;
}

/****************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will determine the flag and
 *   call generate_report.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - generate_report is called
 ***************************************************************/
void amount_paid_yearly::on_submit_clicked()
{
    ui->report->clear();

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

/****************************************************************
 * void on_close_clicked();
 *
 *   Accessor; This method will close the window
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
void amount_paid_yearly::on_close_clicked()
{
    amount_paid_yearly::close();
}

/****************************************************************
 * void generate_report(int flag);
 *
 *   Accessor; This method will create a report for basic
 *   preferred or both members based on user input
 * --------------------------------------------------------------
 *   Parameters: flag (int) // IN - user specified value for
 *                                  member type to print
 * --------------------------------------------------------------
 *   Return: none - report is output to screen
 ***************************************************************/
void amount_paid_yearly::generate_report(int flag)
{
    ui->report->clear();
    Members_Container all;

    for (int i=0; i < members->get_members_count(); i++) {
        if (flag == 0) {
            // basic members only
            if(!(*members)[i].is_premium_member())
                all.add_member((*members)[i]);
        }
        else if (flag == 1) {
            // premium members only
            if((*members)[i].is_premium_member())
                all.add_member((*members)[i]);
        }
        else {
            all.add_member((*members)[i]);
        }
    }

    // check if no members
    if (all.get_members_count() == 0)
    {
        QMessageBox::warning(this, "Warning: ", "There are no members.");
        return;
    }

    for(int i = 0; i < all.get_members_count(); i++)
    {
        for(int j = 0; j < all_sales->size(); j++)
        {
            if((*all_sales)[j].getId() == all[i].get_membership_number())
            {
               double total = (*all_sales)[j].getQuantity()*(*all_sales)[j].getPrice();
               all[i].add_total(total);
            }
        }
    }

    for (int i=0; i < all.get_members_count(); i++) {
        // Member name
        report_output += "Member Name: ";
        report_output += all[i].get_name().c_str();
        report_output += "\n";

        // member type :
        report_output += "Member Type: ";
        all[i].is_premium_member() ? report_output += "Premium\n" : report_output += "Basic\n";

        // member amount total
        report_output += "Total amount spent per year: ($)";
        double spent = all[i].get_total_spend();
        spent = std::ceil(spent*100.0)/100.0;
        std::string s = to_string(spent);
        s = s.substr(0, s.find(".")+3);
        report_output += QString::fromStdString(s);
        report_output += "\n\n";
    }

    ui->report->show();
    ui->report->setText(report_output);
}


