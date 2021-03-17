#include "inventorytracker.h"
#include "ui_inventorytracker.h"

InventoryTracker::InventoryTracker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InventoryTracker)
{
    ui->setupUi(this);
    generate_inventory_list();
}

InventoryTracker::InventoryTracker(QWidget *parent, const inventory& iv)
    : QDialog(parent), ui(new Ui::InventoryTracker)
{
    ui->setupUi(this);
    ui->itemList->hide();
    list = iv;
    if (inventory_list == 0) {
        empty();
    } else {
        generate_inventory_list();
    }
}

InventoryTracker::~InventoryTracker()
{
    delete ui;
}

void InventoryTracker::generate_inventory_list()
{
    inventory_list = inventory_list.fromStdString(("Item: " + list.getItemName()
                                                   + (" ID num: " + list.getItemNumber())));

    for (int i = 0; i < list.size(); i++) {
        if (list[i].get_ID() == inventory_list) {
            inventory_list += list[i].get_ID();
            inventory_list += "     ";
            inventory_list += list[i].get_quantity();
            inventory_list += "     ";
            inventory_list += list[i].get_price();
            inventory_list += "     ";
            inventory_list += list[i].get_total();
            inventory_list += "     ";
        }
    }
    ui->itemList->show();
    ui->itemList->setText(inventory_list);
}

void InventoryTracker::empty()
{
    ui->itemList->setText("No items in stock.");
}

void InventoryTracker::onMainMenu_clicked()
{
    ui->exit->close();
}


