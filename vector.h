#ifndef VECTOR_H
#define VECTOR_H

// ERROR CODE:
const int NO_ERROR = 0;
const int INVALID = 1;
#include <iostream>
#include <cassert>
using namespace std;

void test_vector();

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
}



//=============================================
// test function
// ============================================
void test_vector() {
    vector<int> v;
    v.reserve(3);
    assert(v.capacity() == 3);

    cout<<"========string========"<<endl;
    vector<string> v1(3);
    assert(v1.capacity() == 3);
    assert(v1.size() == 3);
    assert(v1[0] == "");
    assert(v1[1] == "");
    cout<<"*** v1[0], v1[1], and v1[2] print: , , , "<<endl;
    cout<<"v1: "<<v1[0]<<" , "<<v1[1]<<" , "<<v1[2]<<" , ";
    cout<<endl;

    cout<<"========int========"<<endl;
    vector<int> v2(3, 8);   // v2[0]=8
    assert(v2[0] == 8);
    v2[1] = 5;
    v2[2] = 10;
    cout<<"v2: "<<v2[0]<<" , "<<v2[1]<<" , "<<v2[2]<<" , ";
    cout<<endl;

    cout<<"========char========"<<endl;
    vector<char> v3(3);
    assert(v3.capacity() == 3);
    assert(v3.size() == 3);
    v3[0] = 'A';
    v3[1] = 'B';
    v3[2] = 'C';
    cout<<"v3: "<<v3[0]<<" , "<<v3[1]<<" , "<<v3[2]<<" , ";
    cout<<endl;

    cout<<"========string========"<<endl;
    vector<string> v4(3);
    assert(v4.capacity() == 3);
    assert(v4.size() == 3);
    v4[0] = "hello";
    v4[1] = "goodbye";
    cout<<"v4: "<<v4[0]<<" , "<<v4[1]<<" , ";
    v4[2] = "cs";
    cout<<v4[2]<<" , ";
    cout<<endl;

    cout<<"========double========"<<endl;
    vector<double> v5(10);
    assert(v5.capacity() == 10);
    assert(v5.size() == 10);
    v5[0] = 1.5;
    v5[1] = 10.1;
    v5[2] = 5.3;
    cout<<"v5: "<<v5[0]<<" , "<<v5[1]<<" , "<<v5[2]<<" , ";
    v5[3] = 8.9;
    cout<<v5[3]<<" , ";
    v5[4] = 12.2;
    v5[5] = 13.5;
    v5[6] = 17.8;
    cout<<v5[4]<<" , "<<v5[5]<<" , "<<v5[6]<<" , ";
    cout<<"\n\n";

    cout<<"pop_back last element of: v2, v3, v4";
    v2.pop_back();
    v3.pop_back();
    v4.pop_back();
    cout<<endl;
    cout<<"v2: "<<v2<<endl;
    cout<<"v3: "<<v3<<endl;
    cout<<"v4: "<<v4<<endl;
    cout<<"\n";

    cout<<"push_back: "<<endl;
    v2.push_back(10);
    v2[2] = 10;
    v3.push_back('E');
    v3[2] = 'E';
    v4.push_back("programming ");
    v4[2] = "programming ";
    cout<<"v2: "<<v2<<" , "<<v2[2]<<endl;
    cout<<"v3: "<<v3<<" , "<<v3[2]<<endl;
    cout<<"v4: "<<v4<<" , "<<v4[2]<<endl;
    cout<<"\n";

    v2[2] += 50;
    cout<<"adding 50 to v2[2] : ";
    cout<<"v2: "<<v2<<" , "<<v2[2]<<endl;
    cout<<"v3: "<<v3<<" , "<<v3[2]<<endl;
    cout<<"v4: "<<v4<<" , "<<v4[2]<<endl;
    v4[2] += "with c++";
    cout<<"adding 'with c++' to v4[2] :  ";
    cout<<"v4: "<<v4<<" , "<<v4[2]<<endl;

}


#endif // VECTOR_H
