#ifndef ITEMREPORT_H
#define ITEMREPORT_H

#include <QWidget>
#include "sales/sales_container.h"

namespace Ui {
class itemreport;
}

class itemreport : public QWidget
{
    Q_OBJECT

public:
    explicit itemreport(QWidget *parent = nullptr);
    itemreport(QWidget *parent, sales_container* my_sales);
    ~itemreport();

private:
    Ui::itemreport *ui;
    sales_container* mySales;
};

#endif // ITEMREPORT_H
