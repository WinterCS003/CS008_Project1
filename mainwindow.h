#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "item.h"
#include "sales_report/sales_report.h"

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
    void on_newMemberButton_clicked();  // if user clicks 'new member'

    void on_dailySales_clicked();

private:
    Ui::MainWindow *ui;
    sales_report* sR;
};

#endif // MAINWINDOW_H
