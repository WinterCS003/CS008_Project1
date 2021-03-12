#ifndef sales_container_H
#define sales_container_H

#include "sales.h"

class sales_container
{
public:
    sales_container();
    sales_container(unsigned int size);
    sales_container(unsigned int size, const sales& initial);

    // Big three:
    sales_container(const sales_container& v); // copy constructor
    sales_container& operator =(const sales_container& v);
    ~sales_container();  // destructor

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    sales& front();
    sales& back();
    void push_back(const sales& value);
    void pop_back();

    void set_size(int size);
    void set_capacity(int capacity);

    sales& operator[](unsigned int index);

    sales_container& operator += (const sales& item);

    void reserve(unsigned int capacity);
    void resize(unsigned int size);
    void clear();

private:
    // member variables: my_size and my_capacity
    unsigned int my_size;
    unsigned int my_capacity;
    sales* my_list;
};

#endif // sales_container_H
