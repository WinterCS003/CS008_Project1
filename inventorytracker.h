#ifndef INVENTORYTRACKER_H
#define INVENTORYTRACKER_H

#include <QDialog>
#include "inventory.h"
#include "sales/sales_container.h"
#include <QTableView>
#include <QItemDelegate>
#include <QStandardItemModel>

namespace Ui {
class InventoryTracker;
}

class InventoryTracker : public QDialog
{
    Q_OBJECT

public:
    explicit InventoryTracker(QWidget *parent = 0);
    InventoryTracker(QWidget *parent, inventory* iv, sales_container* sales);
    ~InventoryTracker();

private slots:
    /***************
     ** ACCESSORS **
     ***************/
    void on_exit_clicked();

private:
    void generate_inventory_list();
    void empty();

    Ui::InventoryTracker *ui;
    inventory* list;
    sales_container* all_sales;
    QTableView itemTable;
    QStandardItemModel *model;
    QLineEdit *text;
};

#endif // INVENTORYTRACKER_H

/****************************************************************
 * InventoryTracker Class
 *   This class represents an inventory tracker widget, it
 *   generates a report based off of all the items in stock
 *   and that were sold. It handles a sales_container, QTableView,
 *   QStandardItemModel, QLineEdit, and inventory pointers.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * InventoryTracker(QWidget *parent = 0);
 *   Constructor; Initialize class attributes to null
 *   Parameters: parent (QWidget*) // IN - pointer to widget
 *   Return: none
 ***************************************************************/

/****************************************************************
 * InventoryTracker(QWidget *parent,
 *                  inventory* iv,
 *                  sales_container* sales);
 *   Constructor; Initialize class attributes to parameters
 *   Parameters: QWidget *parent, // IN - pointer to widget window
 *               inventory* iv, // IN - inventory pointer
 *               sales_container* sales); // IN - sales container pointer
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~InventoryTracker();
 *   Destructor; Deletes ui pointer
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * void on_exit_clicked();
 *
 *   Accessor; This method will close the window
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 void generate_inventory_list();
 *
 *   Accessor; This method will create a report of all items
 *   in stock and how many were sold
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is printed
 ***************************************************************/

/****************************************************************
 * void empty();
 *
 *   Accessor; This method will notify the user if the
 *   inventory is empty
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
