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
#include "sales/sales_container.h"

namespace Ui {
class amount_paid_yearly;
}

class amount_paid_yearly : public QDialog
{
    Q_OBJECT

public:
    /***************
     ** ACCESSORS **
     ***************/
    explicit amount_paid_yearly(QWidget *parent = nullptr);
    amount_paid_yearly(QWidget* parent, Members_Container* m, sales_container* sc);
    ~amount_paid_yearly();

    // displays each members amount paid per year with their name and member type
    void generate_report(int flag);

private slots:
    void on_submit_clicked();
    void on_close_clicked();    // if 'close' button is pushed- exit window

private:
    Ui::amount_paid_yearly *ui;
    Members_Container *members;
    sales_container* all_sales;
    QString report_output;
};

#endif // AMOUNT_PAID_YEARLY_H

/****************************************************************
 * amount_paid_yearly Class
 *   This class represents an amount paid yearly widget. It
 *   generates a report based off of how much a member paid in
 *   the year. The class manages an ui, Members_Container,
 *   sales_container, and QString attributes.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * amount_paid_yearly(QWidget *parent = nullptr);
 *   Constructor; Initialize class attributes to null
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *   Return: none
 ***************************************************************/

/****************************************************************
 * amount_paid_yearly(QWidget* parent,
 *                    Members_Container* m,
 *                    sales_container* sc);
 *   Constructor; Initializes attributes with parameters
 *   Parameters: QWidget* parent, // IN - pointer to widget window
 *               Members_Container* m // IN - pointer to members container
 *               sales_container* sc // IN - pointer to sales container
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~amount_paid_yearly();
 *   Destructor; deletes ui pointer
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * void generate_report(int flag);
 *
 *   Accessor; This method will create a report for basic
 *   preferred or both members based on user input
 * --------------------------------------------------------------
 *   Parameters: flag (int) // IN - user specified value for
 *                                  member type to print
 * --------------------------------------------------------------
 *   Return: none - report is output to screen
 ***************************************************************/

/****************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will determine the flag and
 *   call generate_report.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - generate_report is called
 ***************************************************************/

/****************************************************************
 * void on_close_clicked();
 *
 *   Accessor; This method will close the window
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
