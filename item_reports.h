#ifndef ITEM_REPORTS_H
#define ITEM_REPORTS_H

#include <QWidget>
#include "sales/sales_container.h"
#include "sales/sales.h"
#include "inventory.h"

namespace Ui {
class item_reports;
}

class item_reports : public QWidget
{
    Q_OBJECT

public:
    explicit item_reports(QWidget *parent = nullptr);
    item_reports(QWidget *parent,
                 sales_container* all_sales,
                 inventory* all_items);
    ~item_reports();

private slots:
    /***************
     ** ACCESSORS **
     ***************/
    void on_submitButton_clicked();

private:
    void singleItemReport(std::string itemName);
    void allItemReport();

    Ui::item_reports *ui;
    sales_container* all_sales;
    inventory* all_items;
};

#endif // ITEM_REPORTS_H

/****************************************************************
 * item_reports Class
 *   This class represents an item report window. It manages 3
 *     attributes: a pointer to the window, a pointer to all
 *     sales made, and a pointer to all items in stock.
 *     This class generates a report of all items sold and
 *     left in stock.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * item_reports(QWidget* parent = nullptr);
 *   Constructor; Initialize class attributes to null
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *   Return: none
 ***************************************************************/

/****************************************************************
 * item_reports(QWidget *parent,
                 sales_container* all_sales,
                 inventory* all_items);
 *   Constructor; Initialize class attributes
 *   Parameters: parent (QWidget*) // IN - pointer to window
                 all_sales (sales_container*) // IN - pointer to
                                              // all sales made
                 all_items (inventory*) // IN - pointer to all
                                        // items in stock
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~item_reports();
 *   Destructor; Frees memory used by the window
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * void on_submitButton_clicked();
 *
 *   Accessor; This method will generate a report of all items
 *     or a single items based on user input.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated
 ***************************************************************/

/****************************************************************
 * void on_back_clicked();
 *
 *   Accessor; This method will call switchScreen and allow the
 *     user to toggle between input and report.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - screen is changed
 ***************************************************************/

/****************************************************************
 *  void singleItemReport(std::string itemName);
 *
 *   Accessor; This method will generate a report on a single
 *     item, sold and in stock based off of an itemName.
 * --------------------------------------------------------------
 *   Parameters: itemName (std::string) // IN - name of item to
 *                                      //      report
 * --------------------------------------------------------------
 *   Return: none - report on single item is generated
 ***************************************************************/

/****************************************************************
 * void allItemReport();
 *
 *   Accessor; This method will generate a report on all items
 *     in the all_items container.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is generated
 ***************************************************************/

/****************************************************************
 * void switchScreen();
 *
 *   Accessor; This method will switch between the input and
 *     report screens.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - this method will allow the user to switch
 *                  screens
 ***************************************************************/
