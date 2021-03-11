#ifndef SALES_CONTAINER_H
#define SALES_CONTAINER_H

#include "sales.h"

class sales_container
{
    public:
        sales_container(size_t number_sales);
        ~sales_container();
        bool add_sale(const sales& add);

    private:
        sales* all_sales;
        size_t number_sales;
};

#endif // SALES_CONTAINER_H
