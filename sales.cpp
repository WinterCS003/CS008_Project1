 #include "sales.h"

sales::sales(std::string date, item* item, size_t ID, double sales_tax, member* customer, int invoice)
{
    date_sold = date;
    item_sold = item;
    this->ID = ID;
    this->sales_tax = sales_tax;
    this->customer = customer;
    SalesInvoiceNumber = invoice;
}

sales::~sales()
{
    item_sold = nullptr;
    customer  = nullptr;
}
