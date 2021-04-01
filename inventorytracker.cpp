#include "inventorytracker.h"
#include "ui_inventorytracker.h"

InventoryTracker::InventoryTracker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InventoryTracker)
{
    ui->setupUi(this);
}

InventoryTracker::InventoryTracker(QWidget *parent, inventory* iv)
    : QDialog(parent), ui(new Ui::InventoryTracker)
{
    ui->setupUi(this);
    ui->title->show();
    ui->exit->show();
    this->list = iv;

    QStandardItem *name = new QStandardItem;
    name->setText("Item Name");
    QStandardItem *id = new QStandardItem;
    id->setText("Item ID");
    QStandardItem *sold = new QStandardItem;
    sold->setText("Amount sold");
    QStandardItem *stock = new QStandardItem;
    stock->setText("Amount in stock");
    QStandardItem *price = new QStandardItem;
    price->setText("Price sold at ");
    QStandardItem *total = new QStandardItem;
    total->setText("Total");

    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // QStandardItemModel(int rows, int cols, *parent)
    model = new QStandardItemModel(5, 6, this);
    model->setHorizontalHeaderItem(0, name);
    model->setHorizontalHeaderItem(1, id);
    model->setHorizontalHeaderItem(2, sold);
    model->setHorizontalHeaderItem(3, stock);
    model->setHorizontalHeaderItem(4, price);
    model->setHorizontalHeaderItem(5, total);

    // attach model to view
    ui->table->setModel(model);
    generate_inventory_list();
    ui->table->show();
}

InventoryTracker::~InventoryTracker()
{
    delete ui;
}

void InventoryTracker::on_exit_clicked()
{
    ui->~InventoryTracker();
    InventoryTracker::close();
}

void InventoryTracker::empty()
{
    ui->text->setText("Inventory List = 0 ");
}

void InventoryTracker::generate_inventory_list()
{
    QString out = " ";
    if (list->size() == 0) {
        empty();
    }

    for (int row = 0; row < list->size(); row++) {
        QModelIndex index = model->index(row, 0, QModelIndex());
        model->setData(index, out.fromStdString((*list)[row].get_item_name()));

        QModelIndex i2 = model->index(row, 1, QModelIndex());
        model->setData(i2, (*list)[row].get_ID());

        QModelIndex i3 = model->index(row, 2, QModelIndex());
        model->setData(i3, 0);

        QModelIndex i4 = model->index(row, 3, QModelIndex());
        model->setData(i4, (*list)[row].get_quantity());

        QModelIndex i5 = model->index(row, 4, QModelIndex());
        model->setData(i5, (*list)[row].get_price());

        QModelIndex i6 = model->index(row, 5, QModelIndex());
        model->setData(i6, 0);
    }
}
