#include "inventorytracker.h"
#include "ui_inventorytracker.h"

/****************************************************************
 * InventoryTracker(QWidget *parent = 0);
 *   Constructor; Initialize class attributes to null
 *   Parameters: parent (QWidget*) // IN - pointer to widget
 *   Return: none
 ***************************************************************/
InventoryTracker::InventoryTracker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InventoryTracker)
{
    ui->setupUi(this);
}

/****************************************************************
 * InventoryTracker(QWidget *parent,
 *                  inventory* iv,
 *                  sales_container* sales);
 *   Constructor; Initialize class attributes to parameters
 *   Parameters: QWidget *parent, // IN - pointer to widget window
 *               inventory* iv, // IN - inventory pointer
 *               sales_container* sales); // IN - sales container pointer
 *   Return: none
 ***************************************************************/
InventoryTracker::InventoryTracker(QWidget *parent, inventory* iv, sales_container* sales)
    : QDialog(parent), ui(new Ui::InventoryTracker)
{
    ui->setupUi(this);
    ui->title->show();
    ui->exit->show();
    this->list = iv;
    this->all_sales = sales;

    QStandardItem *name = new QStandardItem;
    name->setText("Item Name");
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
    model = new QStandardItemModel(0, 5, this);
    model->setHorizontalHeaderItem(0, name);
    model->setHorizontalHeaderItem(1, sold);
    model->setHorizontalHeaderItem(2, stock);
    model->setHorizontalHeaderItem(3, price);
    model->setHorizontalHeaderItem(4, total);

    // attach model to view
    ui->table->setModel(model);
    generate_inventory_list();
    ui->table->show();
}

/****************************************************************
 * ~InventoryTracker();
 *   Destructor; Deletes ui pointer
 *   Parameters: none
 *   Return: none
 ***************************************************************/
InventoryTracker::~InventoryTracker()
{
    delete ui;
}

/****************************************************************
 * void on_exit_clicked();
 *
 *   Accessor; This method will close the window
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
void InventoryTracker::on_exit_clicked()
{
    ui->~InventoryTracker();
    InventoryTracker::close();
}

/****************************************************************
 * void empty();
 *
 *   Accessor; This method will notify the user if the
 *   inventory is empty
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
void InventoryTracker::empty()
{
    ui->text->setText("Inventory List = 0 ");
}

/****************************************************************
 void generate_inventory_list();
 *
 *   Accessor; This method will create a report of all items
 *   in stock and how many were sold
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is printed
 ***************************************************************/
void InventoryTracker::generate_inventory_list()
{
    QString out = " ";
    if (list->size() == 0) {
        empty();
    }

    sales_container unique_sales;
    for(size_t i = 0; i < all_sales->size(); i++)
    {
        int index = unique_sales.find((*all_sales)[i].getItem());
        if(index == -1)
        {
            unique_sales.push_back((*all_sales)[i]);
        }
        else
        {
            int s1 = unique_sales[index].getQuantity();
            int s2 = (*all_sales)[i].getQuantity();
            unique_sales[index].setQuantity(s1 + s2);
        }
    }

    int sold = 0;
    for (int row = 0; row < list->size(); row++) {
        int i = unique_sales.find((*list)[row].get_item_name());
        i != -1 ? sold = unique_sales[i].getQuantity() : sold = 0;
        double total = std::ceil(sold*(*list)[row].get_price()*100.0)/100.0;

        model->insertRow(row, QModelIndex());
        QModelIndex index = model->index(row, 0, QModelIndex());
        model->setData(index, out.fromStdString((*list)[row].get_item_name()));

        QModelIndex i2 = model->index(row, 1, QModelIndex());
        model->setData(i2, sold);

        QModelIndex i3 = model->index(row, 2, QModelIndex());
        model->setData(i3, (*list)[row].get_quantity());

        QModelIndex i4 = model->index(row, 3, QModelIndex());
        model->setData(i4, (*list)[row].get_price());

        QModelIndex i5 = model->index(row, 4, QModelIndex());
        model->setData(i5, total);
    }

    model->sort(0);
}
