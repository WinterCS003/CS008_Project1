#ifndef DAILY_SALES_H
#define DAILY_SALES_H

#include <QWidget>
#include <QMessageBox>

#include "sales/sales.h"
#include "sales/sales_container.h"
#include "member.h"
#include "members_container.h"

namespace Ui {
class daily_sales;
}

class daily_sales : public QWidget
{
    Q_OBJECT

public:
    daily_sales(QWidget *parent = nullptr);
    daily_sales(QWidget *parent, sales_container* sc, Members_Container* mc);
    ~daily_sales();


private slots:
    void on_submit_clicked();

    void on_goBack_clicked();

private:
    void switchScreen();
    void generate_daily_daily_sales(std::string date, int flag);

    Ui::daily_sales *ui;
    QString report_output;
    Members_Container* members;
    sales_container* report;
};

#endif // DAILY_SALES_H
