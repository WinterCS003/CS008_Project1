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
    delete sR;
    delete ui;
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
    sR = new sales_report(nullptr, &sc, &mc);

    sR->show();
}

// manage all member operations(adding, displaying reports etc)
void MainWindow::on_manageMembers_clicked()
{
    Members_Container mc;
    mM = new manageMembers(nullptr, mc);
    mM->show();
}
