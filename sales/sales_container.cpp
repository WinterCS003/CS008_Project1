#include <algorithm>

#include "sales_container.h"

/****************************************************************
 * sales_container();
 *   Constructor; Initialize an empty class
 *   Parameters: none
 *   Return: none
 ***************************************************************/
sales_container::sales_container()
{
    my_capacity = 0;
    my_size = 0;
    my_list = 0;
}

/****************************************************************
 * sales_container(unsigned int size);
 *   Constructor; Initialize a sales_container to parameter size
 *   Parameters: size (unsigned int) // IN - size of new container
 *   Return: none
 ***************************************************************/
sales_container::sales_container(unsigned int size) // IN - size of new container
{
    my_capacity = size;
    my_size = size;
    my_list = new sales[size];
}

/****************************************************************
 * sales_container(unsigned int size, const sales& initial);
 *   Constructor; Initialize class to a new parameter sales
 *                of passed size
 *   Parameters: size (unsigned int) // IN - size of new container
 *               initial (sales&) // IN - first sale object
 *   Return: none
 ***************************************************************/
sales_container::sales_container(unsigned int size, // IN - size of new container
                                 const sales& initial) // IN - first sale object
{
    my_size = size;
    my_capacity = size;
    my_list = new sales[size];
    for (unsigned int i = 0; i < size; i++) {
        my_list[i] = initial;
    }
}

/****************************************************************
 * sales_container(const sales_container& s);
 *   Constructor; copy constructor
 *   Parameters: s (sales_container&) // IN - parameter to copy
 *                                            from
 *   Return: none
 ***************************************************************/
sales_container::sales_container(const sales_container& s) // IN - parameter to copy from
{
    my_size = s.my_size;
    my_capacity = s.my_capacity;
    my_list = new sales[my_size];
    for (unsigned int i = 0; i < my_size; i++) {
        my_list[i] = s.my_list[i];
    }
}

/****************************************************************
 * ~sales_container();
 *   Destructor; deallocates my_list attribute
 *   Parameters: none
 *   Return: none
 ***************************************************************/
sales_container::~sales_container()
{
    delete[] my_list;
}

/****************************************************************
 * unsigned int capacity() const;
 *
 *   Accessor; This method will return the allocated size of the
 *   container
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: my_capacity (unsigned int) - total allocated size
 *                                        of this object
 ***************************************************************/
unsigned int sales_container::capacity() const
{
    return my_capacity;
}
/****************************************************************
 * unsigned int size() const;
 *
 *   Accessor; This method will return the size of the container
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: my_size (unsigned int) - number of elements in the
 *                                    object
 ***************************************************************/
unsigned int sales_container::size() const
{
    return my_size;
}

/****************************************************************
 * bool empty() const;
 *
 *   Accessor; This method will return true if the container is
 *   empty.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: bool - true if container is empty, false otherwise
 ***************************************************************/
bool sales_container::empty() const
{
    return my_capacity == 0;
}

/****************************************************************
 * sales& operator[](unsigned int index) const;
 *
 *   Accessor; This method will return the sales found at the
 *   index passed by the parameter
 * --------------------------------------------------------------
 *   Parameters: index (unsigned int) // IN - index of sales
 *                                            object
 * --------------------------------------------------------------
 *   Return: sales (sales&) - sales object at parameter index
 ***************************************************************/
sales& sales_container::operator[](unsigned int index) const // IN - index of sales
                                                             // object
{
    return my_list[index];
}

/****************************************************************
 * double getTotalRevenue() const;
 *
 *   Accessor; This method will return the total revenue of all
 *   sales in the container
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: total revenue (double) - total revenue of all sales
 ***************************************************************/
double sales_container::getTotalRevenue() const
{
    if(my_size == 0)
    {
        return 0.0;
    }

    double output;
    output = 0.0;
    for(unsigned int i = 0; i < my_size; i++)
    {
        output += my_list[i].getRevenue();
    }

    return output;
}

/****************************************************************
 * int find(const sales& s) const;
 *
 *   Accessor; This method will return the index of the parameter
 * --------------------------------------------------------------
 *   Parameters: s (sales&) // IN - sales to search for
 * --------------------------------------------------------------
 *   Return: index (int) - index of the sales parameter to find
 *                         -1 is returned if parameter not found
 ***************************************************************/
int sales_container::find(const sales& s) const // IN - sales to search for
{
    for(unsigned int i = 0; i < my_size; i++)
    {
        if(my_list[i] == s)
        {
            return i;
        }
    }

    return -1;
}

/*******************************************************************
 * void push_back(const sales& value);
 *
 *   Mutator; This method will add the parameter to the end of the
 *   object
 *------------------------------------------------------------------
 *   Parameter: value (sales&) // IN – sales to add to end of object
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void sales_container::push_back(const sales& s) // IN – sales to add to end of object
{
    if (my_size >= my_capacity) {
        reserve(my_capacity + 5);
    }
    my_list[my_size++] = s;
}

/*******************************************************************
 * void pop_back();
 *
 *   Mutator; This method will delete the last sales object of this
 *   object
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void sales_container::pop_back()
{
    my_size--;
}

/*******************************************************************
 * void erase(const sales& s);
 *
 *   Mutator; This method will erase the first instance of the
 *   parameter sales
 *------------------------------------------------------------------
 *   Parameter: s (sales&) // IN – sales to erase from object
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void sales_container::erase(const sales& s) // IN – sales to erase from object
{
    int index = find(s);
    if(index == -1)
    {
        return;
    }

    for(unsigned int i = index; i < my_size-1; i++)
    {
        my_list[i] = my_list[i+1];
    }

    my_size--;
}

/*******************************************************************
 * void set_size(int size);
 *
 *   Mutator; This method will set the size of the object to the
 *   parameter
 *------------------------------------------------------------------
 *   Preconditions: size > 0
 *   Parameter: size (int) // IN – new size of the object
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void sales_container::set_size(int size) // IN – new size of the object
{
    my_size = size;
}

/*******************************************************************
 * void set_capacity(int capacity);
 *
 *   Mutator; This method will set the capacity of this object to
 *   the parameter
 *------------------------------------------------------------------
 *   Preconditions: capacity > 0
 *
 *   Parameter: capacity (int) // IN – new capacity for the object
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void sales_container::set_capacity(int capacity) // IN – new capacity for the object
{
    my_capacity = capacity;
}

/*******************************************************************
 * sales_container& operator+=(const sales& item);
 *
 *   Mutator; This method will append the sales from the parameter
 *   into this object
 *------------------------------------------------------------------
 *   Parameter: item (sales&) // IN – new sales to add to object
 *------------------------------------------------------------------
 *   Return: reference to this object
 *******************************************************************/
sales_container& sales_container::operator+=(const sales& item) // IN – new sales to add to object
{
    push_back(item);
    return *this;
}

/*******************************************************************
 * sales_container& operator=(const sales_container& s);
 *
 *   Mutator; This method will override the assignment operator and
 *   will set this object to be the same as the parameter
 *------------------------------------------------------------------
 *   Parameter: s (sales_container&) // IN – sales container to
 *                                           assign from
 *------------------------------------------------------------------
 *   Return: a reference to this object is returned
 *******************************************************************/
sales_container& sales_container::operator=(const sales_container& s) // IN – sales container to
                                                                      // assign from
{
    delete[] my_list;
    my_size = s.my_size;
    my_capacity = s.my_capacity;
    my_list = new sales[my_size];
    for (unsigned int i=0; i<my_size; i++) {
        my_list[i] = s.my_list[i];
    }
    return *this;
}

/*******************************************************************
 * void reserve(unsigned int capacity);
 *
 *   Mutator; This method will set the capacity of the container to
 *   the parameter, size will remain the same
 *------------------------------------------------------------------
 *   Preconditions: capacity > my_size
 *
 *   Parameter: capacity (unsigned int) // IN – new capacity
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void sales_container::reserve(unsigned int capacity) // IN – new capacity
{
    // allocate
    if (my_list == 0) {
        my_size = 0;
        my_capacity = 0;
    }
    sales* my_list = new sales[capacity];

    std::copy(this->my_list, this->my_list+my_size, my_list);

    my_capacity = capacity;
    delete [] this->my_list;
    this->my_list = my_list;
}

/*******************************************************************
 * void resize(unsigned int size);
 *
 *   Mutator; This method will set the size and capacity of the
 *   container to the parameter
 *------------------------------------------------------------------
 *   Preconditions: size > 0
 *
 *   Parameter: size (unsigned int) // IN – new size of container
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void sales_container::resize(unsigned int size) // IN – new size of container
{
    // reallocate
    reserve(size);
    my_size = size;
}

/*******************************************************************
 * void clear();
 *
 *   Mutator; This method will erase all elements in the object
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/
void sales_container::clear()
{
    my_size = 0;
    my_capacity = 0;
}
