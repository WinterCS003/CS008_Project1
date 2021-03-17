#include "member.h"

int Member::next_membership_number = 1000;

/*****************************************************************************
* Constructor Member: Class Member
*-----------------------------------------------------------------------------
* This constructor receives no arguments
* membership_number initialized to next_membership_number,
* premium_member initialized to false, membership_expiration initialized
* as empty string, total_spend and total_rebates both initialized to 0.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    Blank member object is created.
*    next_membership_number incremented by 1.
******************************************************************************/
Member::Member()
    :membership_number(next_membership_number), premium_member(false),
    membership_expiration(""), total_spend(0), total_rebates(0)
{
    next_membership_number++;
}

/*****************************************************************************
* Constructor Member: Class Member
*-----------------------------------------------------------------------------
* This constructor receives one argument for name.
* membership_number initialized to next_membership_number,
* premium_member initialized to false, membership_expiration initialized
* as empty string, total_spend and total_rebates both initialized to 0.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    Member object is created.
*    next_membership_number incremented by 1.
******************************************************************************/
Member::Member(std::string name)
    :membership_number(next_membership_number), premium_member(false),
    membership_expiration(""), total_spend(0), total_rebates(0)
{
    this->name = name;
    next_membership_number++;
}

Member::Member(std::string nm,
       int memNum,
       bool premium,
       std::string expDate,
       double totalSpent,
       double totalRebate)
{
    name = nm;
    membership_number = memNum;
    premium_member = premium;
    membership_expiration = expDate;
    total_spend = totalSpent;
    total_rebates = totalRebate;
}

/*****************************************************************************
 * Method set_name: Class Member
 *----------------------------------------------------------------------------
 * Receives a string as argument. Returns no values.
 *----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    none
 * POST-CONDITIONS
 *    Name attribute set to parameter.
 *****************************************************************************/
void Member::set_name(const std::string& _name) {
    name = _name;
}

/*****************************************************************************
 * Method set_membership_number: Class Member
 *----------------------------------------------------------------------------
 * Receives no argument. Returns no values.
 *----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    none
 * POST-CONDITIONS
 *    membership_number attribute set to next_membership_number.
 *    next_membership_number incremented by 1.
 *****************************************************************************/
void Member::set_membership_number() {
    membership_number = next_membership_number;
    next_membership_number++;
}

/*****************************************************************************
 * Method upgrade_member: Class Member
 *----------------------------------------------------------------------------
 * Receives a string argument. Returns no values.
 * Argument should be entered as 2-digit month and four-digit year. No spaces.
 * Example: For March 2021 enter 032021.
 *----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    premium_member is false.
 * POST-CONDITIONS
 *    premium_member set to true.
 *    membership_expiration set to 1 year from date entered.
 *****************************************************************************/
void Member::upgrade_member(const std::string& todays_date) {
    assert(premium_member == false);
    premium_member = true;

    //Take todays_date and increment the year by one.
    std::string date = todays_date;

    int temp = (int)date[5] - 48;

    if (temp < 9)
        temp++;

    else {
        temp = 0;
        int temp2 = (int)date[4] - 48;
        temp2++;
        date[4] = (char)temp2 + 48;
    }
    date[5] = (char)temp + 48;


    membership_expiration = date;
}

/*****************************************************************************
 * Method extend_membership: Class Member
 *----------------------------------------------------------------------------
 * Receives no arguments. Returns no values.
 *----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    premium_member is true.
 * POST-CONDITIONS
 *    membership_expiration extended by one year.
 *****************************************************************************/
void Member::extend_membership() {
    assert(is_premium_member());

    std::string date = get_membership_expiration();

    int temp = (int)date[5] - 48;

    if (temp < 9)
        temp++;

    else {
        temp = 0;
        int temp2 = (int)date[4] - 48;
        temp2++;
        date[4] = (char)temp2 + 48;
    }
    date[5] = (char)temp + 48;

    membership_expiration = date;

}

// returns all member info string form
std::string getInfo()
{

}
