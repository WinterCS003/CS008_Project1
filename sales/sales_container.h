#ifndef sales_container_H
#define sales_container_H

#include "sales.h"
#include "inventory.h"
#include "members_container.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <fstream>

class sales_container
{
public:
    /********************************
     ** CONSTRUCTORS & DESTRUCTORS **
     ********************************/
    sales_container();
    sales_container(unsigned int size);        // IN - size of new container
    sales_container(unsigned int size,         // IN - size of new container
                    const sales& initial);     // IN - first sale object
    sales_container(const sales_container& v); // copy constructor
    ~sales_container();  // destructor - delete all sales

    /***************
     ** ACCESSORS **
     ***************/
    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    sales& operator[](unsigned int index) const; // IN - index of sales
                                                 //      object
    double getTotalRevenue() const;
    int find(const sales& s) const; // IN - sales to search for
    int find(std::string name) const; // IN - sales to search for
    int find(int id) const; // IN - sales to search for
    int getItemQuantity(std::string item) const; // item to search
    bool contains(sales& s) const;
    bool contains(int id) const;
    sales* begin() const {return &my_list[0];}
    sales* end() const {return &my_list[my_size];}
    bool outFile(std::string output) const;


    /**************
     ** MUTATORS **
     **************/
    void push_back(const sales& value);
    void push_back(QWidget* parent,
                   const sales& value,
                   inventory& inventory,
                   Members_Container& all_members); // IN – sales to add to end of object
    void pop_back();
    void erase(const sales& s); // IN – sales to erase from object

    void set_size(int size);         // IN – new size of the object
    void set_capacity(int capacity); // IN – new capacity for the object

    sales_container& operator=(const sales_container& s); // IN – sales container to
                                                          //      assign from

    void reserve(unsigned int capacity); // IN – new capacity
    void resize(unsigned int size);      // IN – new size of container
    void clear();
    bool readFile(QWidget* parent,
                  std::string input,
                  inventory& inventory,
                  Members_Container& members);
    bool readFile(std::string name);

private:
    unsigned int my_capacity; // IN - allocated size of container
    unsigned int my_size;     // IN - size of container
    sales* my_list;           // IN - array of sales
};


#endif // sales_container_H

/****************************************************************
 * sales_container Class
 *   This class represents a container of sales objects. It
 *   handles 4 attributes, the size of the container, the
 *   allocated capacity of the container, and an array of sales.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * sales_container();
 *   Constructor; Initialize an empty class
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * sales_container(unsigned int size);
 *   Constructor; Initialize a sales_container to parameter size
 *   Parameters: size (unsigned int) // IN - size of new container
 *   Return: none
 ***************************************************************/

/****************************************************************
 * sales_container(unsigned int size, const sales& initial);
 *   Constructor; Initialize class to a new parameter sales
 *                of passed size
 *   Parameters: size (unsigned int) // IN - size of new container
 *               initial (sales&) // IN - first sale object
 *   Return: none
 ***************************************************************/

/****************************************************************
 * sales_container(const sales_container& s);
 *   Constructor; copy constructor
 *   Parameters: s (sales_container&) // IN - parameter to copy
 *                                            from
 *   Return: none
 ***************************************************************/

/****************************************************************
 * ~sales_container();
 *   Destructor; deallocates my_list attribute
 *   Parameters: none
 *   Return: none
 ***************************************************************/

 /***************
  ** ACCESSORS **
  ***************/

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

/****************************************************************
 * int find(std::string name) const;
 *
 *   Accessor; This method will return the index of the first
 *             instance found of sale of passed item name.
 * --------------------------------------------------------------
 *   Parameters: name (std::string) // IN - item name to search
 *                                          for
 * --------------------------------------------------------------
 *   Return: index (int) - index of the item name to find
 *                         -1 is returned if parameter not found
 ***************************************************************/

/****************************************************************
 * int find(int id) const;
 *
 *   Accessor; This method will return the index of the first
 *             sale made by the passed member id
 * --------------------------------------------------------------
 *   Parameters: id (int) // IN - member id to search for
 * --------------------------------------------------------------
 *   Return: index (int) - index of the member id to find
 *                         -1 is returned if parameter not found
 ***************************************************************/

/****************************************************************
 * int getItemQuantity(std::string item) const;
 *
 *   Accessor; This method will return the total number of item
 *             stored in the container.
 * --------------------------------------------------------------
 *   Parameters: item (std::string) // IN - item name to search
 *                                          for
 * --------------------------------------------------------------
 *   Return: (int) - total number of item name passed from
 *                   parameter found in the container.
 ***************************************************************/

/****************************************************************
 * bool contains(sales& s) const;
 *
 *   Accessor; This method will return true if passed sale can
 *             be found in the sales container.
 * --------------------------------------------------------------
 *   Parameters: s (sales&) // IN - sale to search for
 * --------------------------------------------------------------
 *   Return: (bool) - true if sale found in sales container, false
 *                    otherwise.
 ***************************************************************/

/****************************************************************
 * bool contains(int id) const;
 *
 *   Accessor; This method will return true if the sales container
 *             has a sale by member with the passed id.
 * --------------------------------------------------------------
 *   Parameters: id (int) // IN - member id to seach for
 * --------------------------------------------------------------
 *   Return: (bool) - true if id found in sales container, false
 *                    otherwise.
 ***************************************************************/

/****************************************************************
 * sales* begin() const
 *
 *   Accessor; This method will return a pointer to the first
 *             element
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: sales (sales*) - pointer to the first element
 ***************************************************************/

/****************************************************************
 * sales* end() const
 *
 *   Accessor; This method will return a pointer to the position
 *             after the last element
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: sales (sales*) - pointer to the position after the
 *                            last element
 ***************************************************************/

/****************************************************************
 *   bool outFile(std::string output) const;
 *
 *   Accessor; This method will print all sales in the container
 *             into a txt file
 * --------------------------------------------------------------
 *   Parameters: output (std::string)// IN - file name to output
 *                                           to
 * --------------------------------------------------------------
 *   Return: (bool) - true on success, false otherwise
 ***************************************************************/

/**************
 ** MUTATORS **
 **************/

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

/*******************************************************************
 * void sales_container::push_back(QWidget* parent,
 *                                 const sales& value,
 *                                 inventory& inventory,
 *                                 Members_Container& all_members)
 *
 *   Mutator; This method will add the parameter to the end of the
 *   object
 *------------------------------------------------------------------
 *   Parameter: parent (QWidget*) // IN - QWidget to print errors to
 *              value (const sales&) // IN - sale to add to container
 *              inventory (inventory&) // IN - container of all items
 *              members (Members_Container&) // IN - container of
 *                                               all members, for errors
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

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

/*******************************************************************
 * void set_size(int size);
 *
 *   Mutator; This method will set the size of the object to the
 *   parameter
 *------------------------------------------------------------------
 *   Parameter: size (int) // IN – new size of the object
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void set_capacity(int capacity);
 *
 *   Mutator; This method will set the capacity of this object to
 *   the parameter
 *------------------------------------------------------------------
 *   Parameter: capacity (int) // IN – new capacity for the object
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

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

/*******************************************************************
 * void reserve(unsigned int capacity);
 *
 *   Mutator; This method will set the capacity of the container to
 *   the parameter, size will remain the same
 *------------------------------------------------------------------
 *   Parameter: capacity (unsigned int) // IN – new capacity
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void resize(unsigned int size);
 *
 *   Mutator; This method will set the size and capacity of the
 *   container to the parameter
 *------------------------------------------------------------------
 *   Parameter: size (unsigned int) // IN – new size of container
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void clear();
 *
 *   Mutator; This method will erase all elements in the object
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * bool readFile(QWidget* parent,
                  std::string input,
                  inventory& inventory,
                  Members_Container& members);
 *
 *   Mutator; This method will read sales from a txt file and save
 *            them into the container. Inventory is updated and
 *            error handling is put in place.
 *------------------------------------------------------------------
 *   Parameter: parent (QWidget*) // IN - QWidget to print errors to
 *              input (std::string) // IN - txt file to read from
 *              inventory (inventory&) // IN - container of all items
 *              members (Members_Container&) // IN - container of
                                                all members, for errors
 *------------------------------------------------------------------
 *   Return: bool - true on success, false otherwise
 *******************************************************************/

/*******************************************************************
 * bool readFile(std::string name)
 *
 *   Mutator; This method will read sales from a txt file and save
 *            them into the container without updating the inventory
 *------------------------------------------------------------------
 *   Parameter: name (std::string) // IN - name of txt file to read
 *------------------------------------------------------------------
 *   Return: bool - true on success, false otherwise
 *******************************************************************/
