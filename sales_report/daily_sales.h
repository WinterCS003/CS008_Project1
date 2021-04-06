#ifndef DAILY_SALES_H
#define DAILY_SALES_H

#include <QWidget>
#include <QMessageBox>

#include "sales/sales.h"
#include "sales/sales_container.h"
#include "member.h"
#include "members_container.h"

namespace Ui {
class daily_sales;
}

class daily_sales : public QWidget
{
    Q_OBJECT

public:
    /********************************
     ** CONSTRUCTORS & DESTRUCTORS **
     ********************************/
    daily_sales(QWidget *parent = nullptr);
    daily_sales(QWidget *parent,
                sales_container* sc,
                Members_Container* mc);
    ~daily_sales();


private slots:
    /***************
     ** ACCESSORS **
     ***************/
    void on_submit_clicked();

private:
    void generate_daily_daily_sales(std::string date,
                                    int flag);

    Ui::daily_sales *ui;
    QString report_output;
    Members_Container* members;
    sales_container* report;
};

#endif // DAILY_SALES_H

/****************************************************************
 * daily_sales Class
 *   This class represents a daily_sales widget window. On this
 *     page, the user can generate reports of all sales made on
 *     a specific date.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * daily_sales(QWidget* parent = nullptr);
 *   Constructor; create a new window
 *   Parameters: parent (QWidget*) // IN - pointer to widget
 *   Return: none
 ***************************************************************/

/****************************************************************
 *   daily_sales(QWidget *parent,
 *               sales_container* sc,
 *               Members_Container* mc);
 *   Constructor; create a new window and initializes all member
 *                attributes to the parameters.
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *               sc (sales_container*) // IN - all sales made
 *               mc (Members_Container*) // IN - container of members
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~daily_sales();
 *   Destructor; Frees memory used by the ui pointer
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will submit input from the user to
 *             generate a report. generate_daily_daily_sales is
 *             called
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void on_goBack_clicked();
 *
 *   Accessor; This method will call switch screen
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void switchScreen();
 *
 *   Accessor; This method will toggle between the report and
 *             input screens
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void generate_daily_daily_sales(std::string date,
 *                                 int flag);
 *
 *   Accessor; This method will create a report of all sales
 *             made on the date. User can specify a flag to
 *             toggle between member types
 * --------------------------------------------------------------
 *   Parameters: date (std::string) // IN - date of sales to find
 *               flag (int) // IN - member type
 *                          // 0 = basic
 *                          // 1 = preferrred
 *                          // 2 = both
 * --------------------------------------------------------------
 *   Return: none - report is output to the screen
 ***************************************************************/
