#include "memberpurchase.h"
#include "ui_memberpurchase.h"

memberPurchase::memberPurchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memberPurchase)
{
    ui->setupUi(this);
}

memberPurchase::memberPurchase(QWidget *parent,
                               sales_container* sc,
                               Members_Container* mc,
                               inventory* iv):
    QWidget(parent),
    ui(new Ui::memberPurchase),
    all_sales(sc),
    all_members(mc),
    all_items(iv)
{
    ui->setupUi(this);

    ui->report->hide();
    ui->back->hide();
}

memberPurchase::~memberPurchase()
{
    delete ui;
}

void memberPurchase::on_back_clicked()
{
    switchScreen();
}

void memberPurchase::on_submit_clicked()
{
    switchScreen();
    if(ui->allMembers->isChecked())
    {
        allMemberReport();
    }
    else
    {
        std::string name = ui->nameInput->text().toStdString();
        unsigned int id = ui->id->value();
        if(name.length() == 0)
        {
            if(!all_members->contains(id))
            {
                QMessageBox::warning(this, "Warning", "Member not found");
                return;
            }
            singleMemberReport(id);
        }
        else
        {
            if(!all_members->contains(name))
            {
                QMessageBox::warning(this, "Warning", "Member not found");
                return;
            }
            singleMemberReport(name);
        }
    }
}

void memberPurchase::singleMemberReport(std::string name)
{
    sales_container output;
    for(size_t i = 0; i < all_sales->size(); i++)
    {
        Member m1 = all_members->get_member((*all_sales)[i].getId());
        if(m1.get_name() == name){
            output.push_back((*all_sales)[i]);
        }
    }

    if(output.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No sales made by member");
        return;
    }

}

void memberPurchase::singleMemberReport(unsigned int id)
{
    Members_Container output;
    for(size_t i = 0; i < all_members->get_members_count(); i++)
    {

    }
}

void memberPurchase::allMemberReport()
{

}
void memberPurchase::switchScreen()
{
    // on report screen
    if(ui->submit->isHidden())
    {
        ui->report->hide();
        ui->back->hide();
        ui->nameLabel->show();
        ui->nameInput->show();
        ui->idLabel->show();
        ui->id->show();
        ui->allMembers->show();
        ui->submit->show();
    }
    else
    {
        ui->report->show();
        ui->back->show();
        ui->nameLabel->hide();
        ui->nameInput->hide();
        ui->idLabel->hide();
        ui->id->hide();
        ui->allMembers->hide();
        ui->submit->hide();
    }
}
