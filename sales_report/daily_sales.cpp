#include "daily_sales.h"
#include "ui_daily_sales.h"

daily_sales::daily_sales(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::daily_sales)
{
    ui->setupUi(this);
    ui->report->hide();
    ui->goBack->hide();
}

daily_sales::daily_sales(QWidget *parent, sales_container* sc, Members_Container* mc)
    : QWidget(parent)
    , ui(new Ui::daily_sales)
{
    ui->setupUi(this);
    ui->report->hide();
    ui->goBack->hide();

    report = sc;
    members = mc;
}

daily_sales::~daily_sales()
{
    delete ui;
}

void daily_sales::on_submit_clicked()
{
    switchScreen();

    QDate date = ui->dateEdit->date();
    QString sDate = date.toString("MM/dd/yyyy");
    std::string sdDate = sDate.toStdString();

    int flag = 2;
    if(ui->basic->isChecked() && ui->preferred->isChecked())
    {
        flag = 2;
    }
    else if(ui->preferred->isChecked())
    {
        flag = 1;
    }
    else if(ui->basic->isChecked())
    {
        flag = 0;
    }
    else
    {
        flag = 2;
    }
    generate_daily_daily_sales(sdDate, flag);
}

void daily_sales::switchScreen()
{
    if(ui->report->isHidden())
    {
        ui->date->hide();
        ui->dateEdit->hide();
        ui->preferred->hide();
        ui->basic->hide();
        ui->submit->hide();
        ui->report->show();
        ui->goBack->show();
    }
    else
    {
        ui->report->hide();
        ui->date->show();
        ui->dateEdit->show();
        ui->preferred->show();
        ui->basic->show();
        ui->submit->show();
        ui->goBack->hide();
    }
}

// flag - 0 = Basic only
//        1 = Preferred
//        2 = both
void daily_sales::generate_daily_daily_sales(std::string date, int flag)
{
    report_output = report_output.fromStdString(("----------Date: " + date + "----------\n\n"));
    sales_container dailySale;

    // first pass - finds all sales made on the given date
    for(size_t i = 0; i < report->size(); i++)
    {
        if(date == (*report)[i].getDate())
        {
            int index = members->get_member_index((*report)[i].getId());
            if(flag == 0) // only basic members
            {
                if(!(*members)[index].is_premium_member())
                {
                    dailySale.push_back((*report)[i]);
                }
            }
            else if(flag == 1) // only preferred members
            {
                if(!(*members)[index].is_premium_member())
                {
                    dailySale.push_back((*report)[i]);
                }
            }
            else // both members
            {
                dailySale.push_back((*report)[i]);
            }
        }
    }
    // check if no sales were made on the date
    if(dailySale.size() == 0)
    {
        QString warning = date.c_str();
        QMessageBox::warning(this, "Warning", "No sales made on: " + warning);
        switchScreen();
        return;
    }

    sales_container unique_sales;
    for(size_t i = 0; i < dailySale.size(); i++)
    {
        if(unique_sales.find(dailySale[i]) == -1)
        {
            unique_sales.push_back(dailySale[i]);
        }
        else
        {
            sales s1 = dailySale[i];
            sales* s2 = &unique_sales[unique_sales.find(dailySale[i])];

            s2->setQuantity(s1.getQuantity() + s2->getQuantity());
        }
    }

    // second pass - make report of all items sold
    for(size_t i = 0; i < unique_sales.size(); i++)
    {
        // Item name
        report_output += "Item Name: ";
        report_output += unique_sales[i].getItem().c_str();
        report_output += "\n";

        // Item Quantity
        report_output += "Item Quantity: ";
        report_output += to_string(unique_sales.getItemQuantity(unique_sales[i].getItem())).c_str();
        report_output += "\n\n";
    }
    // total revenue of all sales on the given date
    report_output += "Total Revenue: ";
    report_output += to_string(unique_sales.getTotalRevenue()).c_str();
    report_output += "\n\n";

    report_output += "List of Members:\n";
    Member temp;
    QString memberName;
    int countPremium = 0;
    int countBasic = 0;
    // Members who shopped
    for(unsigned int i = 0; i < dailySale.size(); i++)
    {
        int index = members->get_member_index(dailySale[i].getId());
        temp = (*members)[index];
        memberName = temp.get_name().c_str();
        if(!report_output.contains(memberName))
        {
            if(temp.is_premium_member())
            {
                countPremium++;
            }
            else
            {
                countBasic++;
            }
            report_output += memberName;
            report_output += "\n";
        }
    }
    // number of basic members
    report_output += "Number of Basic Members: ";
    report_output += to_string(countBasic).c_str();
    report_output += "\n";
    // number of preferred members
    report_output += "Number of Premium Members: ";
    report_output += to_string(countPremium).c_str();
    report_output += "\n\n";
    report_output += "----------End of report----------";

    ui->report->show();
    ui->report->setText(report_output);
}

void daily_sales::on_goBack_clicked()
{
    switchScreen();
}
