#include "item.h"

/***********************************************
 * Item()
 *
 * initializing a default constructor member
 * values to 0
 * ---------------------------------------------
 *      Parameters: none
 * ---------------------------------------------
 *      Returns: none
************************************************/
Item::Item()
{
    _ID = 0;
    _quantity = 0;
    _price = 0;
}

/***********************************************
 * Item(int, int, double)
 *
 * initializing a CTOR to given parameters
 * ---------------------------------------------
 *      Parameters: id (int), quantity (int),
 *      price(double)
 * ---------------------------------------------
 *      Returns: none
************************************************/
Item::Item(int id, int quantity, double price)
{
    _ID = id;
    _quantity = quantity;
    _price = price;
}

/***********************************************
 * Item(string, int, double)
 *
 * initializing a constructor with given parameters
 * ---------------------------------------------
 *      Parameters: n (string), q (int),
 *      price (double)
 * ---------------------------------------------
 *      Returns: none
************************************************/
Item::Item(string n, int q, double p)
{
    _name = n;
    _quantity = q;
    _price = p;
}

/***********************************************
 * void set_item_number(int)
 *
 * Mutator; set a new item number to member value
 * ---------------------------------------------
 *      Parameters: int
 * ---------------------------------------------
 *      Returns: none
************************************************/
void Item::set_item_number(int id)
{
    _ID = id;
}

/***********************************************
 * void set_quantity(int)
 *
 * Mutator; set a new quantity value to member value
 * ---------------------------------------------
 *      Parameters: int
 * ---------------------------------------------
 *      Returns: none
************************************************/
void Item::set_quantity(int quan)
{
    _quantity = quan;
}

/***********************************************
 * void set_price(double)
 *
 * Mutator; set a new price for an item
 * ---------------------------------------------
 *      Parameters: int
 * ---------------------------------------------
 *      Returns: none
************************************************/
void Item::set_price(double p)
{
    _price = p;
}

/***********************************************
 * int get_quantity()
 *
 * Accessor; returns the member value _quantity
 * ---------------------------------------------
 *      Parameters: none
 * ---------------------------------------------
 *      Returns: int
************************************************/
int Item::get_quantity() const
{
    return _quantity;
}

/***********************************************
 * double get_price()
 *
 * Accessor; returns the member value _price
 * ---------------------------------------------
 *      Parameters: none
 * ---------------------------------------------
 *      Returns: double
************************************************/
double Item::get_price() const
{
    return _price;
}

/***********************************************
 * int get_ID()
 *
 * Accessor; returns the member value _ID
 * ---------------------------------------------
 *      Parameters: none
 * ---------------------------------------------
 *      Returns: int
************************************************/
int Item::get_ID() const
{
    return _ID;
}

/***********************************************
 * double get_total()
 *
 * Accessor; returns total price for total quantity
 * of items multiplied by price
 * ---------------------------------------------
 *      Parameters: none
 * ---------------------------------------------
 *      Returns: double
************************************************/
double Item::get_total() const
{
    return _price * _quantity;
}

/***********************************************
 * string get_item_name()
 *
 * Accessor; returns the member value _name
 * ---------------------------------------------
 *      Parameters: none
 * ---------------------------------------------
 *      Returns: string
************************************************/
string Item::get_item_name() const
{
    return _name;
}


bool operator ==(const Item& i1, const Item& i2)
{
    return (i1 == i2);
}
