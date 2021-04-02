#include "memberpurchase.h"
#include "ui_memberpurchase.h"
#include <algorithm>

memberPurchase::memberPurchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memberPurchase)
{
    ui->setupUi(this);
}

memberPurchase::memberPurchase(QWidget *parent,
                               sales_container* sc,
                               Members_Container* mc,
                               inventory* iv):
    QWidget(parent),
    ui(new Ui::memberPurchase),
    all_sales(sc),
    all_members(mc),
    all_items(iv)
{
    ui->setupUi(this);

    ui->report->hide();
    ui->back->hide();
}

memberPurchase::~memberPurchase()
{
    delete ui;
}

void memberPurchase::on_back_clicked()
{
    switchScreen();
}

void memberPurchase::on_submit_clicked()
{
    switchScreen();
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
                switchScreen();
                return;
            }
            for(size_t i = 0; i < all_sales->size(); i++)
            {
                Member m1 = all_members->get_member((*all_sales)[i].getId());
                if(m1.get_name() == name){
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
            switchScreen();
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
        report += to_string(output.getTotalRevenue()).c_str();
        report += "\n\n";
        report += "-----------End report---------";
        ui->report->setText(report);
    }
}

void memberPurchase::allMemberReport()
{
    sales_container output;
    output = *all_sales;

    std::sort(output.begin(), output.end(), [](const sales& s1, const sales& s2)->bool{
        return s1.getId() > s2.getId();
    });

    double total = 0.0;
    QString report;
    report += "---------Begin Report---------\n\n";
    report += "Member: ";
    report += "\n";
    report += "ID: ";
    report += to_string(output[0].getId()).c_str();
    report += "\n\n";
    report += all_members->get_member(output[0].getId()).get_name().c_str();
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
    total += output[0].getRevenue();
    for(int i = 1; i < output.size(); i++)
    {
        if(output[i-1].getId() != output[i].getId())
        {
            report += "Total purchases of member: $";
            report += to_string(total).c_str();
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
        total += output[i].getRevenue();
    }
    report += "Total purchases of member: $";
    report += to_string(total).c_str();
    report += "\n\n";
    report += "Grand total of all purchases: $";
    report += to_string(output.getTotalRevenue()).c_str();
    report += "\n\n---------End Report---------";

    ui->report->setText(report);
}
void memberPurchase::switchScreen()
{
    // on report screen
    if(ui->submit->isHidden())
    {
        ui->report->hide();
        ui->back->hide();
        ui->nameInput->clear();
        ui->nameLabel->show();
        ui->nameInput->show();
        ui->idLabel->show();
        ui->id->show();
        ui->id->clear();
        ui->allMembers->show();
        ui->submit->show();
    }
    else
    {
        ui->report->clear();
        ui->report->show();
        ui->back->show();
        ui->nameLabel->hide();
        ui->nameInput->hide();
        ui->idLabel->hide();
        ui->id->hide();
        ui->allMembers->hide();
        ui->submit->hide();
    }
}
