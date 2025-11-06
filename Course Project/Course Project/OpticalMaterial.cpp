#include "OpticalMaterial.h"

OpticalMaterial::OpticalMaterial()
{
	m_type = "Unknown";
	m_materialName = "Unknown";

	m_thickness = 0.0;
	m_diopter = 0.0;
	m_price = 0.0;
}

OpticalMaterial::OpticalMaterial(string _type, string _materialName, double _thickness, double _diopter, double _price)
{
	setType(_type);
	setMaterialName(_materialName);

	setThickness(_thickness);
	setDiopter(_diopter);
	setPrice(_price);
}

string OpticalMaterial::getType() const
{
	return m_type;
}

string OpticalMaterial::getMaterialName() const
{
	return m_materialName;
}

double OpticalMaterial::getThickness() const
{
	return m_thickness;
}

double OpticalMaterial::getDiopter() const
{
	return m_diopter;
}

double OpticalMaterial::getPrice() const
{
	return m_price;
}

void OpticalMaterial::setType(string _type)
{
	if (_type.empty()) 
	{
		throw invalid_argument("The type can't be empty!");
	}
	m_type = _type;
}

void OpticalMaterial::setMaterialName(string _materialName)
{
	if (_materialName.empty()) 
	{
		throw invalid_argument("Material Name can't be empty!");
	}
	m_materialName = _materialName;
}

void OpticalMaterial::setThickness(double _thickness)
{
	if (_thickness <= 0) 
	{
		throw invalid_argument("The thickness must be positive number!");
	}
	m_thickness = _thickness;
}

void OpticalMaterial::setDiopter(double _diopter)
{
	m_diopter = _diopter;
}

void OpticalMaterial::setPrice(double _price)
{
	if (_price < 0) 
	{
		throw invalid_argument("The price can't be negative!");
	}
	m_price = _price;
}

ostream& operator<<(ostream& os, const OpticalMaterial& _opticalMetrial)
{
	os << _opticalMetrial.m_materialName << " " << _opticalMetrial.m_type << " " << _opticalMetrial.m_thickness << " mm. "
	   << _opticalMetrial.m_diopter << " " << _opticalMetrial.m_price << " lv";
	return os;
}

void OpticalMaterial::saveToFile(fstream& file) const
{
	file << m_type << endl;
	file << m_thickness << endl;
	file << m_diopter << endl;
	file << m_materialName << endl;
	file << m_price << endl;
}

void OpticalMaterial::loadFromFile(fstream& file)
{
	getline(file, m_type);
	file >> m_thickness >> m_diopter;
	file.ignore();
	getline(file, m_materialName);
	file >> m_price;
	file.ignore();
}
