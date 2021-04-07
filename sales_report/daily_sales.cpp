#include "daily_sales.h"
#include "ui_daily_sales.h"

/****************************************************************
 * daily_sales(QWidget* parent = nullptr);
 *   Constructor; create a new window
 *   Parameters: parent (QWidget*) // IN - pointer to widget
 *   Return: none
 ***************************************************************/
daily_sales::daily_sales(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::daily_sales)
{
    ui->setupUi(this);
}

/****************************************************************
 *   daily_sales(QWidget *parent,
 *               sales_container* sc,
 *               Members_Container* mc);
 *   Constructor; create a new window and initializes all member
 *                attributes to the parameters.
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *               sc (sales_container*) // IN - all sales made
 *               mc (Members_Container*) // IN - container of members
 *   Return: none
 ***************************************************************/
daily_sales::daily_sales(QWidget *parent, sales_container* sc, Members_Container* mc)
    : QWidget(parent)
    , ui(new Ui::daily_sales)
{
    ui->setupUi(this);

    report = sc;
    members = mc;
}

/****************************************************************
 * ~daily_sales();
 *   Destructor; Frees memory used by the ui pointer
 *   Parameters: none
 *   Return: none
 ***************************************************************/
daily_sales::~daily_sales()
{
    delete ui;
}

/****************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will submit input from the user to
 *             generate a report. generate_daily_daily_sales is
 *             called
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
void daily_sales::on_submit_clicked()
{
    ui->report->clear();
    QDate date = ui->dateEdit->date();
    QString sDate = date.toString("MM/dd/yyyy");
    std::string sdDate = sDate.toStdString();

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
    generate_daily_daily_sales(sdDate, flag);
}

/****************************************************************
 * void generate_daily_daily_sales(std::string date,
 *                                 int flag);
 *
 *   Accessor; This method will create a report of all sales
 *             made on the date. User can specify a flag to
 *             toggle between member types
 * --------------------------------------------------------------
 *   Parameters: date (std::string) // IN - date of sales to find
 *               flag (int) // IN - member type
 *                          // 0 = basic
 *                          // 1 = preferrred
 *                          // 2 = both
 * --------------------------------------------------------------
 *   Return: none - report is output to the screen
 ***************************************************************/
void daily_sales::generate_daily_daily_sales(std::string date, int flag)
{
    ui->report->clear();
    report_output = report_output.fromStdString(("----------Date: " + date + "----------\n\n"));
    sales_container dailySale;

    // first pass - finds all sales made on the given date
    for(size_t i = 0; i < report->size(); i++)
    {
        if(date == (*report)[i].getDate())
        {
            int index = members->get_member_index((*report)[i].getId());
            if(flag == 0) // only basic members
            {
                if(!(*members)[index].is_premium_member())
                {
                    dailySale.push_back((*report)[i]);
                }
            }
            else if(flag == 1) // only preferred members
            {
                if((*members)[index].is_premium_member())
                {
                    dailySale.push_back((*report)[i]);
                }
            }
            else // both members
            {
                dailySale.push_back((*report)[i]);
            }
        }
    }
    // check if no sales were made on the date
    if(dailySale.size() == 0)
    {
        QString warning = date.c_str();
        QMessageBox::warning(this, "Warning", "No sales made on: " + warning);
        return;
    }

    // only one copy of each item
    sales_container unique_sales;
    for(size_t i = 0; i < dailySale.size(); i++)
    {
        int index = unique_sales.find(dailySale[i].getItem());
        if( index == -1)
        {
            unique_sales.push_back(dailySale[i]);
        }
        else
        {
            sales s1 = dailySale[i];
            sales* s2 = &unique_sales[index];

            s2->setQuantity(s1.getQuantity() + s2->getQuantity());
        }
    }

    // second pass - make report of all items sold
    for(size_t i = 0; i < unique_sales.size(); i++)
    {
        // Item name
        report_output += "Item Name: ";
        report_output += unique_sales[i].getItem().c_str();
        report_output += "\n";

        // Item Quantity
        report_output += "Item Quantity: ";
        report_output += to_string(unique_sales.getItemQuantity(unique_sales[i].getItem())).c_str();
        report_output += "\n\n";
    }
    // total revenue of all sales on the given date
    report_output += "Total Revenue: $";
    double revenue = std::ceil(unique_sales.getTotalRevenue()*100.0)/100.0;
    std::string rev = to_string(revenue);
    rev = rev.substr(0, rev.find(".")+3);
    report_output += QString::fromStdString(rev);
    report_output += "\n\n";

    report_output += "List of Members:\n";
    Member temp;
    QString memberName;
    int countPremium = 0;
    int countBasic = 0;
    // Members who shopped
    for(unsigned int i = 0; i < dailySale.size(); i++)
    {
        int index = members->get_member_index(dailySale[i].getId());
        temp = (*members)[index];
        memberName = temp.get_name().c_str();
        if(!report_output.contains(memberName))
        {
            if(temp.is_premium_member())
            {
                countPremium++;
            }
            else
            {
                countBasic++;
            }
            report_output += memberName;
            report_output += "\n";
        }
    }
    // number of basic members
    report_output += "Number of Basic Members: ";
    report_output += to_string(countBasic).c_str();
    report_output += "\n";
    // number of preferred members
    report_output += "Number of Premium Members: ";
    report_output += to_string(countPremium).c_str();
    report_output += "\n\n";
    report_output += "----------End of report----------";

    ui->report->show();
    ui->report->setText(report_output);
}
