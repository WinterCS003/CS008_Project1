#ifndef MEMBERS_CONTAINER_H
#define MEMBERS_CONTAINER_H

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include "member.h"

class Members_Container
{
public:
    /****************
    ** CONSTRUCTOR **
    *****************/
    Members_Container();
    ~Members_Container();

    /**************
     ** MUTATORS **
     **************/
    void add_member(const Member& new_member);
    void add_bulk_members(const std::string& file);
    void remove_member(const std::string& _name);
    void remove_member(const int& _membership_number);
    void upgrade_membership(const std::string& _name, const std::string& _date);
    void upgrade_membership(const int& _membership_number, const std::string& _date);

    /***************
     ** ACCESSORS **
     ***************/
    bool contains(const int& _membership_number);
    bool contains(const std::string& _name);
    int get_members_count() {return members_count;};
    Member& operator[](int index) { return members[index]; };
    Member _get_member(int i) {return members[i];};

    Member get_member(int _memberid) {
        assert(this->contains(_memberid));
        for (int i=0; i<members_count; i++) {
            if (members[i].get_membership_number()==_memberid) {
                return members[i];
            }
        }
        return members[0];
    }

    int get_member_index(int _memberid) {
        for (int i=0; i<members_count; i++) {
            if (members[i].get_membership_number()==_memberid) {
                return i;
            }
        }
        return -1;
    }
    bool outFile(std::string name);

private:
    Member *members;
    int members_count;

};

#endif // MEMBERS_CONTAINER_H

/*****************************************************************************
 * Members_Container Class
 *  Container for Member Class objects.
 *****************************************************************************/

/*****************
 ** CONSTRUCTOR **
 *****************/

/*****************************************************************
 * Members_Container();
 *    Constructor; Initialize object.
 *    Parameters: none
 *    Return: none
 *****************************************************************/


/**************
 ** MUTATORS **
 **************/

/********************************************************************************
 * void add_member (const Member& new_member)
 *    Mutator; Adds a Member object to the members attribute.
 *-------------------------------------------------------------------------------
 *    Parameter: Member object
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 * void remove_member (const std::string& _name)
 *    Mutator; Removes a Member object from the members attribute.
 *-------------------------------------------------------------------------------
 *    Parameter: std::string
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 * void remove_member (const int& _membership_number)
 *    Mutator; Removes a Member object from the members attribute.
 *-------------------------------------------------------------------------------
 *    Parameter: integer
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 * void upgrade_membership (const std::string& _name_or_id, const std::string& _date)
 *    Mutator; Changes premium_member attribute of Member object to true. Use
 *     object name attribute as parameter.
 *-------------------------------------------------------------------------------
 *    Parameter: std::string
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 * void upgrade_membership (const int& _membership_number, const std::string& _date)
 *    Mutator; Changes premium_member attribute of Member object to true. Use
 *     object membership_number attribute as parameter.
 *-------------------------------------------------------------------------------
 *    Parameter: integer
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/


/***************
 ** ACCESSORS **
 ***************/

/********************************************************************************
 * int get_members_count ()
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: integer
 ********************************************************************************/

/********************************************************************************
 * bool contains (int _membership_number)
 *  Accessor; returns true if member with passed in _membership_number is found.
 *-------------------------------------------------------------------------------
 *    Parameter: integer
 *-------------------------------------------------------------------------------
 *    Return: boolean
 ********************************************************************************/

/********************************************************************************
 * bool contains (const std::string _name)
 *  Accessor; returns true if member with passed in _name is found.
 *-------------------------------------------------------------------------------
 *    Parameter: std::string
 *-------------------------------------------------------------------------------
 *    Return: boolean
 ********************************************************************************/
