#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "inventorytracker.h"

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
private:
    Ui::MainWindow *ui;
    InventoryTracker* it;
    inventory iv;
};



#endif // MAINWINDOW_H
