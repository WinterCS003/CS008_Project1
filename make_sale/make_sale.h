#ifndef MAKE_SALE_H
#define MAKE_SALE_H

#include <iostream>

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

#include "sales/sales_container.h"
#include "sales/sales.h"

QT_BEGIN_NAMESPACE
namespace Ui { class make_sale; }
QT_END_NAMESPACE

class make_sale : public QMainWindow
{
    Q_OBJECT

public:
    make_sale(QWidget *parent = nullptr);
    make_sale(QWidget *parent, sales_container* sc);
    ~make_sale();

private slots:
    void on_fileInput_clicked();

    void on_manualSale_clicked();

    void on_back_clicked();

    void on_makePurchase_clicked();

private:
    void printReport();
    void switchScreen();
    Ui::make_sale *ui;
    sales_container* all_sales;
};
#endif // MAKE_SALE_H
