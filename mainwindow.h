#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// item libraries
#include "item.h"
#include "inventory.h"

// sales libraries
#include "sales/sales.h"
#include "sales/sales_container.h"
#include "make_sale/make_sale.h"

// Member libraries
#include "member.h"
#include "members_container.h"
#include "managemembers.h"

// report libraries
#include "memberpurchase.h"
#include "item_reports.h"
#include "inventorytracker.h"
#include "sales_report/daily_sales.h"
#include "sales_report/yearly_sales.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_quitButton_clicked();       // if user quits, program exits
    void on_manageInventory_clicked();        // if inventory is clicked

    void on_manageMembers_clicked(); // if manage members is clicked

    void on_makeSale_clicked();
    void on_dailySales_clicked();
    void on_yearlySales_clicked();

    void on_itemReport_clicked();

    void on_purchaseReports_clicked();

private:

    Ui::MainWindow *ui;
    // containers
    Members_Container mc;      // all members
    sales_container all_sales; // all sales
    inventory iv;
    // update containers
    manageMembers* mM; // add or delete members
    make_sale* ms;     // add sales
    // reports
    daily_sales* dailySale;  // Sales report by day
    yearly_sales* yearlySale; // Sales report by year
    item_reports* ir;
    InventoryTracker* it;
    memberPurchase* purchaseReport;
};

#endif // MAINWINDOW_H
