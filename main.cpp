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
