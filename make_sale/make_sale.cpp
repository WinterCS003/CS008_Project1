#include "make_sale.h"
#include "ui_make_sale.h"

#include "sales/sales.h"
#include <fstream>

make_sale::make_sale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::make_sale)
{
    ui->setupUi(this);
}

make_sale::make_sale(QWidget *parent, sales_container* sc, Members_Container* mc, inventory* i)
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
    ui->priceLabel->hide();
    ui->itemPrice->hide();
    ui->makePurchase->hide();
}

make_sale::~make_sale()
{
    delete ui;
}

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
        ui->priceLabel->hide();
        ui->itemPrice->hide();
        ui->makePurchase->hide();
    }
    else
    {
        ui->fileInput->hide();
        ui->manualSale->hide();
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
        ui->priceLabel->show();
        ui->itemPrice->show();
        ui->makePurchase->show();
    }
}

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

void make_sale::on_manualSale_clicked()
{
    switchScreen();
}

void make_sale::on_back_clicked()
{
    switchScreen();
}

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
    price = ui->itemPrice->value();
    quantity = ui->quantity->value();
    sales mysale(date, id, name, price, quantity);
    all_sales->push_back(this, mysale, *my_inventory, *all_members);
    printReport();

    ui->date->clear();
    ui->Id->clear();
    ui->itemName->clear();
    ui->itemPrice->clear();
    ui->quantity->clear();
}
