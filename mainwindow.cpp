#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete mM;
    delete dailySale;
    delete yearlySale;
    delete ms;
    delete ui;
    delete it;
}

void MainWindow::on_quitButton_clicked()
{
    qApp->quit();
}


void MainWindow::on_dailySales_clicked()
{
    dailySale = new daily_sales(nullptr, &all_sales, &mc);
    dailySale->show();
}

// manage all member operations(adding, displaying reports etc)
void MainWindow::on_manageMembers_clicked()
{
//    Members_Container mc;
    mM = new manageMembers(nullptr, mc);
    mM->show();
}

void MainWindow::on_makeSale_clicked()
{
    ms = new make_sale(nullptr, &all_sales, &mc, &iv);
    ms->show();
}

void MainWindow::on_yearlySales_clicked()
{
    yearlySale = new yearly_sales(nullptr, &all_sales, &mc);
    yearlySale->show();
}

void MainWindow::on_manageInventory_clicked()
{
    it = new InventoryTracker(nullptr, iv);
    it->show();
}

void MainWindow::on_amountPerYear_clicked()
{
    ap = new amount_paid_yearly(nullptr, &mc);
    ap->show();
}



