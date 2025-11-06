#include "Supplier.h"

Supplier::Supplier()
{
	m_bulstat = "000000000";
	m_name = "Unknown";
	m_location = "Unknown";
	m_phone = "0000000000";

	m_materials = vector<OpticalMaterial>();
}

Supplier::Supplier(string _bulstat, string _name, string _location, string _phone)
{
	setBulstat(_bulstat);
	setName(_name);
	setLocation(_location);
	setPhone(_phone);

	m_materials = vector<OpticalMaterial>();
}

string Supplier::getBulstat() const
{
	return m_bulstat;
}

string Supplier::getName() const
{
	return m_name;
}

string Supplier::getLocation() const
{
	return m_location;
}

string Supplier::getPhone() const
{
	return m_phone;
}

vector<OpticalMaterial> Supplier::getMaterials() const
{
	return m_materials;
}

void Supplier::setBulstat(string _bulstat)
{
	if (_bulstat.length() < 9 || _bulstat.length() > 13) 
	{
		throw invalid_argument("The bulstat must be between 9 and 13 symbols!");
	}
	for (char c : _bulstat) 
	{
		if (!isdigit(c)) 
		{
			throw invalid_argument("The bulstat must be only digits!");
		}
	}
	m_bulstat = _bulstat;
}

void Supplier::setName(string _name)
{
	if (_name.empty()) 
	{
		throw invalid_argument("The name can't be empty!");
	}
	m_name = _name;
}

void Supplier::setLocation(string _location)
{
	if (_location.empty()) 
	{
		throw invalid_argument("The location can't be empty!");
	}
	m_location = _location;
}

void Supplier::setPhone(string _phone)
{
	if (_phone.length() < 10) 
	{
		throw invalid_argument("The phone number must have at least 10 symbols!");
	}
	m_phone = _phone;
}

void Supplier::addMaterial(const OpticalMaterial& _material)
{
	m_materials.push_back(_material);
}

ostream& operator<<(ostream& os, const Supplier& _supplier)
{
	os << endl 
	   << "════════════════════════════════════════════════════════════════" << endl;
	os << "Bulstat: " << _supplier.m_bulstat << endl;
	os << "Name: " << _supplier.m_name << endl;
	os << "Location: " << _supplier.m_location << endl;
	os << "Phone: " << _supplier.m_phone << endl;
	os << "Number of materials : " << _supplier.m_materials.size() << endl;
	os << "════════════════════════════════════════════════════════════════" << endl;
	return os;
}

void Supplier::saveToFile(fstream& file) const
{
	file << m_bulstat << endl;
	file << m_name << endl;
	file << m_location << endl;
	file << m_phone << endl;
	file << m_materials.size() << endl;
	for (const auto& material : m_materials) 
	{
		material.saveToFile(file);
	}
}

void Supplier::loadFromFile(fstream& file)
{
	getline(file, m_bulstat);
	getline(file, m_name);
	getline(file, m_location);
	getline(file, m_phone);

	int _materialCount;
	file >> _materialCount;
	file.ignore();

	m_materials.clear();
	for (int i = 0; i < _materialCount; i ++) 
	{
		OpticalMaterial _material;
		_material.loadFromFile(file);
		m_materials.push_back(_material);
	}
}
