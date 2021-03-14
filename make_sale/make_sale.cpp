#include "make_sale.h"
#include "ui_make_sale.h"

#include "sales/sales.h"

make_sale::make_sale(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::make_sale)
{
    ui->setupUi(this);
}

make_sale::~make_sale()
{
    delete ui;
}

void make_sale::on_purchase_clicked()
{
    QDate d;
    d = d.currentDate();

    sales s(d.toString("MMddyyyy").toStdString(), ui->item->text().toStdString(), ui->member->text().toStdString(), false, ui->price->text().toDouble());
    sc.push_back(s);
}
