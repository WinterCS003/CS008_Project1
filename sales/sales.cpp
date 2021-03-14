 #include "sales.h"

sales::sales()
{

}

sales::sales(const sales& s)
{
    this->date_sold = s.date_sold;
    this->item_name = s.item_name;
    this->customer_name = s.customer_name;
    this->isPreferred = s.isPreferred;
    this->price = s.price;
}

sales::sales(std::string date, std::string item, std::string customer, bool type, double pay)
{
    date_sold = date;
    item_name = item;
    customer_name = customer;
    isPreferred = type;
    price = pay;
}

sales& sales::operator=(const sales& s)
{
    this->date_sold = s.date_sold;
    this->item_name = s.item_name;
    this->customer_name = s.customer_name;
    this->isPreferred = s.isPreferred;
    this->price = s.price;

    return *this;
}

std::string sales::getDate() const
{
    return date_sold;
}

std::string sales::item() const
{
    return item_name;
}

std::string sales::customer() const
{
    return customer_name;
}

bool sales::member_type() const
{
    return isPreferred;
}
