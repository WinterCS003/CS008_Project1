#include "member.h"

/*****************************************************************************
* Constructor Member: Class Member
*-----------------------------------------------------------------------------
* This constructor receives no arguments
* total_spend and total_rebates are initialized to 0
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    An instance of the set is created with an empty array and used set to zero
******************************************************************************/
Member::Member() {}

/*****************************************************************************
* Constructor Member: Class Member
*-----------------------------------------------------------------------------
* This constructor receives two arguments for name and membership number.
* total_spend and total_rebates are initialized to 0
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    An instance of the set is created with an empty array and used set to zero
******************************************************************************/
Member::Member(std::string name, std::string membership_number)
    :total_spend(0), total_rebates(0)
{
    this->name = name;
    this->membership_number = membership_number;
}
