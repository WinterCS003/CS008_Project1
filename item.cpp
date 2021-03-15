#include "item.h"

Item::Item()
{
    _ID = 0;
    _quantity = 0;
    _price = 0;
}

Item::Item(int id, int quantity, double price)
{
    _ID = id;
    _quantity = quantity;
    _price = price;
}

void Item::set_item_number(int id)
{
    _ID = id;
}

void Item::set_quantity(int quan)
{
    _quantity = quan;
}

void Item::set_price(double p)
{
    _price = p;
}

int Item::get_quantity() const
{
    return _quantity;
}

double Item::get_price() const
{
    return _price;
}

int Item::get_ID() const
{
    return _ID;
}

double Item::get_total() const
{
    return _price * _quantity;
}



