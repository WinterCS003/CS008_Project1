#ifndef MEMBERPURCHASE_H
#define MEMBERPURCHASE_H

#include <QWidget>

#include "sales/sales_container.h"
#include "sales/sales.h"
#include "inventory.h"
#include "members_container.h"

namespace Ui {
class memberPurchase;
}

class memberPurchase : public QWidget
{
    Q_OBJECT

public:
    explicit memberPurchase(QWidget *parent = nullptr);
    memberPurchase(QWidget* parent,
                   sales_container* sc,
                   Members_Container* mc,
                   inventory* iv);
    ~memberPurchase();

private slots:
    void on_back_clicked();

    void on_submit_clicked();

private:
    void singleMemberReport(int id);
    void singleMemberReport(std::string name);
    void allMemberReport();
    void switchScreen();

    Ui::memberPurchase *ui;
    sales_container* all_sales;
    Members_Container* all_members;
    inventory* all_items;
};

#endif // MEMBERPURCHASE_H
