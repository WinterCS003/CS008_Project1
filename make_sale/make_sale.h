#ifndef MAKE_SALE_H
#define MAKE_SALE_H

#include <QMainWindow>

#include "sales/sales_container.h"

QT_BEGIN_NAMESPACE
namespace Ui { class make_sale; }
QT_END_NAMESPACE

class make_sale : public QMainWindow
{
    Q_OBJECT

public:
    make_sale(QWidget *parent = nullptr);
    ~make_sale();

private slots:
    void on_purchase_clicked();

private:
    Ui::make_sale *ui;
    sales_container sc;
};
#endif // MAKE_SALE_H
