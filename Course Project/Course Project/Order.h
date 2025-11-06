#pragma once

#include "Supplier.h"

struct int2 
{
    int first;
    int second;
};

class Order 
{
public:
    Order();
    Order(Supplier* _supplier);

    Supplier* getSupplier() const;
    double getTotalPrice() const;

    void addItem(int _materialIndex, int _quantity);

    void calculateTotal();

    friend ostream& operator<<(ostream& os, const Order& _order);

private:
    Supplier* m_supplier;
    vector<int2> m_items;
    double m_totalPrice;
};