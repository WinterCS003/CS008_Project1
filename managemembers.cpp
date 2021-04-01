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
    , members(mc)
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
    std::string name = ui->input_1_name->toPlainText().toStdString();
    int mem_number = ui->input_2_mem_ID->toPlainText().toInt();
    bool isPremium;
    ui->label_3_prem->text().toStdString() == "y" ? isPremium = true : isPremium = false;
    std::string expiration = ui->label_4_exp_dat->text().toStdString();

    Member temp(name, mem_number, isPremium, expiration);
    members->add_member(temp);

    ui->display->setPlainText(QString::fromStdString("Added! Total members: "));
    ui->display->setPlainText(QString::number(members->get_members_count()));
    switchScreen();
}

void manageMembers::switchScreen()
{
    if(!ui->label_1_name->isHidden()){
        ui->label_1_name->hide();
        ui->label_2_mem_ID->hide();
        ui->label_3_prem->hide();
        ui->label_4_exp_dat->hide();
        ui->label_5_total_spend->hide();
        ui->label_6_rebate_amt->hide();
        ui->submit->hide();
        ui->input_1_name->clear();
        ui->input_2_mem_ID->clear();
        ui->input_3_prem->clear();
        ui->input_4_exp_dat->clear();
        ui->input_5_total_spend->clear();
        ui->input_6_rebate_amt->clear();
    }
    else{
        ui->label_1_name->show();
        ui->label_2_mem_ID->show();
        ui->label_3_prem->show();
        ui->label_4_exp_dat->show();
        ui->label_5_total_spend->show();
        ui->label_6_rebate_amt->show();
        ui->submit->show();
    }
}

void manageMembers::on_submitDelete_clicked()
{
//    ui->label_2_mem_ID->hide();
//    ui->input_2_mem_ID->hide();
//    ui->submitDelete->hide();

//    //is this the problem??
//    //clearing the input before passing to to the remove member function
//    ui->input_2_mem_ID->clear();

    members->remove_member(ui->input_2_mem_ID->toPlainText().toInt());

    std::string count = std::to_string(members->get_members_count());

    std::string msg = "Deleted! Total members: ";

    ui->display->setPlainText(QString::fromStdString(msg));
    ui->display->setPlainText(QString::fromStdString(count));

}

void manageMembers::on_viewMemberInfo_clicked()
{
    ui->display->clear();
    ui->label_2_mem_ID->show();
    ui->input_2_mem_ID->show();
    ui->displayButton->show();
}

void manageMembers::on_button_delete_Member_clicked()
{
    ui->label_1_name->hide();
    ui->label_2_mem_ID->hide();
    ui->label_3_prem->hide();
    ui->label_4_exp_dat->hide();
    ui->label_5_total_spend->hide();
    ui->label_6_rebate_amt->hide();
    ui->submit->hide();
    ui->input_1_name->clear();
    ui->input_2_mem_ID->clear();
    ui->input_3_prem->clear();
    ui->input_4_exp_dat->clear();
    ui->input_5_total_spend->clear();
    ui->input_6_rebate_amt->clear();
    ui->input_1_name->hide();
    ui->input_2_mem_ID->hide();
    ui->input_3_prem->hide();
    ui->input_4_exp_dat->hide();
    ui->input_5_total_spend->hide();
    ui->input_6_rebate_amt->hide();

    ui->label_2_mem_ID->show();
    ui->input_2_mem_ID->show();
    ui->submitDelete->show();
    ui->display->clear();
    ui->displayButton->hide();
}
