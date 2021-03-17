#ifndef INVENTORYTRACKER_H
#define INVENTORYTRACKER_H

#include <QDialog>
#include "inventory.h"

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

    void generate_inventory_list();
    void empty();

private slots:
    void onMainMenu_clicked();

private:
    Ui::InventoryTracker *ui;
    QString inventory_list;
    inventory list;
};

#endif // INVENTORYTRACKER_H
