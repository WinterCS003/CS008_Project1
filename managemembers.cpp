#include "managemembers.h"
#include "ui_managemembers.h"

manageMembers::manageMembers(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manageMembers)
{
    ui->setupUi(this);
//    ui->label->hide();
//    ui->label_2->hide();
//    ui->label_3->hide();
//    ui->label_4->hide();
//    ui->label_5->hide();
//    ui->label_6->hide();
//    ui->nameInput->hide();
//    ui->memberNumInput->hide();
//    ui->memberTypeInput->hide();
//    ui->memberExpireDateInput->hide();
//    ui->totalAmtSpentInput->hide();
//    ui->rebateAmountInput->hide();
//    ui->submit->hide();

}

manageMembers::manageMembers(QWidget *parent, const Members_Container& mc)
    : QMainWindow(parent)
    , ui(new Ui::manageMembers)
{
    ui->setupUi(this);
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->nameInput->hide();
    ui->memberNumInput->hide();
    ui->memberTypeInput->hide();
    ui->memberExpireDateInput->hide();
    ui->totalAmtSpentInput->hide();
    ui->rebateAmountInput->hide();
    ui->submit->hide();
    ui->submitDelete->hide();
    members = mc;
}

manageMembers::~manageMembers()
{
    delete ui;
}

// displays text fields to get user input
void manageMembers::on_addMemberButton_clicked()
{
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->nameInput->show();
    ui->memberNumInput->show();
    ui->memberTypeInput->show();
    ui->memberExpireDateInput->show();
    ui->totalAmtSpentInput->show();
    ui->rebateAmountInput->show();
    ui->submit->show();
    ui->display->clear();

}

// add member to member container
void manageMembers::on_submit_clicked()
{
    std::string name = ui->nameInput->toPlainText().toStdString();
    int ID = ui->memberNumInput->toPlainText().toInt();
    std::string prem = ui->memberTypeInput->toPlainText().toStdString();
    std::string expDate = ui->memberExpireDateInput->toPlainText().toStdString();
    double totalSpent = ui->totalAmtSpentInput->toPlainText().toDouble();
    double totalRebate = ui->rebateAmountInput->toPlainText().toDouble();
    if (prem == "y" || prem == "Y")
    {
        members.add_member(Member(name, ID, true, expDate, totalSpent, totalRebate));
    }
    else
    {
        members.add_member(Member(name, ID, false, expDate, totalSpent, totalRebate));
    }

//     tests if member is added

    std::string count = std::to_string(members.get_members_count());
    std::string msg = "Added! Total members: " + count;

    ui->display->setPlainText(QString::fromStdString(msg));
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->nameInput->hide();
    ui->memberNumInput->hide();
    ui->memberTypeInput->hide();
    ui->memberExpireDateInput->hide();
    ui->totalAmtSpentInput->hide();
    ui->rebateAmountInput->hide();
    ui->submit->hide();
    ui->nameInput->clear();
    ui->memberNumInput->clear();
    ui->memberTypeInput->clear();
    ui->memberExpireDateInput->clear();
    ui->totalAmtSpentInput->clear();
    ui->rebateAmountInput->clear();
}

void manageMembers::on_deleteMemberButton_clicked()
{
    ui->label_2->show();
    ui->memberNumInput->show();
    ui->submitDelete->show();
    ui->display->clear();
}

void manageMembers::on_submitDelete_clicked()
{
    ui->label_2->hide();
    ui->memberNumInput->hide();
    ui->submitDelete->hide();
    ui->memberNumInput->clear();

    // remove_member method broken, memory leak
    if (members.contains(ui->memberNumInput->toPlainText().toInt()))
    {
        members.remove_member(ui->memberNumInput->toPlainText().toInt());
    }
    std::string count = std::to_string(members.get_members_count());
    std::string msg = "Deleted! Total members: " + count;

    ui->display->setPlainText(QString::fromStdString(msg));
}

void manageMembers::on_viewMemberInfo_clicked()
{
    ui->display->clear();
    ui->label_2->show();
    ui->memberNumInput->show();
}
