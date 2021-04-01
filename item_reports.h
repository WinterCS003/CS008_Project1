#ifndef ITEM_REPORTS_H
#define ITEM_REPORTS_H

#include <QWidget>
#include "sales/sales_container.h"
#include "sales/sales.h"
#include "inventory.h"

namespace Ui {
class item_reports;
}

class item_reports : public QWidget
{
    Q_OBJECT

public:
    explicit item_reports(QWidget *parent = nullptr);
    item_reports(QWidget *parent,
                 sales_container* all_sales,
                 inventory* all_items);
    ~item_reports();

private slots:
    void on_submitButton_clicked();

    void on_back_clicked();

private:
    void singleItemReport(std::string itemName);
    void allItemReport();
    void switchScreen();

    Ui::item_reports *ui;
    sales_container* all_sales;
    inventory* all_items;
};

#endif // ITEM_REPORTS_H
