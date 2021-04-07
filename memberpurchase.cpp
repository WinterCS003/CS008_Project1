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
        allMemberReport(0);
    }
    else if(ui->basicOnly->isChecked())
    {
        allMemberReport(1);
    }
    else if(ui->preferredOnly->isChecked())
    {
        allMemberReport(2);
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

void memberPurchase::allMemberReport(int flag)
{
    ui->report->clear();

    if(all_sales->size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No sales");
        return;
    }

    Members_Container mc;
    for(int i = 0; i < all_members->get_members_count(); i++)
    {
        if(flag == 1)
        {
            if(!(*all_members)[i].is_premium_member())
            {
                mc.add_member((*all_members)[i]);
            }
        }
        else if(flag == 2)
        {
            if((*all_members)[i].is_premium_member())
            {
                mc.add_member((*all_members)[i]);
            }
        }
        else
        {
            mc.add_member((*all_members)[i]);
        }
    }

    for(int i = 0; i < mc.get_members_count(); i++)
    {
        for(int j = 0; j < all_sales->size(); j++)
        {
            if((*all_sales)[j].getId() == mc[i].get_membership_number())
            {
                double total = (*all_sales)[j].getQuantity()*(*all_sales)[j].getPrice();
                mc[i].add_total(total);
            }
        }
    }

    if(mc.get_members_count() == 0)
    {
        QMessageBox::warning(this, "Warning", "No Members");
        return;
    }

    std::sort(all_members->begin(), all_members->end(), [](const Member& m1, const Member& m2)->bool{
        return m1.get_membership_number() < m2.get_membership_number();
    });

    double total = 0.0;
    double grandTotal = 0.0;
    std::string sTotal;
    QString report;
    report += "---------Begin Report---------\n\n";
    for(int i = 0; i < mc.get_members_count(); i++)
    {
        report += "Member: ";
        report += QString::fromStdString(mc[i].get_name());
        report += "\n";
        report += "Total Purchase amount: $";
        total = mc[i].get_total_spend();
        grandTotal += total;
        total = std::ceil(total*100.0)/100.0;
        sTotal = to_string(total);
        sTotal = sTotal.substr(0, sTotal.find(".")+3);
        report += QString::fromStdString(sTotal);
        report += "\n\n";
    }
    report += "Grand Total of Purchases: $";
    grandTotal = std::ceil(grandTotal*100.0)/100.0;
    sTotal = to_string(grandTotal);
    sTotal = sTotal.substr(0, sTotal.find(".")+3);
    report += QString::fromStdString(sTotal);
    report += "\n\n---------End Report---------";

    ui->report->setText(report);
}
