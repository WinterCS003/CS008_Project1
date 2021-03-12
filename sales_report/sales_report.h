#ifndef SALES_REPORT_H
#define SALES_REPORT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class sales_report; }
QT_END_NAMESPACE

class sales_report : public QMainWindow
{
    Q_OBJECT

public:
    sales_report(QWidget *parent = nullptr);
    ~sales_report();

private:
    Ui::sales_report *ui;
};
#endif // SALES_REPORT_H
