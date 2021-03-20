#include "inventory.h"

/***************************************************
 * inventory()
 *
 * CTOR; initializes an empty CTOR
 * -------------------------------------------------
 *  Parameters: none
 * -------------------------------------------------
 *  Returns: none
****************************************************/
inventory::inventory()
{
    item = 0;
    _size = 0;
    _capacity = 0;
}

/***************************************************
 * inventory(int size)
 *
 * CTOR; This will initialize CTOR to parameter size
 * -------------------------------------------------
 *  Parameters: (int) size
 * -------------------------------------------------
 *  Returns: none
****************************************************/
inventory::inventory(int size)
{
    _size = size;
    _capacity = size + 1;
    item = new Item[size];
}

/***************************************************
 * inventory(int size, const Item& it)
 *
 * CTOR;
 * -------------------------------------------------
 *  Parameters: none
 * -------------------------------------------------
 *  Returns: none
****************************************************/
inventory::inventory(int size, const Item& it)
{
    _size = size;
    _capacity = size + 1;
    item = new Item[size];
    for (int i = 0; i < size; i++) {
        item[i] = it;
    }
}

/***************************************************
 * inventory(const inventory& i)
 *
 * Copy Constructor
 * -------------------------------------------------
 *  Parameters: inventory object
 * -------------------------------------------------
 *  Returns: none
****************************************************/
inventory::inventory(const inventory& i)
{
    _size = i._size;
    _capacity = i._capacity;
    item = new Item[_size];
    for (int u = 0; u < _size; u++) {
        item[u] = i.item[u];
    }
}

/***************************************************
 * ~inventory()
 *
 * Destructor; deallocates item attribute
 * -------------------------------------------------
 *  Parameters: none
 * -------------------------------------------------
 *  Returns: none
****************************************************/
inventory::~inventory()
{
    delete[] item;
}

/***************************************************
 * int getItemNumber()
 *
 * Accessor: This method returns item number from
 * Item class.
 * -------------------------------------------------
 *   Parameter: none
 * -------------------------------------------------
 *   Returns: int
****************************************************/
int inventory::getItemNumber()
{
    return item->get_ID();
}

/***************************************************
 * int getItemQuantity()
 *
 * Accessor: This method returns the quantity from
 * Item class.
 * -------------------------------------------------
 *   Parameter: none
 * -------------------------------------------------
 *   Returns: int
****************************************************/
int inventory::getItemQuantity()
{
    return item->get_quantity();
}

/***************************************************
 * int getItemName()
 *
 * Accessor; This method returns the item name from
 * the Item class.
 * -------------------------------------------------
 *   Parameter: none
 * -------------------------------------------------
 *   Returns: string
****************************************************/
string inventory::getItemName()
{
    return item->get_item_name();
}

/***************************************************
 * int capacity() const
 *
 * Accessor: returns member _capacity
 * -------------------------------------------------
 *   Parameter: none
 * -------------------------------------------------
 *   Returns: int
****************************************************/
int inventory::capacity() const
{
    return _capacity;
}

/***************************************************
 * int size() const
 *
 * Accessor: returns member _size
 * -------------------------------------------------
 *   Parameter: none
 * -------------------------------------------------
 *   Returns: int
****************************************************/
int inventory::size() const
{
    return _size;
}

/***************************************************
 * bool empty() const
 *
 * Accessor; check if the item is empty
 * -------------------------------------------------
 *   Parameter: none
 * -------------------------------------------------
 *   Returns: true (if ==0), if not returns false
****************************************************/
bool inventory::empty() const
{
    return (item == 0);
}

/***************************************************
 * void push_back(const Item& it)
 *
 * Mutator; This method will add the parameter to
 * end of object.
 * -------------------------------------------------
 *   Parameter: item& it (item object)
 * -------------------------------------------------
 *   Returns: nothing
****************************************************/
void inventory::push_back(const Item &it)
{
    if (_size > _capacity) {
        reallocate(_capacity + 5);
        item[_size++] = it;
    }
}

/***************************************************
 * void pop_back()
 *
 * Mutator; This method will delete the last item
 * of array
 * -------------------------------------------------
 *   Parameter: none
 * -------------------------------------------------
 *   Returns: nothing
****************************************************/
void inventory::pop_back()
{
    _size--;
}

/***************************************************
 * int search(const Item& it) const
 *
 * Accessor; This method will go through the item
 * array and return the index if finds the object.
 * -------------------------------------------------
 *   Parameter: item object to search for
 * -------------------------------------------------
 *   Returns: -1 if cannot find
****************************************************/
int inventory::search(const Item& t) const
{
    for (int i = 0; i < _size; i++) {
        if (item[i] == t) {
            return i;
        }
    }
    return -1;
}

/***************************************************
 * void remove(const Item& it)
 *
 * Mutator; removes an item object from item array
 * -------------------------------------------------
 *   Parameter: item object
 * -------------------------------------------------
 *   Returns: nothing
****************************************************/
void inventory::remove(const Item &it)
{
    int index;
    index = search(it);

    if (index == -1) {
        return;
    }

    for (int i = index; i < _size - 1; i++) {
        item[i] = item[i+1];
    }

    _size--;
}

/***************************************************
 * void reallocate(int cap)
 *
 * Mutator; this method will set capacity of container
 * to parameter, size remains the same
 * -------------------------------------------------
 *   Pre-conditions: size > capacity
 * -------------------------------------------------
 *   Parameter: cap (int)
 * -------------------------------------------------
 *   Returns: nothing
****************************************************/
void inventory::reallocate(int cap)
{
    if (item == 0) {
        _size = 0;
        _capacity = 1;
    }
    Item* new_list = new Item[cap];
    assert(new_list);
    copy(item, item + _size, new_list);
    _capacity = cap;
    delete[] item;
    item = new_list;
}

/***************************************************
 * void resize(int size)
 *
 * Mutator; set size and capacity of item container
 * to given parameter
 * -------------------------------------------------
 *   Pre-conditions: size > 0
 * -------------------------------------------------
 *   Parameter: size (int)
 * -------------------------------------------------
 *   Returns: nothing
****************************************************/
void inventory::resize(int size)
{
    reallocate(size);
    _size = size;
}

/***************************************************
 * void clear()
 *
 * Mutator; This method will clear everything in item
 * array.
 * -------------------------------------------------
 *   Parameter: none
 * -------------------------------------------------
 *   Returns: nothing
****************************************************/
void inventory::clear()
{
    delete[] item;

    item = nullptr;
    _size = 0;
}

/***************************************************
 * void set_size(int size)
 *
 * Mutator; set size of object to parameter
 * -------------------------------------------------
 *   Parameter: size (int) for item array
 * -------------------------------------------------
 *   Returns: nothing
****************************************************/
void inventory::set_size(int size)
{
    _size = size;
}

/***************************************************
 * void set_capacity(int cap)
 *
 * Mutator; set capacity of object to parameter
 * -------------------------------------------------
 *   Parameter: capacity (int) for item array
 * -------------------------------------------------
 *   Returns: nothing
****************************************************/
void inventory::set_capacity(int cap)
{
    _capacity = cap;
}


/***************************************************
 * Item& operator [](int index)
 *
 * Accessor, this function will return item found at
 * the given index
 * -------------------------------------------------
 *   Parameter: index (int)
 * -------------------------------------------------
 *   Returns: item object at parameter index
****************************************************/
Item& inventory::operator [](int index) const
{
    assert(index >= 0 && index < size());
    return item[index];
}

/***************************************************
 * inventory operator +=(const Item& item)
 *
 * Mutator; method will append Item array by adding
 * item object.
 * -------------------------------------------------
 *   Parameter: Item object
 * -------------------------------------------------
 *   Returns: reference to this object
****************************************************/
inventory& inventory::operator+=(const Item &item)
{
    push_back(item);
    return *this;
}

/***************************************************
 * inventory operator =(const Item& item)
 *
 * Mutator; method will override the assignment
 * operator
 * -------------------------------------------------
 *   Parameter: inventory object to assign to old
 *   memebers
 * -------------------------------------------------
 *   Returns: reference to this object
****************************************************/
inventory& inventory::operator=(const inventory &it)
{
    delete[] item;

    _size = it._size;
    _capacity = it._capacity;
    item = new Item[_size];
    for (int i = 0; i<_size; i++) {
        item[i] = it.item[i];
    }
    return *this;
}



