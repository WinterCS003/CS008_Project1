#ifndef YEARLY_SALES_H
#define YEARLY_SALES_H

#include <QWidget>
#include <QMessageBox>

#include "sales/sales_container.h"
#include "sales/sales.h"
#include "members_container.h"
#include "member.h"

namespace Ui {
class yearly_sales;
}

class yearly_sales : public QWidget
{
    Q_OBJECT

public:
    explicit yearly_sales(QWidget *parent = nullptr);
    yearly_sales(QWidget *parent, sales_container* all_sales, Members_Container* mc);
    ~yearly_sales();

private slots:
    void on_goBack_clicked();
    void on_submit_clicked();

private:
    void switchScreen();
    void clearInput();

    Ui::yearly_sales *ui;
    sales_container* all_sales;
    Members_Container* all_members;
};

#endif // YEARLY_SALES_H
