#include "yearly_sales.h"
#include "ui_yearly_sales.h"
#include <algorithm>

/****************************************************************
 * explicit yearly_sales(QWidget *parent = nullptr);
 *
 *   Constructor; Initialize class attributes
 *
 *   Parameters: parent (QWidget*) // IN - pointer to window
 *
 *   Return: none
 ***************************************************************/
yearly_sales::yearly_sales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yearly_sales)
{
    ui->setupUi(this);
}

/****************************************************************
 * yearly_sales(QWidget *parent,
 *              sales_container* all_sales,
 *              Members_Container* mc,
 *              inventory* iv);
 *
 *   Constructor; Initialize class attributes, create new window
 *
 *   Parameters: QWidget *parent, // IN - pointer to window
 *               sales_container* all_sales, // IN - all sales made
 *               Members_Container* mc, // IN - all members
 *               inventory* iv // IN - all items in stock
 *   Return: none
 ***************************************************************/
yearly_sales::yearly_sales(QWidget *parent, // IN - pointer to window
                           sales_container* all_sales, // IN - all sales made
                           Members_Container* mc, // IN - all members
                           inventory* iv): // IN - all items in stock
    QWidget(parent),
    ui(new Ui::yearly_sales)
{
    ui->setupUi(this);

    this->all_sales = all_sales;
    this->all_members = mc;
    this->all_items = iv;
}

/****************************************************************
 * ~yearly_sales();
 *   Destructor; Frees memory used by ui, widget pointer
 *   Parameters: none
 *   Return: none
 ***************************************************************/
yearly_sales::~yearly_sales()
{
    delete ui;
}

/****************************************************************
 * void clearInput();
 *
 *   Accessor; This method will clear all input from the user
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
void yearly_sales::clearInput()
{
    ui->yearInput->clear();
    ui->yearlyReport->clear();
}

/****************************************************************
 * void on_submit_clicked();
 *
 *   Accessor; This method will take user input and generate a
 *             report of all yearly sales made
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none - report is output to window
 ***************************************************************/
void yearly_sales::on_submit_clicked()
{
    int year = ui->yearInput->value();
    if(year == 0)
    {
        QMessageBox::warning(this, "Warning", "Please input a valid Year");
        return;
    }
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
        return;
    }
    // find all unique sales, dont repeat names
    sales_container unique_sales;
    for(size_t i = 0; i < yearlySales.size(); i++)
    {
        int index = unique_sales.find(yearlySales[i].getItem());
        if(index == -1)
        {
            unique_sales.push_back(yearlySales[i]);
        }
        else
        {
            sales s1 = yearlySales[i];
            sales* s2 = &unique_sales[index];

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
    for(unsigned int i = 0; i < unique_sales.size(); i++)
    {
        // Item name
        output += "Item Name: ";
        output += unique_sales[i].getItem().c_str();
        output += "\n";

        // Item Quantity
        output += "Item Quantity: ";
        output += to_string(unique_sales.getItemQuantity(unique_sales[i].getItem())).c_str();
        output += "\n\n";
    }
    // total revenue of the year
    output += "Total Revenue: $";
    double revenue = std::ceil(unique_sales.getTotalRevenue()*100.0)/100.0;
    std::string rev = to_string(revenue);
    rev = rev.substr(0, rev.find(".")+3);
    output += QString::fromStdString(rev);
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
        int index = all_members->get_member_index(yearlySales[i].getId());
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
    output += "----------best items-----------\n";
    for(int i = 0; i < best.size(); i++)
    {
        output += best[i].get_item_name().c_str();
        output += "\n";
    }
    output += "\n";
    output += "----------worst items----------\n";
    for(int i = 0; i < worst.size(); i++)
    {
        output += worst[i].get_item_name().c_str();
        output += "\n";
    }
    output += "\n\n---------------End of Report---------------";

    ui->yearlyReport->setText(output);
}
