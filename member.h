#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <cassert>
#include <string>
//#include "sales_container.h"

class Member
{
public:
    /****************
    ** CONSTRUCTOR **
    *****************/
    Member();
    Member(std::string name);
    // added member constructor
    Member(std::string nm,
           int memNum,
           bool premium,
           std::string expDate,
           double totalSpent,
           double totalRebate);

    /**************
     ** MUTATORS **
    ***************/
    void set_name(const std::string& _name);
    void set_membership_number();
    void upgrade_member(const std::string& _month_year);
    void extend_membership();


    /***************
     ** ACCESSORS **
    ****************/
    std::string get_name() const { return name; };
    int get_membership_number() const { return membership_number; };
    bool is_premium_member() const { return premium_member; };
    std::string get_membership_expiration() const { return membership_expiration; };
    double get_total_spend() const { return total_spend; };
    double get_total_rebates() const { return total_rebates; };
    std::string getInfo();

private:
    std::string name;
    int membership_number;
    static int next_membership_number;
    bool premium_member;
    std::string membership_expiration;
    double total_spend;
    double total_rebates;
    //    sales_container purchases[];
    // vector purchaseHistory?
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

/********************************************************************************
 * void set_name (const std::string& _name)
 *    Mutator; Method sets the name attribute.
 *-------------------------------------------------------------------------------
 *    Parameter: std::string
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 * void set_membership_number ()
 *    Mutator; Method sets the membership_number attribute.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *  void upgrade_member (std::string todays_date)
 *    Mutator; Changes premium_member attribute to True. Changes membership
 *     expiration to one year past the date of the parameter.
 *-------------------------------------------------------------------------------
 *    Parameter: std::string
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *  void extend_membership ()
 *    Mutator; adds one year on to the membership_expiration attribute.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/


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
 * int get_membership_number() const;
 *   Accessors; This method will return the membership_number attribute.
 *----------------------------------------------------------------------------
 *   Parameter: none
 *----------------------------------------------------------------------------
 *   Return: integer
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
