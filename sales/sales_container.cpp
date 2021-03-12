#include <algorithm>

#include "sales_container.h"

// ==============initialize===============
sales_container::sales_container() {
    my_capacity = 0;
    my_size = 0;
    my_list = 0;
}


sales_container::sales_container(unsigned int size) {
    my_capacity = size;
    my_size = size;
    my_list = new sales[size];
}


sales_container::sales_container(unsigned int size, const sales& initial) {
    my_size = size;
    my_capacity = size;
    my_list = new sales[size];
    for (int i=0; i<size; i++) {
        my_list[i] = initial;
    }
}


// ======================================
// BIG THREE
// ======================================

sales_container::sales_container(const sales_container& v) {
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    my_list = new sales[my_size];
    for (int i=0; i<my_size; i++) {
        my_list[i] = v.my_list[i];
    }
}


sales_container& sales_container::operator =(const sales_container& v) {
    delete[] my_list;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    my_list = new sales[my_size];
    for (int i=0; i<my_size; i++) {
        my_list[i] = v.my_list[i];
    }
    return *this;
}


sales_container::~sales_container() {
    delete[] my_list;
}


// ====================================


sales& sales_container::operator[](unsigned int index) {
    return my_list[index];
}

sales_container& sales_container:: operator +=(const sales& item) {
    push_back(item);
}

sales& sales_container::sales_container::front() {
    return my_list[0];
}

sales& sales_container::sales_container::back() {
    return my_list[my_size - 1];
}

void sales_container::push_back(const sales& v) {
    if (my_size >= my_capacity) {
        reserve(my_capacity + 5);
        my_list[my_size++] = v;
    }
}

void sales_container::pop_back() {
    my_size--;
}


unsigned int sales_container::size() const {
    return my_size;
}


unsigned int sales_container::capacity() const {
    return my_capacity;
}


void sales_container::set_size(int size) {
    my_size = size;
}


void sales_container::set_capacity(int capacity) {
    my_capacity = capacity;
}


void sales_container::reserve(unsigned int capacity) {
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

void sales_container::resize(unsigned int size) {
    // reallocate
    reserve(size);
    my_size = size;
}

void sales_container::clear() {
    my_size = 0;
    my_capacity = 0;
}
