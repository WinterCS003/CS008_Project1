#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_inventorytracker.h"

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
    delete ms;
    delete ui;
    delete it;
}

void MainWindow::on_quitButton_clicked()
{
    qApp->quit();
}



void MainWindow::on_loginButton_clicked()
{
    // when 'login' button is clicked, appear a page where user can
    //  input member id #,
    // member class
    // program reads from txt file of all members and sales?
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
    ms = new make_sale(nullptr, &all_sales, &mc, &item_container);
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
