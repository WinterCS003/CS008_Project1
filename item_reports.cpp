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

item_reports::item_reports(QWidget *parent, // IN - pointer to window
                           sales_container* all_sales, // IN - pointer to
                                                       // all sales made
                           inventory* all_items): // IN - pointer to all
                                                  // items in stock
    QWidget(parent),
    ui(new Ui::item_reports),
    all_sales(all_sales),
    all_items(all_items)
{
    ui->setupUi(this);
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
    ui->report->clear();
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

void item_reports::singleItemReport(std::string itemName) // IN - name of item to
                                                          //      report
{
    ui->report->clear();
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
    report += "Item price: $";
    double revenue = std::ceil(output[0].getPrice()*100.0)/100.0;
    std::string rev = to_string(revenue);
    rev = rev.substr(0, rev.find(".")+3);
    report += QString::fromStdString(rev);
    report += "\n";
    report += "Total revenue: $";
    revenue = std::ceil(price*100.0)/100.0;
    rev = to_string(revenue);
    rev = rev.substr(0, rev.find(".")+3);
    report += QString::fromStdString(rev);
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
    ui->report->clear();
    // quantity sorted by name
    sales_container unique_sales;
    for(size_t i = 0; i < all_sales->size(); i++)
    {
        int index = unique_sales.find((*all_sales)[i].getItem());
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
        return;
    }

    // alphabetically sort, a .. z
    std::sort(all_items->begin(), all_items->end(), [](const Item& s1, const Item& s2) -> bool{
        return s1.get_item_name() < s2.get_item_name();
    });

    QString output = "---------------Report--------------\n\n";
    int sold = 0;
    for(size_t i = 0; i < all_items->size(); i++)
    {
        int index = unique_sales.find((*all_items)[i].get_item_name());
        index != -1 ? sold = unique_sales[index].getQuantity() : sold = 0;

        output += "Item name: ";
        output += QString::fromStdString((*all_items)[i].get_item_name());
        output += "\n";
        output += "Item quantity sold: ";
        output += QString::fromStdString(to_string(sold));
        output += "\n";
        output += "Item quantity in Stock: ";
        output += QString::fromStdString(to_string((*all_items)[i].get_quantity()));
        output += "\n\n";
    }
    output += "Total Number of Items: ";
    output += QString::fromStdString(to_string((*all_items).size()));
    output += "\n\n";
    output += "------------End Report------------";

    ui->report->setText(output);
}
