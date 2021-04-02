#ifndef AMOUNT_PAID_YEARLY_H
#define AMOUNT_PAID_YEARLY_H

#include <iostream>
using namespace std;
#include <string>
#include <QDialog>
#include "QLineEdit"
#include <QMessageBox>
#include "member.h"
#include "members_container.h"

namespace Ui {
class amount_paid_yearly;
}

class amount_paid_yearly : public QDialog
{
    Q_OBJECT

public:
    explicit amount_paid_yearly(QWidget *parent = nullptr);
    amount_paid_yearly(QWidget* parent, Members_Container* m);
    ~amount_paid_yearly();

    // displays each members amount paid per year with their name and member type
    void generate_report(int flag);

private slots:
    void on_submit_clicked();
    void on_close_clicked();    // if 'close' button is pushed- exit window

private:
    Ui::amount_paid_yearly *ui;
    Members_Container *members;
    QString report_output;
};

#endif // AMOUNT_PAID_YEARLY_H
