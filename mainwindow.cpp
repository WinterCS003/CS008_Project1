#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_inventorytracker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // update containers to have all previous sales
    iv.readFile("all-items.txt");
    mc.readFile("all-members.txt");
    all_sales.readFile(this, "all-sales.txt", iv, mc);
    std::cout << iv.size() << std::endl;
    iv.size() > 0 ? std::cout << iv[0].get_item_name() << std::endl : std::cout << std::endl;
//    sales s1("01/02/2021", 0, "Chicken", 1.23, 2);
//    sales s2("01/02/2021", 1, "Turkey", 2.34, 1);
//    sales s3("01/03/2021", 1, "Fish", 0.34, 5);
//    all_sales.push_back(s1);
//    all_sales.push_back(s2);
//    all_sales.push_back(s3);

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    // save contents of containers for next execution
    all_sales.outFile("all-sales.txt");
    iv.outFile("all-items.txt");
    mc.outFile("all-members.txt");
    // deallocate all pointers
    delete mM;
    delete dailySale;
    delete yearlySale;
    delete ms;
    delete ui;
    delete it;
}

void MainWindow::on_quitButton_clicked()
{
    all_sales.outFile("./containers/all-sales.txt");
    qApp->closeAllWindows();
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
    mM = new manageMembers(nullptr, &mc);
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
    it = new InventoryTracker(nullptr, &iv);
    it->show();
}
