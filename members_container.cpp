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

Members_Container::~Members_Container() {
    delete [] members;
}

/*****************************************************************************
* Method contains(int _membership_number): Class Members_Container
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
bool Members_Container::contains(const int& _membership_number) {
    if (get_members_count() == 0) return false;
    for (int index=0; index<get_members_count(); index++) {
        if (members[index].get_membership_number() == _membership_number)
            return true;
    }
    return false;
}

/*****************************************************************************
* Method contains(const std::string& _name): Class Members_Container
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
bool Members_Container::contains(const std::string& _name) {
    if (get_members_count() == 0) return false;
    for (int index=0; index<get_members_count(); index++) {
        if (members[index].get_name() == _name)
            return true;
    }
    return false;
}


/*****************************************************************************
* Method add_member(const Member& new_member): Class Members_Container
*-----------------------------------------------------------------------------
* This method receives a Member object as argument. Calls contains() function
*  to verify new_member is not already in the *members attribute.
*-----------------------------------------------------------------------------
* This method returns a bool depending on the result.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    If contains() returns false, adds new_member to *members attribute.
******************************************************************************/
void Members_Container::add_member(const Member &new_member) {
    if (!contains(new_member.get_membership_number())) {
        if (get_members_count() < 30) {
            members[members_count] = new_member;
            members_count++;
        }
        else {
            int new_size = get_members_count() * 2;
            Member *temp;
            temp = new Member[new_size];

            for (int i=0; i<get_members_count(); i++)
                temp[i] = members[i];

            delete [] members;
            members = new Member[new_size];

            for (int i=0; i<get_members_count(); i++)
                members[i] = temp[i];

            members[get_members_count()] = new_member;
            members_count++;

            delete [] temp;
        }
    }
}


/*****************************************************************************
* Method remove_member(const std::string& _name): Class Members_Container
*-----------------------------------------------------------------------------
* This method receives a string as argument. Calls contains() function
*  to verify Member with name is in the *members attribute. If found,
*  removes member.
*-----------------------------------------------------------------------------
* This method returns a bool depending on the result.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    If contains() returns true, removes member from *members attribute.
******************************************************************************/
void Members_Container::remove_member(const std::string &_name) {
    if(!contains(_name))
        return;
    for (int i=0; i<get_members_count(); i++) {
        if (members[i].get_name() == _name) {
            for (int j = i; j<get_members_count(); j++)
                members[j] = members[j+1];
            members_count--;
            break;
        }
    }


}

/*****************************************************************************
* Method remove_member(const int& _membership_number): Class Members_Container
*-----------------------------------------------------------------------------
* This method receives an integer as argument. Calls contains() function
*  to verify Member with membership_number is in the *members attribute. If
*  found, removes member.
*-----------------------------------------------------------------------------
* This method returns a bool depending on the result.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    If contains() returns true, removes member from *members attribute.
******************************************************************************/
void Members_Container::remove_member(const int& _membership_number) {
    if(!contains(_membership_number))
        return;
    for (int i=0; i<get_members_count(); i++) {
        if (members[i].get_membership_number() == _membership_number) {
            for (int j = i; j<get_members_count(); j++)
                members[j] = members[j+1];
            members_count--;
            break;
        }
    }
}

/*****************************************************************************
* Method upgrade_membership(const std::string& _name): Class Members_Container
*-----------------------------------------------------------------------------
* This method receives a string as argument. Calls contains() function
*  to verify Member with membership_number is in the *members attribute. If
*  found, and if not already premium, makes them a premium member.
*-----------------------------------------------------------------------------
* This method returns a bool depending on the result.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Changes Member attribute premium_member to true.
******************************************************************************/
void Members_Container::upgrade_membership(const std::string& _name, const std::string& _date) {
    if (!contains(_name))
        return;

    for (int i=0; i<get_members_count(); i++) {
        if (members[i].get_name() == _name) {
            if (!members[i].is_premium_member())
                members[i].upgrade_member(_date);
        }
    }
}

/*****************************************************************************
* Method upgrade_membership(const int& _membership_number): Class Members_Container
*-----------------------------------------------------------------------------
* This method receives an integer as argument. Calls contains() function
*  to verify Member with membership_number is in the *members attribute. If found,
*  and if not already premium, makes them a premium member.
*-----------------------------------------------------------------------------
* This method returns a bool depending on the result.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Changes Member attribute premium_member to true.
******************************************************************************/
void Members_Container::upgrade_membership(const int &_membership_number, const std::string& _date) {
    if (!contains(_membership_number))
        return;

    for (int i=0; i<get_members_count(); i++) {
        if (members[i].get_membership_number() == _membership_number) {
            if (!members[i].is_premium_member())
                members[i].upgrade_member(_date);
        }
    }
}

/*****************************************************************************
* Method add_bulk_members(const ifstream& file): Class Members_Container
*-----------------------------------------------------------------------------
* This method ....
*
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*
* POST-CONDITIONS
*
******************************************************************************/
void Members_Container::add_bulk_members(const std::string& file_location) {
    std::ifstream input;
    input.open(file_location);
    std::string get;

    std::string name;
    std::string temp_id;
    int member_id;
    bool premium = false;
    std::string expiration_date;

    while (input >> get) {
        std::cout << get + "\n";
        name = get;
        input >> get;
        name = name + get;
        input >> get;

        std::cout << get + "\n";
        temp_id = get;
        member_id = stoi(temp_id);
        input >> get;

        std::cout << get + "\n";
        if (get == "Preferred") premium = true;
        input >> get;

        std::cout << get + "\n";
        expiration_date = get;
        add_member(Member(name, member_id, premium, expiration_date));
    }

    input.close();
}
