#pragma once

#include <vector>

#include "OpticalMaterial.h"
	
class Supplier 
{
public:
    Supplier();
    Supplier(string _bulstat, string _name, string _location, string _phone);

    string getBulstat() const;
    string getName() const;
    string getLocation() const;
    string getPhone() const;

    vector<OpticalMaterial> getMaterials() const;

    void setBulstat(string _bulstat);
    void setName(string _name);
    void setLocation(string _location);
    void setPhone(string _phone);

    void addMaterial(const OpticalMaterial& _material);

    void saveToFile(fstream& file) const;
    void loadFromFile(fstream& file);

    friend ostream& operator<<(ostream& os, const Supplier& _supplier);

private:
    string m_bulstat;
    string m_name;
    string m_location;
    string m_phone;

    vector<OpticalMaterial> m_materials;
};
