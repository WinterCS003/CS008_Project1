#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;


class Item
{
public:
    // CONSTRUCTORS
    Item();
    Item(int, int, double);
    Item(string, int, double);

    // MUTATORS
    void set_item_number(int id);
    void set_quantity(int quan);
    void set_price(double p);

    // ACCESSORS
    int get_quantity() const;
    double get_price() const;
    int get_ID() const;
    double get_total() const;
    string get_item_name() const;

    friend bool operator ==(const Item& i1, const Item& i2);

private:
    int _ID;
    int _quantity;
    double _price;
    string _name;
};

/********************************************
 * Item class
 *      - this class represents item object.
 *
 * CONSTRUCTORS
 * ------------------------------------------
 * Item()
 *      - Parameters: None
 *      - Returns: Nothing
 *
 * Item(int, int, double)
 *      - Parameters: int id, int quantity,
 *          double price
 *      - Returns: Nothing
 *
 * ACCESSORS
 * ------------------------------------------
 * string get_item_name()
 *
 * int get_quantity()
 *
 * int get_ID()
 *
 * double get_price()
 *
 *
 * MUTATORS
 * ------------------------------------------
 * void set_quantity(int)
 *
 * void set_price(double)
 *
 *
*********************************************/



#endif // ITEM_H
