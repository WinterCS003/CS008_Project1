#ifndef INVENTORYTRACKER_H
#define INVENTORYTRACKER_H

#include <QDialog>
#include "inventory.h"
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
    InventoryTracker(QWidget *parent, inventory* iv);
    ~InventoryTracker();

private slots:
    void on_exit_clicked();

private:
    void generate_inventory_list();
    void empty();

    Ui::InventoryTracker *ui;
    inventory* list;
    QTableView itemTable;
    QStandardItemModel *model;
    QLineEdit *text;
};

#endif // INVENTORYTRACKER_H
