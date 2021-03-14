#ifndef SALES_H
#define SALES_H

#include <string>

#include "stubs/member.h"
#include "stubs/item.h"

class sales
{
public:
    /******************
     ** CONSTRUCTORS **
     ******************/
    sales();
    sales(const sales& s);
    sales(std::string, std::string, std::string, bool, double);


    /**************
     ** MUTATORS **
     **************/

    sales& operator=(const sales& s);

    /***************
     ** ACCESSORS **
     ***************/

    std::string getDate() const;
    std::string item() const;
    std::string customer() const;
    bool member_type() const;

private:
    std::string date_sold;
    std::string item_name;
    std::string customer_name;
    bool isPreferred;
    double price;
    const double sales_tax = 0.875;
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
 * ~sales();
 *   Destructor; It does not perform any specific function
 *   Parameters: none
 *   Return: none
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void SetAge(int age);
 *
 *   Mutator; This method will update the age attribute to the
 *      parameter age value
 *------------------------------------------------------------------
 *   Parameter: age (int) // IN –the age for the new attribute
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * intGetAge() const;
 *
 *   Accessor; This method will return the age attribute
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: age (int)
 ***************************************************************/
