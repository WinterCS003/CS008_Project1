 #include "sales.h"

sales::sales()
{

}

sales::sales(std::string date, std::string item, size_t ID, double sales_tax, std::string member, bool type, int invoice)
{
    date_sold = date;
    item_name = item;
    this->ID = ID;
    this->sales_tax = sales_tax;
    this->customer_name = member;
    isPreferred = type;
    SalesInvoiceNumber = invoice;
}

