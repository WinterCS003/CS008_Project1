#ifndef MANAGEMEMBERS_H
#define MANAGEMEMBERS_H

#include <algorithm>

#include <QMainWindow>
#include <QMessageBox>
#include "members_container.h"

#include "sales/sales_container.h"

namespace Ui {
class manageMembers;
}

class manageMembers : public QMainWindow
{
    Q_OBJECT

public:
    /******************
     ** CONSTRUCTORS **
     ******************/
    manageMembers(QWidget *parent = nullptr);
    manageMembers(QWidget *parent, Members_Container* mc, sales_container* sc);
    ~manageMembers();

private slots:
    /**************
     ** MUTATORS **
     **************/
    void on_submit_clicked();
    void on_submitFile_clicked();
    void on_submitDelete_clicked();
    void on_displayButton_clicked();
    void on_submitRenew_clicked();
    void on_convertAll_clicked();
    void on_convertOne_clicked();
    void on_BasicToPremium_clicked();
    void on_button_addMember_clicked();
    void on_button_delete_Member_clicked();

    /***************
     ** ACCESSORS **
     ***************/
    void on_viewMemberInfo_clicked();
    void on_membersFromFile_clicked();
    void on_membersConvToBasic_clicked();
    void printReport(Members_Container&);
    void on_button_renew_membership_clicked();
    void on_membershipExpirations_clicked();
    void on_submitDate_clicked();
    void on_printTotalRebates_clicked();

private:
    Ui::manageMembers *ui;
    Members_Container* members;
    sales_container* all_sales;
};

#endif // MANAGEMEMBERS_H

/*****************************************************************************
 * manageMembers Class
 *
 *****************************************************************************/


/*****************
 ** CONSTRUCTOR **
 *****************/

/*****************************************************************************
 * manageMembers(QWidget *parent = nullptr)
 *    Constructor; initialize object
 *    Parameters: QWidget *parent
 *    Returns: none
 *****************************************************************************/

/*****************************************************************************
 * manageMembers(QWidget *parent, Members_Container* mc)
 *    Constructor; initialize object
 *    Parameters: QWidget, Members_Container
 *    Returns: none
 *****************************************************************************/


/**************
 ** MUTATORS **
 **************/

/********************************************************************************
 *   void on_submit_clicked();
 *    Mutator; adds member to the member container.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_submitFile_clicked();
 *    Mutator; pulls members from a file and adds them to container.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_submitDelete_clicked();
 *    Mutator; deletes member from member container.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_displayButton_clicked();
 *    Mutator; displays member info into the text browser.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_submitRenew_clicked();
 *    Mutator; extends the members membership by one year. Adjusts the
 *     member expiration date parameter.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/


/********************************************************************************
 *   void on_convertAll_clicked();
 *    Mutator; converts all members from basic to premium
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 * void on_convertOne_clicked();
 *    Mutator; converts a single member from basic to premium
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *  void on_BasicToPremium_clicked();
 *    Mutator; changes members from basic to premium
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/


/********************************************************************************
 *   void on_button_addMember_clicked();
 *    Mutator; brings up input for user to enter new member information.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_button_delete_Member_clicked();
 *    Mutator; brings up input for user to enter member id for member
 *     deletion.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/


/***************
 ** ACCESSORS **
 ***************/

/********************************************************************************
 *   void on_viewMemberInfo_clicked();
 *    Mutator; brings up input for user to enter the member id.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_membersFromFile_clicked();
 *    Mutator; brings up input for user to enter file for adding members.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_membersConvToBasic_clicked();
 *    Mutator; displays list of members names and their id's in the
 *     text browser
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_button_renew_membership_clicked();
 *    Mutator; brings up input box for user to enter member's id.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_membershipExpirations_clicked();
 *    Mutator; brings up dateInput box for user to enter month and year
 *     to search for members with expiring memberships.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_submitDate_clicked();
 *    Mutator; displays the members with expiring memberships.
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void printReport(Members_Container&);
 *    Mutator; Prints a report of all members who should convert to premium
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/

/********************************************************************************
 *   void on_printTotalRebates_clicked();
 *    Mutator; displays the rebates given to all premium members
 *-------------------------------------------------------------------------------
 *    Parameter: none
 *-------------------------------------------------------------------------------
 *    Return: none
 ********************************************************************************/
