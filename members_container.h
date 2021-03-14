#ifndef MEMBERS_CONTAINER_H
#define MEMBERS_CONTAINER_H

#include <iostream>
#include <cassert>
#include <string>
#include "member.h"

class Members_Container
{
public:
    /****************
    ** CONSTRUCTOR **
    *****************/
    Members_Container();

    /**************
     ** MUTATORS **
     **************/
    void add_member(const Member& new_member);
    void remove_member(const std::string& _name_or_id);
    void upgrade_membership(const std::string& _name_or_id);

    /***************
     ** ACCESSORS **
     ***************/
    int get_members_count() {return members_count;};



private:
    Member* members;
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
 * void remove_member (const std::string& _name_or_id)
 *    Mutator; Removes a Member object from the members attribute.
 *-------------------------------------------------------------------------------
 *    Parameter: std::string
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 * void upgrade_membership (const std::string& _name_or_id)
 *    Mutator; Changes premium_member attribute of Member object to true. Uses
 *     the objects name or membership_number as parameter.
 *-------------------------------------------------------------------------------
 *    Parameter: std::string
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
