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
    sR = new sales_report;
    sR->show();
}
