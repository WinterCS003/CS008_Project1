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

    // tests to make sure window works, DELETE LATER
    sales temp1("03/01/2021", 0, "penguin", 1.0, 1);
    sales temp2("03/01/2021", 1, "seal", 2.0, 1);
    sales temp3("03/02/2021", 2, "walrus", 10.0, 2);
    sc->push_back(temp1);
    sc->push_back(temp2);
    sc->push_back(temp3);
    Member member1("Alice", 1, true, "01/02/2023", 0.0, 60.0);
    Member member2("Bob", 2, false, "04/05/2026", 0.0, 60.0);
    Member member3("Charles", 3, true, "07/08/2029", 0.0, 60.0);
    mc->add_member(member1);
    mc->add_member(member2);
    mc->add_member(member3);

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
    bool preferred = false;

    if(ui->preferred->isChecked())
    {
        preferred = true;
    }

    generate_daily_daily_sales(sdDate);
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

void daily_sales::generate_daily_daily_sales(std::string date)
{
    report_output = report_output.fromStdString(("----------Date: " + date + "----------\n\n"));
    sales_container dailySale;

    // first pass - finds all sales made on the given date
    for(size_t i = 0; i < report->size(); i++)
    {
        if(date == (*report)[i].getDate())
        {
            dailySale.push_back((*report)[i]);
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
    // second pass - make report of all items sold
    for(size_t i = 0; i < dailySale.size(); i++)
    {
        if(!report_output.contains(dailySale[i].getItem().c_str()))
        {
            // Item name
            report_output += "Item Name: ";
            report_output += dailySale[i].getItem().c_str();
            report_output += "\n";

            // Item Quantity
            report_output += "Item Quantity: ";
            report_output += to_string(dailySale.getItemQuantity(dailySale[i].getItem())).c_str();
            report_output += "\n\n";
        }
    }
    // total revenue of all sales on the given date
    report_output += "Total Revenue: ";
    report_output += to_string(dailySale.getTotalRevenue()).c_str();
    report_output += "\n\n";

    report_output += "List of Members:\n";
    Member temp;
    QString memberName;
    int countPremium = 0;
    int countBasic = 0;
    // Members who shopped
    for(unsigned int i = 0; i < dailySale.size(); i++)
    {
        temp = members->get_member(dailySale[i].getId());
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
