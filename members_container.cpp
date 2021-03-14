#include "members_container.h"

/*****************************************************************************
* Constructor Member: Class Members_Container
*-----------------------------------------------------------------------------
* This constructor receives no arguments
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    *members initialized with size 30.
*    members_count initialized to 0.
******************************************************************************/
Members_Container::Members_Container()
    :members_count(0)
{
    members = new Member[30];
}

/*****************************************************************************
* Method contains: Class Members_Container
*-----------------------------------------------------------------------------
* This method receives an integer of membership_number as argument. Looks in
*  the *members attribute for an object with passed in membership_number.
*-----------------------------------------------------------------------------
* This method returns a bool depending on the result.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    None.
******************************************************************************/
bool Members_Container::contains(int _membership_number) {
    if (get_members_count() == 0) return false;
    for (int index=0; index<get_members_count(); index++) {
        if (members[index].get_membership_number() == _membership_number)
            return true;
    }
    return false;
}

