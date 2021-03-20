#ifndef INVENTORYTRACKER_H
#define INVENTORYTRACKER_H

#include <QDialog>
#include "inventory.h"
#include <QTableWidget>

namespace Ui {
class InventoryTracker;
}

class InventoryTracker : public QDialog
{
    Q_OBJECT

public:
    explicit InventoryTracker(QWidget *parent = nullptr);
    InventoryTracker(QWidget *parent, const inventory& iv);
    ~InventoryTracker();

private slots:
    void onMainMenu_clicked();

private:
    void backToHome();
    void empty();
    void generate_inventory_list();

    Ui::InventoryTracker *ui;
    QTableWidget itemList;
    inventory list;
    QString inventory_list;
};

#endif // INVENTORYTRACKER_H
