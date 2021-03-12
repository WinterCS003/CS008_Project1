#ifndef VECTOR_H
#define VECTOR_H

// ERROR CODE:
const int NO_ERROR = 0;
const int INVALID = 1;
#include <iostream>
#include <cassert>

using namespace std;

template <class T>
class vector
{
public:
    vector();
    vector(unsigned int size);
    vector(unsigned int size, const T& initial);

    // Big three:
    vector(const vector<T>& v); // copy constructor
    vector<T>& operator =(const vector<T>& v);
    ~vector();  // destructor

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    T& front();
    T& back();
    void push_back(const T& value);
    void pop_back();

    void set_size(int size);
    void set_capacity(int capacity);

    friend ostream& operator <<(ostream& outs, const vector<T>& _a) {
        for (int i=0; i<_a.my_size; i++) {
            outs << _a.my_list[i];
            if (i < _a.my_size - 1) outs << ", ";
        }
        return outs;
    }

    friend istream& operator >>(istream& ins, const vector<T>& _a) {
        const int MAX = 100;
        _a.set_capacity(MAX);
        T* value[MAX+1];
        ins.getline(value, MAX);
        return ins;
    }

    friend bool operator ==(const vector& v1, const vector& v2) {
        return (v1._count == v2._count);
    }

    T& operator[](unsigned int index);

    vector& operator + (const T& item);
    vector& operator += (const T& item);

    void reserve(unsigned int capacity);
    void resize(unsigned int size);

    // error handling :
    int check_error();
    int error();
    void clear();
    string error_description();

private:
    // member variables: my_size and my_capacity
    unsigned int my_size;
    unsigned int my_capacity;
    T* my_list;
    int _error = check_error();
};


// ==============initialize===============
template <class T>
vector<T>::vector() {
    my_capacity = 0;
    my_size = 0;
    my_list = 0;
}

template <class T>
vector<T>::vector(unsigned int size) {
    my_capacity = size;
    my_size = size;
    my_list = new T[size];
}

template <class T>
vector<T>::vector(unsigned int size, const T& initial) {
    my_size = size;
    my_capacity = size;
    my_list = new T[size];
    for (int i=0; i<size; i++) {
        my_list[i] = initial;
    }
}


// ======================================
// BIG THREE
// ======================================
template <class T>
vector<T>::vector(const vector<T>& v) {
    const bool debug = false;
    if (debug) cout<<"Copy CTOR: "<<endl;

    my_size = v.my_size;
    my_capacity = v.my_capacity;
    my_list = new T[my_size];
    for (int i=0; i<my_size; i++) {
        my_list[i] = v.my_list[i];
    }
}

template <class T>
vector<T>& vector<T>::operator =(const vector<T>& v) {
    const bool debug = false;
    if (debug) cout<<"assignment operator = : "<<endl;

    delete[] my_list;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    my_list = new T[my_size];
    for (int i=0; i<my_size; i++) {
        my_list[i] = v.my_list[i];
    }
    return *this;
}

template <class T>
vector<T>::~vector<T>() {
    const bool debug = false;
    if (debug) cout<<"~vector : "<<endl;
    delete[] my_list;
}


// ====================================

template <class T>
T& vector<T>::operator[](unsigned int index) {
    return my_list[index];
}

template <class T>
vector<T>& vector<T>::operator +(const T& item) {
    my_list[my_size] + item;
}

template <class T>
vector<T>& vector<T>:: operator +=(const T& item) {
    push_back(item);
    _error = check_error();
}

template <class T>
T& vector<T>::vector<T>::front() {
    return my_list[0];
}

template <class T>
T& vector<T>::vector<T>::back() {
    return my_list[my_size - 1];
}

template <class T>
void vector<T>::push_back(const T& v) {
    if (my_size >= my_capacity) {
        reserve(my_capacity + 5);
        my_list[my_size++] = v;
    }
}

template <class T>
void vector<T>::pop_back() {
    my_size--;
    _error = check_error();
}

template <class T>
unsigned int vector<T>::size() const {
    return my_size;
}

template <class T>
unsigned int vector<T>::capacity() const {
    return my_capacity;
}

template <class T>
void vector<T>::set_size(int size) {
    my_size = size;
}

template <class T>
void vector<T>::set_capacity(int capacity) {
    my_capacity = capacity;
}

template <class T>
void vector<T>::reserve(unsigned int capacity) {
    // allocate
    if (my_list == 0) {
        my_size = 0;
        my_capacity = 0;
    }
    T* my_list = new T[capacity];
    assert(my_list);
    copy(my_list, my_list+my_size, my_list);
    my_capacity = capacity;
    delete[] my_list;
    my_list = my_list;
}

template <class T>
void vector<T>::resize(unsigned int size) {
    // reallocate
    reserve(size);
    my_size = size;
}


// Error Handling:
template <typename T>
int vector<T>::check_error() {
    if (my_size >= my_capacity) {
        return INVALID;
    }
    return NO_ERROR;
}

template <typename T>
int vector<T>::error() {
    return _error;
}

template <typename T>
void vector<T>::clear() {
    my_size = 0;
    my_capacity = 0;
}

template <typename T>
string vector<T>::error_description() {
    switch(_error){
    case INVALID:   return "INVALID";
    case NO_ERROR:  return "NO ERROR";
    default:        return "UNKNOWN ERROR";
    }
};

#endif // VECTOR_H
