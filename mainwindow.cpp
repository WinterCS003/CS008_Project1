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
    delete ui;
    delete it;
}

void MainWindow::on_quitButton_clicked()
{
    qApp->quit();
}

void MainWindow::on_inventory_clicked()
{
    it = new InventoryTracker(nullptr);
    it->show();
}


