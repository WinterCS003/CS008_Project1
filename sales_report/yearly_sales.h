#ifndef YEARLY_SALES_H
#define YEARLY_SALES_H

#include <QWidget>
#include <QMessageBox>

#include "sales/sales_container.h"
#include "sales/sales.h"
#include "members_container.h"
#include "member.h"
#include "inventory.h"

namespace Ui {
class yearly_sales;
}

class yearly_sales : public QWidget
{
    Q_OBJECT

public:
    explicit yearly_sales(QWidget *parent = nullptr);
    yearly_sales(QWidget *parent, // IN - pointer to window
                 sales_container* all_sales, // IN - all sales made
                 Members_Container* mc, // IN - all members
                 inventory* iv); // IN - all items in stock
    ~yearly_sales();

private slots:
    /***************
     ** ACCESSORS **
     ***************/
    void on_goBack_clicked();
    void on_submit_clicked();

private:
    void switchScreen();
    void clearInput();

    Ui::yearly_sales *ui;
    sales_container* all_sales;
    Members_Container* all_members;
    inventory* all_items;
};

#endif // YEARLY_SALES_H

/****************************************************************
 * yearly_sales Class
 *   This class represents an yearly_sales widget window. This
 *   class manages 4 attributes: ui, all_sales, all_members, and
 *   all_items. The class allows users to generate reports by
 *   year.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * explicit yearly_sales(QWidget *parent = nullptr);
 *
 *   Constructor; Initialize class attributes
 *
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *
 *   Return: none
 ***************************************************************/

/****************************************************************
 * yearly_sales(QWidget *parent,
 *              sales_container* all_sales,
 *              Members_Container* mc,
 *              inventory* iv);
 *
 *   Constructor; Initialize class attributes, create new window
 *
 *   Parameters: QWidget *parent, // IN - pointer to window
 *               sales_container* all_sales, // IN - all sales made
 *               Members_Container* mc, // IN - all members
 *               inventory* iv // IN - all items in stock
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~yearly_sales();
 *   Destructor; Frees memory used by ui, widget pointer
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * void on_goBack_clicked();
 *
 *   Accessor; This method will call switch screen, and lets the
 *             user toggle between the report and input
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will take user input and generate a
 *             report of all yearly sales made
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is output to window
 ***************************************************************/

/****************************************************************
 * void switchScreen();
 *
 *   Accessor; This method will toggle between the report and
 *             user input windows
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void clearInput();
 *
 *   Accessor; This method will clear all input from the user
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
