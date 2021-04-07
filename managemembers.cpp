#include "managemembers.h"
#include "ui_managemembers.h"

/*****************************************************************************
* Constructor manageMembers: Class manageMembers
*-----------------------------------------------------------------------------
* Receives parameter for a QWidget.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    Initializes the UI.
******************************************************************************/
manageMembers::manageMembers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manageMembers)
{
    ui->setupUi(this);
}

/*****************************************************************************
* Constructor manageMembers: Class manageMembers
*-----------------------------------------------------------------------------
* Receives parameters for a QWidget and a Members_Container.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    none
* POST-CONDITIONS
*    Initializes the UI.
*    Hides the labels and inputs.
******************************************************************************/
manageMembers::manageMembers(QWidget *parent, Members_Container* mc, sales_container* sc)
    : QMainWindow(parent)
    , ui(new Ui::manageMembers)
{
    ui->setupUi(this);
    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->submitRenew->hide();
    ui->dateEdit->hide();
    ui->submitDate->hide();
    ui->convertToPremium->hide();
    ui->id->hide();
    ui->idInput->hide();
    ui->name->hide();
    ui->nameInput->hide();
    ui->convertAll->hide();
    ui->convertOne->hide();

    members = mc;
    all_sales = sc;
}


/*****************************************************************************
* Destructor manageMembers: Class manageMembers
*-----------------------------------------------------------------------------
* Receives no arguments.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    Constructor called.
* POST-CONDITIONS
*    Deletes the UI.
******************************************************************************/
manageMembers::~manageMembers()
{
    delete ui;
}

/*****************************************************************************
* Method on_button_addMember_clicked(): Class manageMembers
*  Receives no arguments. Displays text fields to get user input.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    None.
******************************************************************************/
void manageMembers::on_button_addMember_clicked()
{
    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();
    ui->input_4_exp_dat->clear();
    ui->input_5_total_spend->clear();
    ui->input_6_rebate_amt->clear();
    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->submitRenew->hide();
    ui->dateEdit->hide();
    ui->submitDate->hide();
    ui->convertToPremium->hide();
    ui->id->hide();
    ui->idInput->hide();
    ui->name->hide();
    ui->nameInput->hide();
    ui->convertAll->hide();
    ui->convertOne->hide();

    ui->label_1_name->show();
    ui->label_2_mem_ID->show();
    ui->label_3_prem->show();
    ui->label_4_exp_dat->show();
    ui->input_1_name->show();
    ui->input_2_mem_ID->show();
    ui->input_3_prem->show();
    ui->input_4_exp_dat->show();
    ui->submit->show();
    ui->display->clear();

}

/*****************************************************************************
* Method on_submit_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Adds member to member container.
******************************************************************************/
void manageMembers::on_submit_clicked()
{
    QString mem_number;
    QString mem_name;

    mem_name = ui->input_1_name->text();
    mem_number = ui->input_2_mem_ID->text();
    bool premium = ui->input_3_prem->isChecked();
    std::string date = ui->input_4_exp_dat->date().toString("MM/dd/yyyy").toStdString();

    std::string name = mem_name.toStdString();
    int number = mem_number.toInt();

    members->add_member(Member(name,number, premium, date));

    ui->display->setPlainText(QString::fromStdString("Added! Total members: "));
    ui->display->setPlainText(QString::fromStdString("Added! Total members: ") + QString::number(members->get_members_count()));

    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();
    ui->input_4_exp_dat->clear();
    ui->input_5_total_spend->clear();
    ui->input_6_rebate_amt->clear();
}

/*****************************************************************************
* Method on_membersFromFile_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    None.
******************************************************************************/
void manageMembers::on_membersFromFile_clicked() {
    ui->display->clear();
    ui->label_1_name->hide();
    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();
    ui->input_4_exp_dat->clear();
    ui->input_5_total_spend->clear();
    ui->input_6_rebate_amt->clear();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitRenew->hide();
    ui->dateEdit->hide();
    ui->submitDate->hide();
    ui->convertToPremium->hide();
    ui->id->hide();
    ui->idInput->hide();
    ui->name->hide();
    ui->nameInput->hide();
    ui->convertAll->hide();
    ui->convertOne->hide();

    ui->label_1_name->show();
    ui->input_1_name->show();
    ui->submitFile->show();

}

/*****************************************************************************
* Method on_submitFile_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Adds members from file to member container.
******************************************************************************/
void manageMembers::on_submitFile_clicked() {
    QString input;
    input =  ui->input_1_name->text();
    ui->input_1_name->clear();
    std::string file_name = input.toStdString();

    if (members->validateMemberFile(file_name)) {
        members->add_bulk_members(file_name);
        int prev_total_members = members->get_members_count();
        int new_total_members = members->get_members_count();
        int added_members = new_total_members - prev_total_members;
        QString msg_top = "New Members Added:";
        QString msg;

        for (int i = members->get_members_count(); i > (members->get_members_count()-added_members); i-- ) {
            msg = msg + QString::fromStdString("Name: " + members->_get_member(i-1).get_name() + "\t");
            msg = msg + "ID: " + QString::number(members->_get_member(i-1).get_membership_number()) + "\n";
        }
        ui->display->setPlainText(msg_top + "\n" + msg);
    }
    else
        ui->display->setPlainText("ERROR: Invalid file input.");
}

/*****************************************************************************
* Method on_button_delete_Member_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    None.
******************************************************************************/
void manageMembers::on_button_delete_Member_clicked()
{
    ui->display->clear();
    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();
    ui->input_4_exp_dat->clear();
    ui->input_5_total_spend->clear();
    ui->input_6_rebate_amt->clear();
    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->submitRenew->hide();
    ui->dateEdit->hide();
    ui->submitDate->hide();
    ui->convertToPremium->hide();
    ui->id->hide();
    ui->idInput->hide();
    ui->name->hide();
    ui->nameInput->hide();
    ui->convertAll->hide();
    ui->convertOne->hide();

    ui->label_1_name->show();
    ui->input_1_name->show();
    ui->label_2_mem_ID->show();
    ui->input_2_mem_ID->show();
    ui->submitDelete->show();
}

/*****************************************************************************
* Method on_submitDelete_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Removes member from container.
******************************************************************************/
void manageMembers::on_submitDelete_clicked()
{
    int number;
    QString mem_name;

    mem_name = ui->input_1_name->text();
    number = ui->input_2_mem_ID->value();
  
    std::string name = mem_name.toStdString();

    ui->label_2_mem_ID->hide();
    ui->input_2_mem_ID->hide();
    ui->submitDelete->hide();

    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();

    members->remove_member(number);
    int count = members->get_members_count();
    QString msg = "Deleted! Total members: ";
    ui->display->setPlainText(msg + QString::number(count));
}

/*****************************************************************************
* Method on_viewMemberInfo_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    None.
******************************************************************************/
void manageMembers::on_viewMemberInfo_clicked()
{
    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();
    ui->input_4_exp_dat->clear();
    ui->input_5_total_spend->clear();
    ui->input_6_rebate_amt->clear();
    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->submitRenew->hide();
    ui->dateEdit->hide();
    ui->submitDate->hide();
    ui->convertToPremium->hide();
    ui->id->hide();
    ui->idInput->hide();
    ui->name->hide();
    ui->nameInput->hide();
    ui->convertAll->hide();
    ui->convertOne->hide();

    ui->display->clear();
    ui->label_1_name->show();
    ui->input_1_name->show();
    ui->label_2_mem_ID->show();
    ui->input_2_mem_ID->show();
    ui->displayButton->show();
}

/*****************************************************************************
* Method on_displayButton_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Displays member information in the text browser.
******************************************************************************/
void manageMembers::on_displayButton_clicked() {
    QString mem_number;
    QString mem_name;

    mem_name = ui->input_1_name->text();
    mem_number = ui->input_2_mem_ID->text();
    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();

    int id_number = mem_number.toInt();

    if(mem_name.length() == 0)

    {
        if(!members->contains(id_number)){
            QMessageBox::warning(this, "Warning", "not a member id");
            return;
        }
        QString msg_top = "Member Information";
        QString msg_id = "ID#: ";
        QString msg_name = "Name: ";
        QString msg_prem = "Premium: ";
        QString msg_exp_date = "Membership Expiration: ";
        std::string name = members->get_member(id_number).get_name();
        QString name_display = QString::fromStdString(name);
        QString prem_display = "N";
        QString exp_date_display = "N/A";
        if (members->get_member(id_number).is_premium_member()) {
            prem_display = "Y";
            std::string temp = members->get_member(id_number).get_membership_expiration();
            exp_date_display = QString::fromStdString(temp);
        }
        ui->display->setPlainText( msg_top + "\n" +
                                   msg_name + "\t" + "\t" + name_display + "\n" +
                                   msg_id +  "\t" + "\t" + QString::number(id_number) + "\n" +
                                   msg_prem + "\t" + "\t" + prem_display + "\n" +
                                   msg_exp_date + "\t" + exp_date_display
                                       );
    }
    else
    {
        if(!members->contains(mem_name.toStdString())){
            QMessageBox::warning(this, "Warning", mem_name + " is not a member");
            return;
        }
        QString msg_top = "Member Information";
        QString msg_id = "ID#: ";
        QString msg_name = "Name: ";
        QString msg_prem = "Premium: ";
        QString msg_exp_date = "Membership Expiration: ";

        Member m1;
        for(int i = 0; i < members->get_members_count(); i++)
        {
            if((*members)[i].get_name() == mem_name.toStdString())
            {
                m1 = (*members)[i];
                break;
            }
        }
        id_number = m1.get_membership_number();
        QString prem_display = "N";
        QString exp_date_display = "N/A";

        if (members->get_member(id_number).is_premium_member()) {
            prem_display = "Y";
            std::string temp = members->get_member(id_number).get_membership_expiration();
            exp_date_display = QString::fromStdString(temp);
        }

        ui->display->setPlainText( msg_top + "\n" +
                                   msg_name + "\t" + "\t" + mem_name + "\n" +
                                   msg_id +  "\t" + "\t" + QString::number(id_number) + "\n" +
                                   msg_prem + "\t" + "\t" + prem_display + "\n" +
                                   msg_exp_date + "\t" + exp_date_display
                                       );
    }
}

/*****************************************************************************
* Method on_membersConvToBasic_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Displays member information in the text browser.
******************************************************************************/
void manageMembers::on_membersConvToBasic_clicked()
{
    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();
    ui->input_4_exp_dat->clear();
    ui->input_5_total_spend->clear();
    ui->input_6_rebate_amt->clear();

    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->submitRenew->hide();
    ui->dateEdit->hide();
    ui->submitDate->hide();

    Members_Container memberList;
    for (int i = 0; i < members->get_members_count(); i++)
    {
        // checks if the member's rebates is less than the difference in
        // annual fees, if yes, add to temp container
        if (members->operator[](i).get_total_rebates() < 15)
        {
            if (members->_get_member(i).is_premium_member())
                memberList.add_member(members->operator[](i));
        }
    }
    std::string output = "";
    // outputs temp container to display
    for (int j = 0; j < memberList.get_members_count(); j++)
    {
        output += "Name: " + memberList[j].get_name() + "\t\t" +
                "ID: " + std::to_string(memberList[j].get_membership_number()) + "\n";
    }
    ui->display->setText(QString::fromStdString(output));
}

/*****************************************************************************
* Method on_button_renew_membership_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    None.
******************************************************************************/
void manageMembers::on_button_renew_membership_clicked() {

    ui->display->clear();
    ui->label_1_name->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->convertToPremium->hide();
    ui->id->hide();
    ui->idInput->hide();
    ui->name->hide();
    ui->nameInput->hide();
    ui->convertAll->hide();
    ui->convertOne->hide();

    ui->label_2_mem_ID->show();
    ui->input_2_mem_ID->show();
    ui->submitRenew->show();
}

/*****************************************************************************
* Method on_submitRenew_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Extends member's membership by one year.
******************************************************************************/
void manageMembers::on_submitRenew_clicked() {
    int id_number;
    id_number = ui->input_2_mem_ID->value();

    if (members->contains(id_number)) {
        members->extend_membership(id_number);

        QString msg_top = "Membership extended!";
        QString msg_id = "ID#: ";
        QString msg_name = "Name: ";
        QString msg_prem = "Premium: ";
        QString msg_exp_date = "Membership Expiration: ";

        std::string name = members->get_member(id_number).get_name();
        QString name_display = QString::fromStdString(name);
        QString prem_display = "N";
        QString exp_date_display = "N/A";

        if (members->get_member(id_number).is_premium_member()) {
            prem_display = "Y";
            std::string temp = members->get_member(id_number).get_membership_expiration();
            exp_date_display = QString::fromStdString(temp);
        }

        ui->display->setPlainText( msg_top + "\n" +
                                   msg_name + "\t" + "\t" + name_display + "\n" +
                                   msg_id +  "\t" + "\t" + QString::number(id_number) + "\n" +
                                   msg_prem + "\t" + "\t" + prem_display + "\n" +
                                   msg_exp_date + "\t" + exp_date_display
                                   );

    }
}


/*****************************************************************************
* Method on_membershipExpirations_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    None.
******************************************************************************/
void manageMembers::on_membershipExpirations_clicked() {
    ui->display->clear();
    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->submitRenew->hide();
    ui->convertToPremium->hide();
    ui->id->hide();
    ui->idInput->hide();
    ui->name->hide();
    ui->nameInput->hide();
    ui->convertAll->hide();
    ui->convertOne->hide();

    ui->dateEdit->show();
    ui->submitDate->show();
}

/*****************************************************************************
* Method on_submitDate_clicked(): Class manageMembers
*  Receives no arguments.
*  Returns no values.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
*    None.
* POST-CONDITIONS
*    Displays members information inthe text browser.
******************************************************************************/
void manageMembers::on_submitDate_clicked() {
    QDate date = ui->dateEdit->date();
    QString exDate = date.toString("MM/dd/yyyy");
    std::string expDate = exDate.toStdString();

    Members_Container memberList;

    for (int i=0; i<members->get_members_count(); i++) {
        std::string d = members->_get_member(i).get_membership_expiration();
        if (d[6] == expDate[6] &&
            d[7] == expDate[7] &&
            d[8] == expDate[8] &&
            d[9] == expDate[9] &&
            d[0] == expDate[0] && d[1] == expDate[1])
            memberList.add_member(members->_get_member(i));
    }
    std::string output = "";
    std::string dues;
    // outputs temp container to display
    for (int j = 0; j < memberList.get_members_count(); j++)
    {
        if (memberList[j].is_premium_member()) {dues = "75.00";}
        else {dues = "60.00";}

        output += "Name: " + memberList[j].get_name() + "\t\t" +
                "ID: " + std::to_string(memberList[j].get_membership_number()) + "\t\t" +
                "Member Dues: " + dues + "\n";
    }

    ui->display->setText(QString::fromStdString(output));

}

void manageMembers::on_printTotalRebates_clicked()
{
    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->convertToPremium->hide();
    ui->id->hide();
    ui->idInput->hide();
    ui->name->hide();
    ui->nameInput->hide();
    ui->convertAll->hide();
    ui->convertOne->hide();

    ui->display->clear();

    sales_container premiumOnly;
    for(int i = 0; i < all_sales->size(); i++)
    {
        Member m1 = members->get_member((*all_sales)[i].getId());
        if(m1.is_premium_member())
        {
            premiumOnly.push_back((*all_sales)[i]);
        }
    }

    if(premiumOnly.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No members");
        return;
    }

    // sort by ascending membership number
    std::sort(premiumOnly.begin(), premiumOnly.end(), [](const sales& s1, const sales& s2)->bool{
        return s1.getId() > s2.getId();
    });


    QString output = "----------Total Rebates---------\n\n";
    double rebate = 0.0;
    output += "Member: ";
    output += members->get_member(premiumOnly[0].getId()).get_name().c_str();
    output += "\n";
    output += "ID: ";
    output += to_string(premiumOnly[0].getId()).c_str();
    output += "\n";
    rebate += premiumOnly[0].getPrice()*premiumOnly[0].getQuantity();
    for(int i = 1;i < premiumOnly.size(); i++)
    {
        if(premiumOnly[i-1].getId() != premiumOnly[i].getId())
        {
            output += "Rebate: $";
            output += to_string(rebate*1.05).c_str();
            output += "\n\n";
            rebate = 0.0;
            output += "Member: ";
            output += members->get_member(premiumOnly[i].getId()).get_name().c_str();
            output += "\n";
            output += "ID: ";
            output += to_string(premiumOnly[i].getId()).c_str();
            output += "\n";
        }
        rebate += premiumOnly[i].getPrice()*premiumOnly[i].getQuantity();
    }
    output += "Rebate: $";
    output += to_string(rebate*1.05).c_str();
    output += "\n\n";
    output += "Total Rebate given: $";
    output += to_string((premiumOnly.getTotalRevenue()/1.875)*1.05).c_str();
    output += "\n\n---------End Report---------";

    ui->display->setText(output);
}

void manageMembers::on_BasicToPremium_clicked()
{
    // members convert from basic to premium clicked:

    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    ui->displayButton->hide();
    ui->submitFile->hide();
    ui->submitRenew->hide();

    // convert one or all members-
    ui->convertOne->show();
    ui->convertAll->show();

    int box = 0; // if user checks converts one - box = 1; user checks converts all - box = 2
    if (ui->convertOne->isDown())
    {
        box = 1;
    }
    else if (ui->convertAll->isDown())
    {
        box = 2;
    }
    else
    {
        box = 0; // does nothing
    }

    if (box == 1)
    {
        on_convertOne_clicked();
    }
    else if (box == 2)
    {
        on_convertAll_clicked();
    }
    else
    {
        return;
    }

}

void manageMembers::on_convertOne_clicked()
{
    Members_Container member_list;

    // sees if basic members are eligible for premium
    for (int i=0; i < members->get_members_count(); i++)
    {
        if (members->get_member(i).get_total_spend() > 75.0)
        {
            member_list.add_member(members->operator[](i));
        }
    }

    ui->convertAll->hide();
    ui->convertOne->hide();

    ui->nameInput->show();
    ui->name->show();
    ui->id->show();
    ui->idInput->show();

    QString mem_number;
    QString mem_name;
    std::string output = "";

    mem_name = ui->nameInput->text();
    mem_number = ui->idInput->text();
    int id_number = mem_number.toInt();
    ui->convertToPremium->show();

    if (member_list.contains(id_number))
    {
        QMessageBox::StandardButtons confirm;
        confirm = QMessageBox::question(this, "Confirmation",
                                        "Confirm- you want to convert? ",
                                        QMessageBox::Yes|QMessageBox::No);

        if (confirm == QMessageBox::Yes)
        {
            std::string output = "";
            std::string name = "";
            name = member_list.get_member(id_number).get_name();
            output += "Now Premium member: " + name;
            output += std::to_string(id_number) + "\n";
        }
    }

    else
    {
        output += "Member not found. \n";
    }

    ui->display->setText(QString::fromStdString(output));

}

void manageMembers::on_convertAll_clicked()
{
    Members_Container member_list;

    // sees if basic members are eligible for premium
    for (int i=0; i < members->get_members_count(); i++)
    {
        if (members->get_member(i).get_total_spend() > 75.0)
        {
            member_list.add_member(members->operator[](i));
        }
    }

    ui->convertAll->hide();
    ui->convertOne->hide();

    QMessageBox::StandardButtons confirm;
    confirm = QMessageBox::question(this, "Confirmation",
                                    "Confirm- you want to convert? ",
                                    QMessageBox::Yes|QMessageBox::No);
    std::string output = "";
    double newTotalSpent = 0;
    double rebateReceived = 0;

    if (confirm == QMessageBox::Yes)
    {
        for (int i=0; i < member_list.get_members_count(); i++)
        {
            member_list.upgrade_membership(member_list[i].get_name(), member_list[i].get_membership_expiration());
            output += member_list[i].get_name() + std::to_string(member_list[i].get_membership_number()) += "\n";
            newTotalSpent = member_list.get_member(i).get_total_spend() + 15.0;
            rebateReceived = newTotalSpent * .05;
            output += " Membership Total Amount: " + std::to_string(newTotalSpent) + "\n";
            output += " Rebate amount receives: " + std::to_string(rebateReceived) + "\n\n";
        }
    }
    else
    {
        return;
    }

    ui->display->setText(QString::fromStdString(output));
}

