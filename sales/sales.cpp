 #include "sales.h"

/****************************************************************
 * sales();
 *   Constructor; Initialize class attributes
 *   Parameters: none
 *   Return: none
 ***************************************************************/
sales::sales()
{
    item_name = "";
    date_sold = "";
    price = 0.0;
    quantity = 0;
    member_ID = 0;
}

/****************************************************************
 * sales(const sales& s);
 *   Constructor; copy constructor
 *   Parameters: s (sales&) - sales object to copy from
 *   Return: none
 ***************************************************************/
sales::sales(const sales& s)
{
    this->date_sold = s.date_sold;
    this->item_name = s.item_name;
    this->price = s.price;
    this->quantity = s.quantity;
    this->member_ID = s.member_ID;
}

/****************************************************************
 * sales(std::string date,
 *       int id,
 *       std::string item,
 *       double price,
 *       int quantity,
 *       std::string customer,
 *       bool type);
 *   Constructor; Initialize class attributes with custom values
 *   Parameters: date (std::string) // IN - date of sale
 *               id (int) // IN - id of item
 *               item (std::string) // IN - item name
 *               price (double) // IN - price of item
 *               quantity (int) // IN - number of items bought
 *               customer (std::string) // IN - customer name
 *               type (bool) // IN - membership type
 *   Return: none
 ***************************************************************/
sales::sales(std::string date, int id, std::string item, double price, int quantity)
{
    date_sold = date;
    member_ID = id;
    item_name = item;
    this->price = price;
    this->quantity = quantity;
}

/*******************************************************************
 * sales& operator=(const sales& s);
 *
 *   Mutator; This method will assign all values in this sales object
 *     with the sales passed in the parameter
 *------------------------------------------------------------------
 *   Parameter: s (sales&) // IN – sales object to assign from
 *------------------------------------------------------------------
 *   Return: reference to this object is returned
 *******************************************************************/
sales& sales::operator=(const sales& s)
{
    this->date_sold = s.date_sold;
    this->item_name = s.item_name;
    this->member_ID = s.member_ID;
    this->price = s.price;

    return *this;
}

/****************************************************************
 * std::string getDate() const;
 *
 *   Accessor; This method will return the date attribute in
 *     dd/mm/yyyy format
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: date_sold (std::string)
 ***************************************************************/
std::string sales::getDate() const
{
    return date_sold;
}

/****************************************************************
 * int getId() const;
 *
 *   Accessor; This method will return the item id
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: item_ID(int)
 ***************************************************************/
int sales::getId() const
{
    return member_ID;
}

/****************************************************************
 * std::string getItem() const;
 *
 *   Accessor; This method will return the name of the item
 *   bought
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: item_name (std::string)
 ***************************************************************/
std::string sales::getItem() const
{
    return item_name;
}

/****************************************************************
 * double getPrice() const;
 *
 *   Accessor; This method will return the price of the item
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: price (double)
 ***************************************************************/
double sales::getPrice() const
{
    return price;
}

/****************************************************************
 * int getQuantity() const;
 *
 *   Accessor; This method will return how much of an item was
 *   bought by the customer
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: quantity (int) - number of items bought
 ***************************************************************/
int sales::getQuantity() const
{
    return quantity;
}

/****************************************************************
 * double getRevenue() const;
 *
 *   Accessor; This method will return the total revenue from
 *   this particular sale
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: revenue (double)
 ***************************************************************/
double sales::getRevenue() const
{
    return quantity*price*(1+sales_tax);
}

/****************************************************************
 * bool operator==(const sales& s) const;
 *
 *   Accessor; This method will return true if the parameter is
 *   equal to this object
 * --------------------------------------------------------------
 *   Parameters: s (sales&) // IN - sales to compare to
 * --------------------------------------------------------------
 *   Return: is equal (bool) - returns true if this object is
 *                             equal to the parameter
 ***************************************************************/
bool sales::operator==(const sales& s) const
{
    if(s.getItem()     == this->item_name     &&
       s.getDate()     == this->date_sold     &&
       s.getPrice()    == this->price         &&
       s.getQuantity() == this->quantity      &&
       s.getId()       == this->member_ID)
    {
        return true;
    }

    return false;
}
