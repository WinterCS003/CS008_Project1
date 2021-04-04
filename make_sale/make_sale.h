#ifndef MAKE_SALE_H
#define MAKE_SALE_H

#include <iostream>

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

#include "sales/sales_container.h"
#include "sales/sales.h"
#include "member.h"

#include "inventory.h"
#include "members_container.h"

QT_BEGIN_NAMESPACE
namespace Ui { class make_sale; }
QT_END_NAMESPACE

class make_sale : public QMainWindow
{
    Q_OBJECT

public:
    make_sale(QWidget *parent = nullptr);
    make_sale(QWidget *parent, sales_container* sc, Members_Container* mc, inventory* i);
    ~make_sale();

private slots:
    /***************
     ** ACCESSORS **
     ***************/
    void on_back_clicked();

    /***************
     ** MUTATORS **
     ***************/
    void on_fileInput_clicked();

    void on_manualSale_clicked();

    void on_makePurchase_clicked();


private:
    void printReport();
    void switchScreen();

    Ui::make_sale *ui; // IN - pointer to the window
    sales_container* all_sales; // IN - all sales made
    Members_Container* all_members; // IN - all members
    inventory* my_inventory; // IN - all items in stock
};

#endif // MAKE_SALE_H

/****************************************************************
 * make_sale Class
 *   This class represents a make_sale widget. It manages 4
 *   attributes: ui pointer to the widget/window, all_sales keeps
 *   track of all sales made, all_members keeps track of all
 *   members, my_inventory keeps track of all items.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * make_sale(QWidget *parent)
 *   Constructor; Initialize class attributes
 *
 *   Parameters: parent (QWidget *) // IN - pointer to the window
 *
 *   Return: none
 ***************************************************************/

/****************************************************************
 * make_sale(QWidget *parent,
 *           sales_container* sc,
 *           Members_Container* mc,
 *           inventory* i);
 *   Constructor; Initialize class attributes
 *
 *   Parameters: parent (QWidget *) // IN - pointer to the window
 *               sc (sales_container*) // IN - all sales made
 *               mc (Members_Container*) // IN - container of all members
 *               i (inventory*)  // IN - inventory of all items in stock
 *
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~make_sale();
 *   Destructor; Frees memory used by ui.
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * void on_back_clicked();
 *
 *   Accessor; This method will call the function switch screen
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void printReport();
 *
 *   Accessor; This method will print a report of all sales made
 *             mainly for debugging purposes
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - output to widget
 ***************************************************************/

/****************************************************************
 * void switchScreen();
 *
 *   Accessor; This method will switch the screen between
 *             making input from a file and making a manual input
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - widget window is changed
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void on_fileInput_clicked();
 *
 *   Mutator; This method will pop up a new window for user to
 *            chose a file to read sales from
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none - all_sales attribute is updated
 *******************************************************************/

/*******************************************************************
 * void on_manualSale_clicked();
 *
 *   Mutator; This method will pop up a new window for user to
 *            manual input values to make a sale
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_makePurchase_clicked();
 *
 *   Mutator; This method will submit the values inputted from
 *            on_manualSale_clicked
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none - all_sales attribute is updated
 *******************************************************************/

