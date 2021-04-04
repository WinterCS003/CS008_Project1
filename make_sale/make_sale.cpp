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
    ui->fileInput->show();
    ui->manualSale->show();
    ui->dateLabel->hide();
    ui->date->hide();
    ui->idLabel->hide();
    ui->Id->hide();
    ui->quantityLabel->hide();
    ui->quantity->hide();
    ui->nameLabel->hide();
    ui->itemName->hide();
    ui->quantityLabel->hide();
    ui->quantity->hide();
    ui->makePurchase->hide();

    ui->back->hide();
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
 * void on_back_clicked();
 *
 *   Accessor; This method will call the function switch screen
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
void make_sale::on_back_clicked()
{
    switchScreen();
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
    report += " Sales made\n";
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

/****************************************************************
 * void switchScreen();
 *
 *   Accessor; This method will switch the screen between
 *             making input from a file and making a manual input
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - widget window is changed
 ***************************************************************/
void make_sale::switchScreen()
{
    // if on manual input view
    if(ui->fileInput->isHidden())
    {
        ui->fileInput->show();
        ui->manualSale->show();
        ui->idLabel->hide();
        ui->Id->hide();
        ui->dateLabel->hide();
        ui->date->hide();
        ui->quantityLabel->hide();
        ui->quantity->hide();
        ui->nameLabel->hide();
        ui->itemName->hide();
        ui->quantityLabel->hide();
        ui->quantity->hide();
        ui->makePurchase->hide();
    }
    else
    {
        ui->fileInput->hide();
        ui->manualSale->hide();
        ui->back->show();
        ui->dateLabel->show();
        ui->date->show();
        ui->idLabel->show();
        ui->Id->show();
        ui->quantityLabel->show();
        ui->quantity->show();
        ui->nameLabel->show();
        ui->itemName->show();
        ui->quantityLabel->show();
        ui->quantity->show();
        ui->makePurchase->show();
    }
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
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    if(!all_sales->readFile(this, fileName.toStdString(), *my_inventory, *all_members))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file");
        return;
    }

    printReport();
}

/*******************************************************************
 * void on_manualSale_clicked();
 *
 *   Mutator; This method will pop up a new window for user to
 *            manual input values to make a sale
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void make_sale::on_manualSale_clicked()
{
    switchScreen();
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
    std::string date;
    int id;
    std::string name;
    double price;
    int quantity;
    date = ui->date->date().toString("MM/dd/yyyy").toStdString();
    id = ui->Id->value();
    name = ui->itemName->text().toStdString();
    int index = my_inventory->search(name);;
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
