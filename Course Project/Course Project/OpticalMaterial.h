#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class OpticalMaterial
{
public:
    OpticalMaterial();
    OpticalMaterial(string _type, string _materialName, double _thickness, double _diopter, double _price);

    string getType() const;
    string getMaterialName() const;

    double getThickness() const;
    double getDiopter() const;
    double getPrice() const;

    void setType(string _type);
    void setMaterialName(string _materialName);

    void setThickness(double _thickness);
    void setDiopter(double _diopter);
    void setPrice(double _price);

    void saveToFile(fstream& file) const;
    void loadFromFile(fstream& file);

    friend ostream& operator<<(ostream& os, const OpticalMaterial& _opticalMetrial);

private:
    string m_type;
    string m_materialName;
    
    double m_thickness;
    double m_diopter;
    double m_price;
};