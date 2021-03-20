#include "inventorytracker.h"
#include "ui_inventorytracker.h"

InventoryTracker::InventoryTracker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InventoryTracker)
{
    ui->setupUi(this);
    ui->title->show();
    ui->table->hide();
    ui->exit->hide();
}

InventoryTracker::InventoryTracker(QWidget *parent, const inventory& iv)
    : QDialog(parent), ui(new Ui::InventoryTracker)
{
    ui->setupUi(this);
    ui->title->show();
    ui->table->hide();
    ui->exit->hide();

    Item i1("gallon milk", 13, 2.49);
    i1.set_item_number(12345);
    list.push_back(i1);
    Item i2("Potato bread", 20, 1.79);
    i2.set_item_number(67899);
    list.push_back(i2);
    Item i3("Ground Beef", 1, 6.85);
    i3.set_item_number(12899);
    list.push_back(i3);
    Item i4("Pork Tenderloin", 2, 17.25);
    i4.set_item_number(12900);
    list.push_back(i4);

    list = iv;
    generate_inventory_list();

}

InventoryTracker::~InventoryTracker()
{
    delete ui;
}

void InventoryTracker::onMainMenu_clicked()
{
    backToHome();
}

void InventoryTracker::backToHome()
{
    if (ui->exit->isVisible()) {
        ui->exit->hide();
        ui->table->hide();
        ui->title->hide();
    }
}

void InventoryTracker::empty()
{
    if (inventory_list.size() == 0) {
        inventory_list += "No items in here. ";
    }
}

void InventoryTracker::generate_inventory_list()
{
    ui->table->show();
    ui->exit->show();

    QTableWidget *newTable = new QTableWidget(this);
    newTable->setRowCount(10);
    newTable->setColumnCount(6);

    for (int i = 0; i < list.size(); i++) {
        if (ui->table->columnAt(i) && ui->table->rowAt(i)) {
            inventory_list.toStdString() += list[i].get_item_name();
        }
        else if (ui->table->columnAt(i) && ui->table->rowAt(i)) {
            inventory_list += list[i].get_ID();
        }
        else if (ui->table->columnAt(i) && ui->table->rowAt(i)) {
            inventory_list += list[i].get_quantity();
        }
        else if (ui->table->columnAt(i) && ui->table->rowAt(i)) {
            // quantity left in stock
        }
        else if (ui->table->columnAt(i) && ui->table->rowAt(i)) {
            inventory_list += list[i].get_price();
        }
        else if (ui->table->columnAt(i) && ui->table->rowAt(i)) {
            inventory_list += list[i].get_total();
        }
    }

}



