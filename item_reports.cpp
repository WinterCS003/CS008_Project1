#include "item_reports.h"
#include "ui_item_reports.h"

#include <algorithm>

item_reports::item_reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::item_reports)
{
    ui->setupUi(this);
}

item_reports::item_reports(QWidget *parent,
                           sales_container* all_sales,
                           inventory* all_items):
    QWidget(parent),
    ui(new Ui::item_reports),
    all_sales(all_sales),
    all_items(all_items)
{
    ui->setupUi(this);

    ui->report->hide();
    ui->back->hide();
}

item_reports::~item_reports()
{
    delete ui;
}

void item_reports::on_submitButton_clicked()
{
    switchScreen();
    if(ui->allItems->isChecked())
    {
        allItemReport();
    }
    else
    {
        std::string itemName = ui->nameInput->text().toStdString();

        if(!all_items->contains(itemName))
        {
            QMessageBox::warning(this, "Warning", "Item not found");
            return;
        }

        singleItemReport(itemName);
    }
}

void item_reports::singleItemReport(std::string itemName)
{
    sales_container output;
    for(size_t i = 0; i < all_sales->size(); i++)
    {
        if(itemName == (*all_sales)[i].getItem())
        {
            output.push_back((*all_sales)[i]);
        }
    }

    if(output.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No sales made for item");
        return;
    }

    int quantity = 0;
    double price = output.getTotalRevenue();
    for(size_t i = 0; i < output.size(); i++)
    {
        quantity += output[i].getQuantity();
    }

    QString report;
    report += "---------------Report---------------\n\n";
    report += "Item Name: ";
    report += itemName.c_str();
    report += "\n";
    report += "Item Quantity: ";
    report += to_string(quantity).c_str();
    report += "\n\n";
    report += "Item price: ";
    report += to_string(output[0].getPrice()).c_str();
    report += "\n";
    report += "Total price: ";
    report += to_string(price).c_str();
    report += "\n\n";
    report += "-------------End Report-------------";

    ui->report->setText(report);
}

void item_reports::allItemReport()
{
    // quantity sorted by name
    sales_container unique_sales;
    for(size_t i = 0; i < all_sales->size(); i++)
    {
        int index = unique_sales.find((*all_sales)[i]);
        if(index == -1)
        {
            unique_sales.push_back((*all_sales)[i]);
        }
        else
        {
            int s1 = unique_sales[index].getQuantity();
            int s2 = (*all_sales)[i].getQuantity();
            unique_sales[index].setQuantity(s1 + s2);
        }
    }

    if(unique_sales.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No sales made for item");
        switchScreen();
        return;
    }

    // alphabetically sort, a .. z
    std::sort(unique_sales.begin(), unique_sales.end(), [](const sales& s1, const sales& s2) -> bool{
        return s1.getItem() < s2.getItem();
    });

    QString output = "---------------Report--------------\n\n";
    for(size_t i = 0; i < unique_sales.size(); i++)
    {
        output += "Item name: ";
        output += unique_sales[i].getItem().c_str();
        output += "Item quantity: ";
        output += to_string(unique_sales[i].getQuantity()).c_str();
        output += "\n";
    }
    output += "\n\n------------End Report------------";

    ui->report->setText(output);
}

void item_reports::switchScreen()
{
    // input screen
    if(ui->report->isHidden())
    {
        ui->report->clear();
        ui->nameInput->hide();
        ui->nameLabel->hide();
        ui->allItems->hide();
        ui->submitButton->hide();
        ui->report->show();
        ui->back->show();
    }
    else
    {
        ui->nameInput->clear();
        ui->nameInput->show();
        ui->nameLabel->show();
        ui->allItems->show();
        ui->submitButton->show();
        ui->report->hide();
        ui->back->hide();
    }
}

void item_reports::on_back_clicked()
{
    switchScreen();
}
