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
    /***************
     ** ACCESSORS **
     ***************/
    void on_back_clicked();

    void on_submit_clicked();

private:
    void allMemberReport();
    void switchScreen();

    Ui::memberPurchase *ui;
    sales_container* all_sales;
    Members_Container* all_members;
    inventory* all_items;
};

#endif // MEMBERPURCHASE_H

/****************************************************************
 * memberPurchase Class
 *   This class represents a member purchases window, it manages
 *     4 attributes, a pointer to the ui window, a pointer
 *     to a container of all sales made, a pointer to all members
 *     and a pointer to all items in the inventory.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * memberPurchase(QWidget *parent = nullptr);
 *   Constructor; Null initializes class attributes
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *   Return: none
 ***************************************************************/

/****************************************************************
 * memberPurchase(QWidget* parent,
                   sales_container* sc,
                   Members_Container* mc,
                   inventory* iv);
 *   Constructor; Initialize class attributes
 *   Parameters: parent (QWidget*) // IN  - pointer to window
                   sc (sales_container*) // IN - pointer to all sales made
                   mc (Members_Container*) // IN - ponter to all members
                   iv (inventory*) // IN - pointer to all items in stock
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~memberPurchase();
 *   Destructor; Frees memory used by the window
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * void on_back_clicked();
 *
 *   Accessor; This method will call the switchScreen method
 *     and allows the user to toggle between input and report
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - screen is switched
 ***************************************************************/

/****************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will submit all user input and generate
 *     a report based on the input.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated
 ***************************************************************/

/****************************************************************
 * void allMemberReport();
 *
 *   Accessor; This method will generate a report of all
 *     sales made by every member in the all_members container.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated for all members
 ***************************************************************/

/****************************************************************
 * void switchScreen();
 *
 *   Accessor; This method will allow the user to toggle between
 *     input and report screens.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - screen is switched
 ***************************************************************/
