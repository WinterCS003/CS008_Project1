#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
//#include "sales_container.h"

class Member
{
public:
    /****************
    ** CONSTRUCTOR **
    *****************/
    Member();
    Member(std::string name, std::string membership_number);

    /**************
     ** MUTATORS **
    ***************/

    /***************
     ** ACCESSORS **
    ****************/
    std::string get_name() const {return name;};
    std::string get_membership_number() const {return membership_number;};
    bool is_premium_member() const {return premium_member;};
    std::string get_membership_expiration() const {return membership_expiration;};
    double get_total_spend() const {return total_spend;};
    double get_total_rebates() const {return total_rebates;};

private:
    std::string name;
    std::string membership_number;
    bool premium_member;
    std::string membership_expiration;
    double total_spend;
    double total_rebates;
//    sales_container purchases[];
};

/*****************************************************************************
 * Member Class
 *
 *
 *
 *****************************************************************************/

/*****************
 ** CONSTRUCTOR **
 *****************/

/*****************************************************************************
 * Member();
 *    Constructor; initializes total_spend, total_rebates to 0.
 *    Parameters: none
 *    Return: none
 *****************************************************************************/


/**************
 ** MUTATORS **
 **************/


/***************
 ** ACCESSORS **
 ***************/

/*****************************************************************************
 * std::string get_name() const;
 *   Accessors; This method will return the name attribute.
 *----------------------------------------------------------------------------
 *   Parameter: none
 *----------------------------------------------------------------------------
 *   Return: std::string
 *****************************************************************************/

/*****************************************************************************
 * std::string get_membership_number() const;
 *   Accessors; This method will return the membership_number attribute.
 *----------------------------------------------------------------------------
 *   Parameter: none
 *----------------------------------------------------------------------------
 *   Return: std::string
 *****************************************************************************/

/*****************************************************************************
 * bool is_premium_member() const;
 *   Accessors; This method will return the premium_member attribute.
 *----------------------------------------------------------------------------
 *   Parameter: none
 *----------------------------------------------------------------------------
 *   Return: boolean
 *****************************************************************************/

/*****************************************************************************
 * std::string get_membership_expiration() const;
 *   Accessors; This method will return the membership_expiration attribute.
 *----------------------------------------------------------------------------
 *   Parameter: none
 *----------------------------------------------------------------------------
 *   Return: std::string
 *****************************************************************************/

/*****************************************************************************
 * double get_total_spend() const;
 *   Accessors; This method will return the total_spend attribute.
 *----------------------------------------------------------------------------
 *   Parameter: none
 *----------------------------------------------------------------------------
 *   Return: double
 *****************************************************************************/

/*****************************************************************************
 * double get_total_rebates() const;
 *   Accessors; This method will return the total_rebates attribute.
 *----------------------------------------------------------------------------
 *   Parameter: none
 *----------------------------------------------------------------------------
 *   Return: double
 *****************************************************************************/
#endif // MEMBER_H
