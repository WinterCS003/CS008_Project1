#ifndef SALES_REPORT_H
#define SALES_REPORT_H

#include <QMainWindow>

#include "sales/sales_container.h"

QT_BEGIN_NAMESPACE
namespace Ui { class sales_report; }
QT_END_NAMESPACE

class sales_report : public QMainWindow
{
    Q_OBJECT

public:
    sales_report(QWidget *parent = nullptr);
    sales_report(QWidget *parent, const sales_container& sc);
    ~sales_report();


private slots:
    void on_submit_clicked();

    void on_back_clicked();

private:
    void switchScreen();
    void generate_daily_sales_report(std::string date);

    Ui::sales_report *ui;
    QString report_output;
    sales_container report;
};

#endif // SALES_REPORT_H
