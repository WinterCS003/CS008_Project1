#include "managemembers.h"
#include "ui_managemembers.h"

manageMembers::manageMembers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manageMembers)
{
    ui->setupUi(this);
}

manageMembers::manageMembers(QWidget *parent, Members_Container* mc)
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
    members = mc;

}

manageMembers::~manageMembers()
{
    delete ui;
}

// displays text fields to get user input
void manageMembers::on_button_addMember_clicked()
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

// add member to member container
void manageMembers::on_submit_clicked()
{
    QString mem_number;
    QString mem_name;

    mem_name = ui->input_1_name->toPlainText();
    mem_number = ui->input_2_mem_ID->toPlainText();

    std::string name = mem_name.toStdString();
    int number = mem_number.toInt();

    members->add_member(Member(name,number, false, ""));

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
    ui->input_3_prem->clear();
    ui->input_4_exp_dat->clear();
    ui->input_5_total_spend->clear();
    ui->input_6_rebate_amt->clear();
}

void manageMembers::on_membersFromFile_clicked() {
    ui->label_1_name->show();
    ui->input_1_name->show();
    ui->submitFile->show();

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
}

void manageMembers::on_submitFile_clicked() {

    QString input;
    input =  ui->input_1_name->toPlainText();
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

void manageMembers::on_button_delete_Member_clicked()
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


    ui->label_1_name->show();
    ui->label_2_mem_ID->show();
    ui->input_1_name->show();
    ui->input_2_mem_ID->show();
    ui->submitDelete->show();
}

void manageMembers::on_submitDelete_clicked()
{
    QString mem_number;
    QString mem_name;

    mem_name = ui->input_1_name->toPlainText();
    mem_number = ui->input_2_mem_ID->toPlainText();

    std::string name = mem_name.toStdString();
    int number = mem_number.toInt();

    ui->label_2_mem_ID->hide();
    ui->input_2_mem_ID->hide();
    ui->submitDelete->hide();

    members->remove_member(number);

    int count = members->get_members_count();
    QString msg = "Deleted! Total members: ";

//    ui->display->setPlainText(QString::fromStdString(msg));
    ui->display->setPlainText(msg + QString::number(count));

}

void manageMembers::on_viewMemberInfo_clicked()
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

    ui->display->clear();
    ui->label_1_name->show();
    ui->input_1_name->show();
    ui->label_2_mem_ID->show();
    ui->input_2_mem_ID->show();
    ui->displayButton->show();
}

void manageMembers::on_displayButton_clicked() {
    QString mem_number;
    QString mem_name;

    mem_name = ui->input_1_name->toPlainText();
    mem_number = ui->input_2_mem_ID->toPlainText();

    int id_number = mem_number.toInt();

    if (members->contains(id_number)) {

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
        ui->display->setPlainText("Member with that ID does not exist.");
}

void manageMembers::on_membersConvToBasic_clicked()
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

    Members_Container memberList;

    for (int i = 0; i < members->get_members_count(); i++)
    {
        // checks if the member's rebates is less than the difference in
        // annual fees, if yes, add to temp container
        if (members->operator[](i).get_total_rebates() < 15)
        {
            memberList.add_member(members->operator[](i));
        }
    }

    std::string output = "";

    // outputs temp container to display
    for (int j = 0; j < memberList.get_members_count(); j++)
    {
        output += memberList[j].get_name() + std::to_string(memberList[j].get_membership_number()) + "\n";
    }

    ui->display->setText(QString::fromStdString(output));
}
