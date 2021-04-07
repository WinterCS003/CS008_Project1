#include "memberpurchase.h"
#include "ui_memberpurchase.h"
#include <algorithm>

/****************************************************************
 * memberPurchase(QWidget *parent = nullptr);
 *   Constructor; Null initializes class attributes
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *   Return: none
 ***************************************************************/

memberPurchase::memberPurchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memberPurchase)
{
    ui->setupUi(this);
}

/****************************************************************
 * memberPurchase(QWidget* parent,
                   sales_container* sc,
                   Members_Container* mc,
                   inventory* iv);
 *   Constructor; Initialize class attributes
 *   Parameters: parent (QWidget*) // IN  - pointer to window
                   sc (sales_container*) // IN - pointer to all sales made
                   mc (Members_Container*) // IN - ponter to all members
                   iv (inventory*) // IN - pointer to all items in stock
 *   Return: none
 ***************************************************************/

memberPurchase::memberPurchase(QWidget *parent, // IN  - pointer to window
                               sales_container* sc, // IN - pointer to all sales made
                               Members_Container* mc, // IN - ponter to all members
                               inventory* iv): // IN - pointer to all items in stock
    QWidget(parent),
    ui(new Ui::memberPurchase),
    all_sales(sc),
    all_members(mc),
    all_items(iv)
{
    ui->setupUi(this);
}

/****************************************************************
 * ~memberPurchase();
 *   Destructor; Frees memory used by the window
 *   Parameters: none
 *   Return: none
 ***************************************************************/

memberPurchase::~memberPurchase()
{
    delete ui;
}

/****************************************************************
 * void singleMemberReport(int id);
 *
 *   Accessor; This method will generate a report of all sales
 *     made by a single member based on their id number.
 * --------------------------------------------------------------
 *   Parameters: id (int) // IN - id number of member
 * --------------------------------------------------------------
 *   Return: none - report on a single user is generated
 ***************************************************************/

void memberPurchase::on_submit_clicked()
{
    ui->report->clear();
    if(ui->allMembers->isChecked())
    {
        allMemberReport();
    }
    else
    {
        std::string name = ui->nameInput->text().toStdString();
        int id = ui->id->value();
        sales_container output;
        if(name.length() == 0)
        {
            if(!all_members->contains(id))
            {
                QMessageBox::warning(this, "Warning", "Member not found");
                return;
            }
            for(size_t i = 0; i < all_sales->size(); i++)
            {
                Member m1 = all_members->get_member((*all_sales)[i].getId());
                if(m1.get_membership_number() == id){
                    output.push_back((*all_sales)[i]);
                }
            }
        }
        else
        {
            if(!all_members->contains(name))
            {
                QMessageBox::warning(this, "Warning", "Member not found");
                return;
            }
            for(int i = 0; i < all_sales->size(); i++)
            {
                Member m1 = all_members->get_member((*all_sales)[i].getId());
                if(m1.get_name() == name)
                {
                    output.push_back((*all_sales)[i]);
                }
            }
        }

        if(output.size() == 0)
        {
            QMessageBox::warning(this, "Warning", "No sales made by member");
            return;
        }

        QString report = "--------------";
        report += name.c_str();
        report += "--------------\n\n";
        for(int i = 0; i < output.size(); i++)
        {
            report += "Date: ";
            report += output[i].getDate().c_str();
            report += "\n";
            report += "Item name: ";
            report += output[i].getItem().c_str();
            report += "\n";
            report += "Item quantity: ";
            report += to_string(output[i].getQuantity()).c_str();
            report += "\n\n";
        }
        report += "Total amount spent $";
        double revenue = std::ceil((output.getTotalRevenue()/1.875)*100.0)/100.0;
        std::string rev = to_string(revenue);
        rev = rev.substr(0, rev.find(".")+3);
        report += QString::fromStdString(rev);
        report += "\n\n";
        report += "-----------End report---------";
        ui->report->setText(report);
    }
}

/****************************************************************
 * void allMemberReport();
 *
 *   Accessor; This method will generate a report of all
 *     sales made by every member in the all_members container.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated for all members
 ***************************************************************/

void memberPurchase::allMemberReport()
{
    ui->report->clear();
    sales_container output;
    output = *all_sales;

    if(output.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No sales");
        return;
    }

    std::sort(output.begin(), output.end(), [](const sales& s1, const sales& s2)->bool{
        return s1.getId() < s2.getId();
    });

    double total = 0.0;
    QString report;
    report += "---------Begin Report---------\n\n";
    report += "Member: ";
    report += all_members->get_member(output[0].getId()).get_name().c_str();
    report += "\n";
    report += "ID: ";
    report += to_string(output[0].getId()).c_str();
    report += "\n";
    report += "Date: ";
    report += output[0].getDate().c_str();
    report += "\n";
    report += "Item name: ";
    report += output[0].getItem().c_str();
    report += "\n";
    report += "Item quantity: ";
    report += to_string(output[0].getQuantity()).c_str();
    report += "\n\n";
    total += output[0].getPrice()*output[0].getQuantity();
    for(int i = 1; i < output.size(); i++)
    {
        if(output[i-1].getId() != output[i].getId())
        {
            total = std::ceil(total*100.0)/100.0;
            report += "Total purchases of member: $";
            std::string revenue = to_string(total);
            revenue = revenue.substr(0, revenue.find(".")+3);
            report += QString::fromStdString(revenue);
            total = 0.0;
            report += "\n\nMember: ";
            report += all_members->get_member(output[i].getId()).get_name().c_str();
            report += "\n";
            report += "ID: ";
            report += to_string(output[i].getId()).c_str();
            report += "\n\n";
        }
        report += "Date: ";
        report += output[i].getDate().c_str();
        report += "\n";
        report += "Item name: ";
        report += output[i].getItem().c_str();
        report += "\n";
        report += "Item quantity: ";
        report += to_string(output[i].getQuantity()).c_str();
        report += "\n\n";
        total += output[i].getPrice()*output[i].getQuantity();
    }
    report += "Total purchases of member: $";
    std::string revenue = to_string(total);
    revenue = revenue.substr(0, revenue.find(".")+3);
    report += QString::fromStdString(revenue);
    report += "\n\n";
    report += "Grand total of all purchases: $";
    double rev = std::ceil((output.getTotalRevenue()/1.875)*100.0)/100.0;
    revenue = to_string(rev);
    revenue = revenue.substr(0, revenue.find(".")+3);
    report += QString::fromStdString(revenue);
    report += "\n\n---------End Report---------";

    ui->report->setText(report);
}
