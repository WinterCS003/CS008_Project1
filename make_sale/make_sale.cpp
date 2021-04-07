#include "make_sale.h"
#include "ui_make_sale.h"

#include "sales/sales.h"
#include <fstream>

/**********************************************************
 *
 * CONSTRUCTOR make_sale
 *_________________________________________________________
 * This constructor receives a QWidget pointer and creates
 *   a new window.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     parent: QWidget*
 *
 * POST-CONDITIONS
 *   This function will create a new window.
 ***********************************************************/
make_sale::make_sale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::make_sale)
{
    ui->setupUi(this);
}

/**********************************************************
 *
 * CONSTRUCTOR make_sale
 *_________________________________________________________
 * This function receives QWidget, sales_container,
 *   Members_Container, and inventory as pointers. A new
 *   window is created with attributes initialized to the
 *   parameters.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     parent (QWidget *) // IN - pointer to the window
 *     sales_container* sc // IN - pointer to a sales_container
 *     Members_Container* mc // IN - pointer to a members container
 *     inventory* i // IN - pointer to an inventory
 *
 * POST-CONDITIONS
 *   This function will initialize all member attributes to the
 *     parameter
 ***********************************************************/
make_sale::make_sale(QWidget *parent, // IN - pointer to the window
                     sales_container* sc, // IN - pointer to a sales_container
                     Members_Container* mc, // IN - pointer to a members container
                     inventory* i) // IN - pointer to an inventory
    : QMainWindow(parent)
    , ui(new Ui::make_sale)
    , all_sales(sc)
    , all_members(mc)
    , my_inventory(i)
{
    ui->setupUi(this);
}

/****************************************************************
 * ~make_sale();
 *   Destructor; Frees memory used by ui.
 *   Parameters: none
 *   Return: none
 ***************************************************************/
make_sale::~make_sale()
{
    delete ui;
}

/****************************************************************
 * void printReport();
 *
 *   Accessor; This method will print a report of all sales made
 *             mainly for debugging purposes
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - output to widget
 ***************************************************************/
void make_sale::printReport()
{
    QString report;
    report += to_string((*all_sales).size()).c_str();
    report += " Total Sales\n";
    for(unsigned int i = 0; i < (*all_sales).size(); i++)
    {
        report += (*all_sales)[i].getDate().c_str();
        report += "\n";
        report += to_string((*all_sales)[i].getId()).c_str();
        report += "\n";
        report += (*all_sales)[i].getItem().c_str();
        report += "\n";
        report += to_string((*all_sales)[i].getPrice()).c_str();
        report += "\n";
        report += to_string((*all_sales)[i].getQuantity()).c_str();
        report += "\n\n";
    }
    ui->textBrowser->setText(report);
}

/*******************************************************************
 * void on_fileInput_clicked();
 *
 *   Mutator; This method will pop up a new window for user to
 *            chose a file to read sales from
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none - all_sales attribute is updated
 *******************************************************************/
void make_sale::on_fileInput_clicked()
{
    ui->textBrowser->clear();
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    if(!all_sales->readFile(this, fileName.toStdString(), *my_inventory, *all_members))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file");
        return;
    }

    printReport();
}

/*******************************************************************
 * void on_makePurchase_clicked();
 *
 *   Mutator; This method will submit the values inputted from
 *            on_manualSale_clicked
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none - all_sales attribute is updated
 *******************************************************************/
void make_sale::on_makePurchase_clicked()
{
    ui->textBrowser->clear();
    std::string date;
    int id;
    std::string name;
    double price;
    int quantity;
    date = ui->date->date().toString("MM/dd/yyyy").toStdString();
    id = ui->Id->value();
    name = ui->itemName->text().toStdString();
    int index = my_inventory->search(name);
    if(index == -1)
    {
        QMessageBox::warning(this, "Warning", "Item does not exist");
        return;
    }
    price = (*my_inventory)[index].get_price();
    quantity = ui->quantity->value();
    sales mysale(date, id, name, price, quantity);
    all_sales->push_back(this, mysale, *my_inventory, *all_members);
    printReport();

    ui->date->clear();
    ui->Id->clear();
    ui->itemName->clear();
    ui->quantity->clear();
}
