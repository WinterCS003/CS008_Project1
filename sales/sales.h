#ifndef SALES_H
#define SALES_H

#include <string>

#include "member.h"
#include "stubs/item.h"

class sales
{
public:
    /******************
     ** CONSTRUCTORS **
     ******************/
    sales();
    sales(const sales& s);
    sales(std::string, int, std::string, double, int, std::string, bool);


    /**************
     ** MUTATORS **
     **************/

    sales& operator=(const sales& s);

    /***************
     ** ACCESSORS **
     ***************/

    std::string getDate() const;
    int getId() const;
    std::string getItem() const;
    double getPrice() const;
    int getQuantity() const;
    double getRevenue() const;
    std::string getCustomer() const;
    bool member_type() const;
    bool operator==(const sales& s) const;

private:
    const double sales_tax = 0.875; // CONST - sales tax rate
    std::string customer_name;      // IN - name of customer
    std::string item_name;          // IN - name of item
    std::string date_sold;          // IN - mm/dd/yyyy
    bool isPreferred;               // IN - membership type
    double price;                   // IN - price of item
    int quantity;                   // IN - quantity of item bought
    int item_ID;                    // IN - item id
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
 *   Parameters: s (sales&) - sales object to copy from
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
 * std::string getCustomer() const;
 *
 *   Accessor; This method will return the name of the customer
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: customer_name (std::string) - name of customer
 ***************************************************************/

/****************************************************************
 * bool member_type() const;
 *
 *   Accessor; This method will return the membership type of
 *   the customer
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: isPreferred (bool) - returns membership type
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
