#include "yearly_sales.h"
#include "ui_yearly_sales.h"

yearly_sales::yearly_sales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yearly_sales)
{
    ui->setupUi(this);
}

yearly_sales::yearly_sales(QWidget *parent,
                           sales_container* all_sales,
                           Members_Container* mc):
    QWidget(parent),
    ui(new Ui::yearly_sales)
{
    ui->setupUi(this);
    ui->yearlyReport->hide();
    ui->goBack->hide();

    this->all_sales = all_sales;
    this->all_members = mc;
}

yearly_sales::~yearly_sales()
{
    delete ui;
}

void yearly_sales::switchScreen()
{
    // if on input screen
    if(ui->yearlyReport->isHidden())
    {
        ui->year->hide();
        ui->yearInput->hide();
        ui->preferred->hide();
        ui->basic->hide();
        ui->submit->hide();
        ui->yearlyReport->show();
        ui->goBack->show();
    }
    // if on report screen
    else
    {
        ui->year->show();
        ui->yearInput->show();
        ui->preferred->show();
        ui->basic->show();
        ui->submit->show();
        ui->yearlyReport->hide();
        ui->goBack->hide();
    }
}

void yearly_sales::clearInput()
{
    ui->yearInput->clear();
}

void yearly_sales::on_goBack_clicked()
{
    switchScreen();
}

void yearly_sales::on_submit_clicked()
{
    int year = ui->yearInput->value();
    if(year == 0)
    {
        QMessageBox::warning(this, "Warning", "Please input a valid Year");
        return;
    }
    switchScreen();
    clearInput();

    sales_container yearlySales;
    // first pass - find all sales on the given year
    for(unsigned int i = 0; i < all_sales->size(); i++)
    {
        if(to_string(year)== (*all_sales)[i].getDate().substr(6,4))
        {
            if(ui->basic->isChecked() && ui->preferred->isChecked())
            {
                yearlySales.push_back((*all_sales)[i]);
            }
            else if(ui->basic->isChecked())
            {
                if(!all_members->get_member((*all_sales)[i].getId()).is_premium_member())
                {
                    yearlySales.push_back((*all_sales)[i]);
                }
            }
            else if(ui->preferred->isChecked())
            {
                if(all_members->get_member((*all_sales)[i].getId()).is_premium_member())
                {
                    yearlySales.push_back((*all_sales)[i]);
                }
            }
            else
            {
                yearlySales.push_back((*all_sales)[i]);
            }
        }
    }
    // quit function with warning if no sales, return to input
    if(yearlySales.size() == 0)
    {
        QMessageBox::warning(this, "Warning", "No sales found for: " + year);
        switchScreen();
        return;
    }
    QString output = "---------------Year: ";
    output += to_string(year).c_str();
    output += "---------------\n";
    // second pass, generate output for all sales in the year
    for(unsigned int i = 0; i < yearlySales.size(); i++)
    {
        if(!output.contains(yearlySales[i].getItem().c_str()))
        {
            // Item name
            output += "Item Name: ";
            output += yearlySales[i].getItem().c_str();
            output += "\n";

            // Item Quantity
            output += "Item Quantity: ";
            output += to_string(yearlySales.getItemQuantity(yearlySales[i].getItem())).c_str();
            output += "\n\n";
        }
    }
    // total revenue of the year
    output += "Total Revenue: ";
    output += to_string(yearlySales.getTotalRevenue()).c_str();
    output+= "\n\n";

    // list of members
    output += "List of Members:\n";
    Member temp;
    QString memberName;
    int countPremium = 0;
    int countBasic = 0;
    // all members who shopped
    for(unsigned int i = 0; i < yearlySales.size(); i++)
    {
        temp = all_members->get_member((yearlySales[i].getId()));
        memberName = temp.get_name().c_str();
        if(!output.contains(memberName))
        {
            if(temp.is_premium_member())
            {
                countPremium++;
            }
            else
            {
                countBasic++;
            }
            output += memberName;
            output += "\n";
        }
    }
    // number of basic members
    output += "Number of Basic Members: ";
    output += to_string(countBasic).c_str();
    output += "\n";
    // number of preferred members
    output += "Number of Premium Members: ";
    output += to_string(countPremium).c_str();
    output += "\n\n";
    output += "---------------End of Report---------------";

    ui->yearlyReport->setText(output);
}
