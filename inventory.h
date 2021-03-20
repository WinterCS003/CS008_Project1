#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include <cassert>

// Item container class

class inventory
{
public:
    // CONSTRUCTORS & DESTRUCTOR
    inventory();                            // default CTOR
    inventory(int size);                    // IN: CTOR with new size
    inventory(int size, const Item& i);

    inventory(const inventory& i);          // copy CTOR
    ~inventory();                           // destructor

    // ACCESSORS
    int getItemNumber();                    // OUT: return item number
    int getItemQuantity();                  // OUT: return item quantity
    string getItemName();                   // OUT: return item name
    int capacity() const;                   // OUT: return _capacity
    int size() const;                       // OUT: return _size
    bool empty() const;                     // check if array is empty

    int search(const Item& t) const;       // searches for an item
    Item& operator [](int index) const;

    // MUTATORS
    void push_back(const Item& it);         // push back item to end of array
    void pop_back();                        // pops back last item of array
    void remove(const Item& it);            // remove an item
    void reallocate(int cap);               // reallocates new capacity
    void resize(int size);                  // resizes new size
    void clear();                           // clears entire array
    void set_size(int size);
    void set_capacity(int cap);

    inventory& operator +=(const Item& item);
    inventory& operator =(const inventory& i);  // assignment operator =

    void PrintReportToScreen();
    void PrintReportToText();

private:
    Item *item;     // IN: array of items
    int _size;      // IN: size of container
    int _capacity;  // IN: allocated size of item container
};

#endif // INVENTORY_H


/********************************************
 * CONSTRUCTORS & DESTRUCTOR
 *
 * inventory()
 *
 * inventory(const inventory& i)
 *
 * ~inventory()
 *
*********************************************/

/********************************************
 * MUTATORS
 *
 * void push_back(const inventory& item)
 *
 * void pop_back()
 *
 * void remove(const inventory& item)
 *
 * void reallocate(int cap)
 *
 * void resize(int size)
 *
 * void clear()
 *
 * Item& operator [](int index) const
 *
 * inventory& operator +=(const inventory& item)
 *
 * inventory& operator =(const inventory& item)
 *
 * void PrintReportToScreen()
 *
 * void PrintReportToText()
 *
*********************************************/

/********************************************
 * ACCESSORS
 *
 * int getItemNumber()
 *
 * int getItemQuantity()
 *
 * int capacity() const
 *
 * int size() const
 *
 * bool empty() const
 *
*********************************************/



