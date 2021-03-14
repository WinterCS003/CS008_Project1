#include "member.h"

/*****************************************************************************
* Constructor Member: Class Member
*-----------------------------------------------------------------------------
* This constructor receives no arguments
* premium_member initialized to false, membership_expiration initialized
* as empty string, total_spend and total_rebates both initialized to 0.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    Blank member object is created.
******************************************************************************/
Member::Member()
    :premium_member(false), membership_expiration(""),
    total_spend(0), total_rebates(0)
{

}

/*****************************************************************************
* Constructor Member: Class Member
*-----------------------------------------------------------------------------
* This constructor receives two arguments for name and membership number.
* premium_member initialized to false, membership_expiration initialized
* as empty string, total_spend and total_rebates both initialized to 0.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    Member object is created.
******************************************************************************/
Member::Member(std::string name, std::string membership_number)
    :premium_member(false), membership_expiration(""),
    total_spend(0), total_rebates(0)
{
    this->name = name;
    this->membership_number = membership_number;
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
 * Receives a string as argument. Returns no values.
 *----------------------------------------------------------------------------
 * PRE-CONDITIONS
 *    none
 * POST-CONDITIONS
 *    membership_number attribute set to parameter.
 *****************************************************************************/
void Member::set_membership_number(const std::string& _number) {
    membership_number = _number;
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
