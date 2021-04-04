#include "item_reports.h"
#include "ui_item_reports.h"

#include <algorithm>

/****************************************************************
 * item_reports(QWidget* parent = nullptr);
 *   Constructor; Initialize class attributes to null
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *   Return: none
 ***************************************************************/

item_reports::item_reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::item_reports)
{
    ui->setupUi(this);
}

/****************************************************************
 * item_reports(QWidget *parent,
                 sales_container* all_sales,
                 inventory* all_items);
 *   Constructor; Initialize class attributes
 *   Parameters: parent (QWidget*) // IN - pointer to window
                 all_sales (sales_container*) // IN - pointer to
                                              // all sales made
                 all_items (inventory*) // IN - pointer to all
                                        // items in stock
 *   Return: none
 ***************************************************************/

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

/****************************************************************
 * ~item_reports();
 *   Destructor; Frees memory used by the window
 *   Parameters: none
 *   Return: none
 ***************************************************************/

item_reports::~item_reports()
{
    delete ui;
}

/****************************************************************
 * void on_submitButton_clicked();
 *
 *   Accessor; This method will generate a report of all items
 *     or a single items based on user input.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated
 ***************************************************************/

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

/****************************************************************
 * void on_back_clicked();
 *
 *   Accessor; This method will call switchScreen and allow the
 *     user to toggle between input and report.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - screen is changed
 ***************************************************************/

void item_reports::on_back_clicked()
{
    switchScreen();
}

/****************************************************************
 *  void singleItemReport(std::string itemName);
 *
 *   Accessor; This method will generate a report on a single
 *     item, sold and in stock based off of an itemName.
 * --------------------------------------------------------------
 *   Parameters: itemName (std::string) // IN - name of item to
 *                                      //      report
 * --------------------------------------------------------------
 *   Return: none - report on single item is generated
 ***************************************************************/

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
    report += "Item Quantity sold: ";
    report += to_string(quantity).c_str();
    report += "\n";
    report += "Item Quantity in stock: ";
    report += to_string((*all_items)[all_items->search(itemName)].get_quantity()).c_str();
    report += "\n\n";
    report += "Item price: ";
    report += to_string(output[0].getPrice()).c_str();
    report += "\n";
    report += "Total revenue: ";
    report += to_string(price).c_str();
    report += "\n\n";
    report += "-------------End Report-------------";

    ui->report->setText(report);
}

/****************************************************************
 * void allItemReport();
 *
 *   Accessor; This method will generate a report on all items
 *     in the all_items container.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated
 ***************************************************************/

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
        int index = all_items->search(unique_sales[i].getItem());
        output += "Item name: ";
        output += unique_sales[i].getItem().c_str();
        output += "\n";
        output += "Item quantity sold: ";
        output += to_string(unique_sales[i].getQuantity()).c_str();
        output += "\n";
        output += "Item quantity in Stock: ";
        output += to_string((*all_items)[index].get_quantity()).c_str();
        output += "\n\n";
    }
    output += "------------End Report------------";

    ui->report->setText(output);
}

/****************************************************************
 * void switchScreen();
 *
 *   Accessor; This method will switch between the input and
 *     report screens.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - this method will allow the user to switch
 *                  screens
 ***************************************************************/

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

