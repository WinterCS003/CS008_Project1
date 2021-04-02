#include "yearly_sales.h"
#include "ui_yearly_sales.h"
#include <algorithm>

yearly_sales::yearly_sales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yearly_sales)
{
    ui->setupUi(this);
}

yearly_sales::yearly_sales(QWidget *parent,
                           sales_container* all_sales,
                           Members_Container* mc,
                           inventory* iv):
    QWidget(parent),
    ui(new Ui::yearly_sales)
{
    ui->setupUi(this);
    ui->yearlyReport->hide();
    ui->goBack->hide();

    this->all_sales = all_sales;
    this->all_members = mc;
    this->all_items = iv;
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
    ui->yearlyReport->clear();
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
            int index = all_members->get_member_index((*all_sales)[i].getId());
            if(ui->basic->isChecked() && ui->preferred->isChecked())
            {
                yearlySales.push_back((*all_sales)[i]);
            }
            else if(ui->basic->isChecked())
            {
                if(!(*all_members)[index].is_premium_member())
                {
                    yearlySales.push_back((*all_sales)[i]);
                }
            }
            else if(ui->preferred->isChecked())
            {
                if((*all_members)[index].is_premium_member())
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
        QString Qyear = to_string(year).c_str();
        QMessageBox::warning(this, "Warning", "No sales found for: " + Qyear);
        switchScreen();
        return;
    }
    // find all unique sales, dont repeat names
    sales_container unique_sales;
    for(size_t i = 0; i < yearlySales.size(); i++)
    {
        if(unique_sales.find(yearlySales[i]) == -1)
        {
            unique_sales.push_back(yearlySales[i]);
        }
        else
        {
            sales s1 = yearlySales[i];
            sales* s2 = &unique_sales[unique_sales.find(yearlySales[i])];

            s2->setQuantity(s1.getQuantity() + s2->getQuantity());
        }
    }

    inventory best;
    inventory worst;
    // sort sales in descending order by quantity
    std::sort(unique_sales.begin(), unique_sales.end(), [](const sales& s1, const sales& s2) ->bool {return s1.getQuantity() > s2.getQuantity();});
    // find 5 best items by quantity
    for(size_t i = 0; i < unique_sales.size() && best.size() < 5; i++)
    {
        Item i1;
        i1 = (*all_items)[all_items->search(unique_sales[i].getItem())];
        best.push_back(i1);
    }
    // find 5 worst items by quantity
    for(int i = unique_sales.size() - 1; i >= 0 && worst.size() < 5; i--)
    {
        Item i1;
        i1 = (*all_items)[all_items->search(unique_sales[i].getItem())];
        if(!best.contains(i1.get_item_name()))
            worst.push_back(i1);
    }

    QString output = "---------------Year: ";
    output += to_string(year).c_str();
    output += "---------------\n";
    // second pass, generate output for all sales in the year
    for(unsigned int i = 0; i < yearlySales.size(); i++)
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
    // total revenue of the year
    output += "Total Revenue: $";
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
        int index = all_members->get_member_index(unique_sales[i].getId());
        temp = (*all_members)[index];
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
    output += "\nNumber of Basic Members: ";
    output += to_string(countBasic).c_str();
    output += "\n";
    // number of preferred members
    output += "Number of Premium Members: ";
    output += to_string(countPremium).c_str();
    output += "\n\n";
    // best and worst items
    output += "best items\n";
    for(int i = 0; i < best.size(); i++)
    {
        output += best[i].get_item_name().c_str();
        output += "\n";
    }
    output += "\n";
    output += "worst items\n";
    for(int i = 0; i < worst.size(); i++)
    {
        output += worst[i].get_item_name().c_str();
        output += "\n";
    }
    output += "---------------End of Report---------------";

    ui->yearlyReport->setText(output);
}
