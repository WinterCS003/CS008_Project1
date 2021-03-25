#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "item.h"

// sales libraries
#include "sales_report/daily_sales.h"
#include "sales_report/yearly_sales.h"
#include "make_sale/make_sale.h"

// member libraries
#include "member.h"
#include "members_container.h"
#include "managemembers.h"

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
    void on_loginButton_clicked();      // if user clicks 'login'

    void on_manageMembers_clicked(); // if manage members is clicked

    void on_makeSale_clicked();
    void on_dailySales_clicked();
    void on_yearlySales_clicked();
    
    void on_quitButton_clicked();       // if user quits, program exits
    void on_manageInventory_clicked();        // if inventory is clicked

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
    InventoryTracker* it;
};

#endif // MAINWINDOW_H
