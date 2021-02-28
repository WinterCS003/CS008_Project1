/******************************************************************
 * AUTHORS   : Thomas Benson, David Dang, Jaemok C. Lee, Ellen Yim
 * PROJECT 1 : Super Warehouse Store
 * CLASS     : CS 008 Data Structures
 * SECTION   : MW 6:30p-8:35
 * DUE DATE  : 04/07/2021
 ******************************************************************/
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // This is our main file
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
