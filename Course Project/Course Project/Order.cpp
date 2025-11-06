#include "Order.h"

Order::Order()
{
	m_supplier = nullptr;
	m_items = vector<int2>();
	m_totalPrice = 0.0;
}

Order::Order(Supplier* _supplier)
{
	m_supplier = _supplier;
	m_items = vector<int2>();
	m_totalPrice = 0.0;
}

Supplier* Order::getSupplier() const
{
	return m_supplier;
}

double Order::getTotalPrice() const
{
	return m_totalPrice;
}

void Order::addItem(int _materialIndex, int _quantity)
{
	if (_quantity <= 0) 
	{
		throw invalid_argument("The quantity must be a positive number!");
	}
	m_items.push_back({ _materialIndex, _quantity });
	calculateTotal();
}

void Order::calculateTotal()
{
	m_totalPrice = 0.0;
	const auto& materials = m_supplier->getMaterials();
	for (const auto& item : m_items) 
	{
		if (item.first < materials.size()) 
		{
			m_totalPrice += materials[item.first].getPrice() * item.second;
		}
	}
}

ostream& operator<<(ostream& os, const Order& _order)
{
    os << endl 
	   << "╔════════════════════════════════════════════════════════════════╗" << endl;
    os << "║                           ORDER                                ║" << endl;
    os << "╠════════════════════════════════════════════════════════════════╣" << endl;
    os << "║ Supplier: " << _order.m_supplier->getName() << endl;
    os << "║ Bulstat: " << _order.m_supplier->getBulstat() << endl;
    os << "─────────────────────────────────────────────────────────────────" << endl;

    const auto& materials = _order.m_supplier->getMaterials();
    os << "  Material Type Quantity Unit Price Total Price" << endl;
    os << "─────────────────────────────────────────────────────────────────" << endl;

    for (const auto& item : _order.m_items) 
	{
        const auto& material = materials[item.first];
		os << "   " << material.getMaterialName() << "   " << material.getType() << "   " << item.second << "   "
            << material.getPrice() << " lv   " << (material.getPrice() * item.second) << " lv" << endl;
    }

    os << "╔════════════════════════════════════════════════════════════════╗" << endl;
    os << "║ TOTAL PRICE: "  << _order.m_totalPrice << " lv" << endl;
    os << "╚════════════════════════════════════════════════════════════════╝" << endl;

    return os;
}
