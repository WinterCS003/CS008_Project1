#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_inventorytracker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // update containers to have all previous info
    iv.readFile("all-items.txt");
    mc.add_bulk_members("all-members.txt");
    all_sales.readFile("all-sales.txt");

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    // save contents of containers for next execution
    all_sales.outFile("all-sales.txt");
    iv.outFile("all-items.txt");
    mc.outFile("all-members.txt");

    // deallocate all pointers
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
    // save contents of containers for next execution
    all_sales.outFile("all-sales.txt");
    iv.outFile("all-items.txt");
    mc.outFile("all-members.txt");

    qApp->closeAllWindows();
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
    mM = new manageMembers(nullptr, &mc, &all_sales);
    mM->show();
}

void MainWindow::on_makeSale_clicked()
{
    ms = new make_sale(nullptr, &all_sales, &mc, &iv);
    ms->show();
}

void MainWindow::on_yearlySales_clicked()
{
    yearlySale = new yearly_sales(nullptr, &all_sales, &mc, &iv);
    yearlySale->show();
}

void MainWindow::on_manageInventory_clicked()
{
    it = new InventoryTracker(nullptr, &iv, &all_sales);
    it->show();
}

void MainWindow::on_itemReport_clicked()
{
    ir = new item_reports(nullptr, &all_sales, &iv);
    ir->show();
}

void MainWindow::on_purchaseReports_clicked()
{
    purchaseReport = new memberPurchase(nullptr, &all_sales, &mc, &iv);
    purchaseReport->show();
}

void MainWindow::on_pushButton_clicked()
{
    dues = new amount_paid_yearly(this, &mc, &all_sales);
    dues->show();
}
