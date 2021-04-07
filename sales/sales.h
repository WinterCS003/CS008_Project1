#ifndef SALES_H
#define SALES_H

#include <string>
#include <QTextStream>
#include <QDate>

#include "member.h"
#include "item.h"

class sales
{
public:
    /******************
     ** CONSTRUCTORS **
     ******************/
    sales();
    sales(const sales& s);  // IN - sales object to copy from
    sales(std::string date, // IN - date of sale
          int id,           // IN - id of member
          std::string item, // IN - item name
          double price,     // IN - price of item
          int quantity);    // IN - number of items bought

    /**************
     ** MUTATORS **
     **************/

    sales& operator=(const sales& s); // IN – sales object to assign from
    bool setItemName(std::string name);
    bool setDate(std::string date);
    bool setPrice(double price);
    bool setQuantity(int quantity);
    bool setId(int id);

    /***************
     ** ACCESSORS **
     ***************/

    std::string getDate() const;
    int getId() const;
    std::string getItem() const;
    double getPrice() const;
    int getQuantity() const;
    double getRevenue() const;
    bool operator==(const sales& s) const; // IN - sales to compare to

private:
    const double sales_tax = 0.875; // CONST - sales tax rate
    std::string item_name;          // IN - name of item
    std::string date_sold;          // IN - mm/dd/yyyy
    double price;                   // IN - price of item
    int quantity;                   // IN - quantity of item bought
    int member_ID;                  // IN - member id
};

#endif // SALES_H

/****************************************************************
 * sales Class
 *   This class represents a sales object.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * sales();
 *   Constructor; Initialize class attributes
 *   Parameters: none
 *   Return: none
 ***************************************************************/

/****************************************************************
 * sales(const sales& s);
 *   Constructor; copy constructor
 *   Parameters: s (sales&) // IN - sales object to copy from
 *   Return: none
 ***************************************************************/

/****************************************************************
 * sales(std::string date,
 *       int id,
 *       std::string item,
 *       double price,
 *       int quantity,
 *       std::string customer,
 *       bool type);
 *   Constructor; Initialize class attributes with custom values
 *   Parameters: date (std::string) // IN - date of sale
 *               id (int) // IN - id of item
 *               item (std::string) // IN - item name
 *               price (double) // IN - price of item
 *               quantity (int) // IN - number of items bought
 *               customer (std::string) // IN - customer name
 *               type (bool) // IN - membership type
 *   Return: none
 ***************************************************************/

/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * sales& operator=(const sales& s);
 *
 *   Mutator; This method will assign all values in this sales object
 *     with the sales passed in the parameter
 *------------------------------------------------------------------
 *   Parameter: s (sales&) // IN – sales object to assign from
 *------------------------------------------------------------------
 *   Return: reference to this object is returned
 *******************************************************************/

/*******************************************************************
 * bool setItemName(std::string name);
 *
 *   Mutator; This method will set the name of the item sold to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: name (std::string) // IN – item name to set to
 *------------------------------------------------------------------
 *   Return: bool - true on success, false otherwise
 *******************************************************************/

/*******************************************************************
 * bool setDate(std::string date);
 *
 *   Mutator; This method will set the date of the sale, to the
 *            parameter
 *------------------------------------------------------------------
 *   Parameter: date (std::string) // IN – date to update sale to
 *------------------------------------------------------------------
 *   Return: bool - true on success, false otherwise
 *******************************************************************/

/*******************************************************************
 * bool setPrice(double price);
 *
 *   Mutator; This method will assign set the price of the item
 *            sold to the parameter
 *------------------------------------------------------------------
 *   Parameter: price (double) // IN – price to update sale to
 *------------------------------------------------------------------
 *   Return: bool - true on success, false otherwise
 *******************************************************************/

/*******************************************************************
 * bool setQuantity(int quantity);
 *
 *   Mutator; This method will set the quantity sold to the parameter
 *------------------------------------------------------------------
 *   Parameter: quantity (int) // IN – quantity sold to update to
 *------------------------------------------------------------------
 *   Return: bool - true on success, false otherwise
 *******************************************************************/

/*******************************************************************
 * bool setId(int id);
 *
 *   Mutator; This method will set the member id who bought the item
 *            to the parameter
 *------------------------------------------------------------------
 *   Parameter: id (int) // IN – member id to update to
 *------------------------------------------------------------------
 *   Return: bool - true on success, false otherwise
 *******************************************************************/


 /***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * std::string getDate() const;
 *
 *   Accessor; This method will return the date attribute in
 *     dd/mm/yyyy format
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: date_sold (std::string)
 ***************************************************************/

/****************************************************************
 * int getId() const;
 *
 *   Accessor; This method will return the item id
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: item_ID(int)
 ***************************************************************/

/****************************************************************
 * std::string getItem() const;
 *
 *   Accessor; This method will return the name of the item
 *   bought
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: item_name (std::string)
 ***************************************************************/

/****************************************************************
 * double getPrice() const;
 *
 *   Accessor; This method will return the price of the item
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: price (double)
 ***************************************************************/

/****************************************************************
 * int getQuantity() const;
 *
 *   Accessor; This method will return how much of an item was
 *   bought by the customer
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: quantity (int) - number of items bought
 ***************************************************************/

/****************************************************************
 * double getRevenue() const;
 *
 *   Accessor; This method will return the total revenue from
 *   this particular sale
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: revenue (double)
 ***************************************************************/

/****************************************************************
 * bool operator==(const sales& s) const;
 *
 *   Accessor; This method will return true if the parameter is
 *   equal to this object
 * --------------------------------------------------------------
 *   Parameters: s (sales&) // IN - sales to compare to
 * --------------------------------------------------------------
 *   Return: is equal (bool) - returns true if this object is
 *                             equal to the parameter
 ***************************************************************/
