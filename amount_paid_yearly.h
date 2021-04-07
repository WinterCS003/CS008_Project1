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

private slots:
    void on_submit_clicked();
    void on_close_clicked();

private:
    // displays each members amount paid per year with their name and member type
    void generate_report(int flag);

    Ui::amount_paid_yearly *ui;
    Members_Container *members;
    QString report_output;
};


/*******************************
 ** CONSTRUCTORS & DESTRUCTOR **
 *******************************/

/*************************************************************
 * amount_paid_yearly(QWidget *parent = nullptr);
 *      CTOR; initialize class objects to null
 * -----------------------------------------------------------
 *      Parameters: QWidget*
 * -----------------------------------------------------------
 *      Returns: none
**************************************************************/

/*************************************************************
 * amount_paid_yearly(QWidget* parent, Members_Container* m);
 *      CTOR; initialize class attributes;
 * -----------------------------------------------------------
 *      Parameters: parent (QWidget*) // IN: ptr to window
 *          m (Members_Container*)  // IN: ptr to all members
 * -----------------------------------------------------------
 *      Returns: none
**************************************************************/

/*************************************************************
 * ~amount_paid_yearly()
 *      Destructor; frees memory used by ui (window)
 * -----------------------------------------------------------
 *      Parameters: none
 * -----------------------------------------------------------
 *      Returns: none
**************************************************************/


/***************
 ** ACCESSORS **
 **************/

/*************************************************************
 * void on_submit_clicked()
 *      Accessor; checks if basic / preferred checkbox is
 * checked, and sets to an int and then calls generate_report(int)
 * -----------------------------------------------------------
 *      Parameters: none
 * -----------------------------------------------------------
 *      Returns: none
**************************************************************/


/*************************************************************
 * void on_close_clicked()
 *      Accessor; closes the amount_paid_yearly window
 * ----------------------------------------------------------
 *      Parameters: none
 * ----------------------------------------------------------
 *      Returns: none
**************************************************************/


#endif // AMOUNT_PAID_YEARLY_H
