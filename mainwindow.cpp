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
}

void MainWindow::on_newMemberButton_clicked()
{
    // member class
}

void MainWindow::on_dailySales_clicked()
{
    sales_container sc;

    sales temp1("03/01/2021", 1234, "penguin", 1.0, 1);
    sales temp2("03/01/2021", 1234, "seal", 2.0, 1);
    sales temp3("03/02/2021", 2345, "walrus", 10.0, 2);
    sc.push_back(temp1);
    sc.push_back(temp2);
    sc.push_back(temp3);
    sR = new sales_report(nullptr, sc);

    sR->show();
}
