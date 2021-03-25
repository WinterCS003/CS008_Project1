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

make_sale::make_sale(QWidget *parent, sales_container* sc)
    : QMainWindow(parent)
    , ui(new Ui::make_sale)
    , all_sales(sc)
{
    ui->setupUi(this);
    ui->fileInput->show();
    ui->manualSale->show();
    ui->dateLabel->hide();
    ui->date->hide();
    ui->numberLabel->hide();
    ui->number->hide();
    ui->nameLabel->hide();
    ui->name->hide();
    ui->quantityLabel->hide();
    ui->quantity->hide();
    ui->priceLabel->hide();
    ui->price->hide();
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
        ui->dateLabel->hide();
        ui->date->hide();
        ui->numberLabel->hide();
        ui->number->hide();
        ui->nameLabel->hide();
        ui->name->hide();
        ui->quantityLabel->hide();
        ui->quantity->hide();
        ui->priceLabel->hide();
        ui->price->hide();
        ui->makePurchase->hide();
    }
    else
    {
        ui->fileInput->hide();
        ui->manualSale->hide();
        ui->dateLabel->show();
        ui->date->show();
        ui->numberLabel->show();
        ui->number->show();
        ui->nameLabel->show();
        ui->name->show();
        ui->quantityLabel->show();
        ui->quantity->show();
        ui->priceLabel->show();
        ui->price->show();
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
    QFile file(fileName);
    if (file.size() == 0)
    {
        return;
    }
    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    ifstream in(fileName.toStdString());
    std::string date;
    while(getline(in, date))
    {
        int id;
        in >> id;
        in.ignore();
        std::string name;
        getline(in, name);
        double price;
        in >> price;
        int quantity;
        in >> quantity;
        in.ignore();
        sales temp(date, id, name, price, quantity);
        all_sales->push_back(temp);
    }
    printReport();

    file.close();
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
    id = ui->number->text().toInt();
    name = ui->name->text().toStdString();
    price = ui->price->text().toDouble();
    quantity = ui->quantity->text().toInt();
    sales mysale(date, id, name, price, quantity);
    all_sales->push_back(mysale);
    printReport();
    ui->date->clear();
    ui->number->clear();
    ui->name->clear();
    ui->price->clear();
    ui->quantity->clear();
}
