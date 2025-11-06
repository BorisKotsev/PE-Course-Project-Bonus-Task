#include "Supplier.h"
#include "OpticalMaterial.h"
#include "Order.h"

void clearInput() 
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addSupplier(vector<Supplier>& suppliers) 
{
    Supplier _supplier;
    string _input;

    cout << endl 
         << "╔════════════════════════════════════════════╗" << endl;
    cout << "║              ADD NEW SUPPLIER              ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;

    while (true) 
    {
        try 
        {
            cout << "Bulstat: ";
            getline(cin, _input);
            _supplier.setBulstat(_input);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
        }
    }

    while (true) 
    {
        try 
        {
            cout << "Name: ";
            getline(cin, _input);
            _supplier.setName(_input);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
        }
    }

    while (true) 
    {
        try 
        {
            cout << "Location: ";
            getline(cin, _input);
            _supplier.setLocation(_input);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
        }
    }

    while (true) 
    {
        try 
        {
            cout << "Phone: ";
            getline(cin, _input);
            _supplier.setPhone(_input);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
        }
    }

    suppliers.push_back(_supplier);
    cout << endl << "The Supplier is added!" << endl;
}

void addMaterialToSupplier(vector<Supplier>& suppliers) 
{
    if (suppliers.empty())
    {
        cout << endl << "There are no suppliers!" << endl;
        return;
    }

    cout << endl 
         << "╔════════════════════════════════════════════╗" << endl;
    cout << "║           ADD MATERIAL TO SUPPLIER         ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;

    cout << endl << "List of all suppliers:" << endl;
    for (int i = 0; i < suppliers.size(); i ++)
    {
        cout << i + 1 << ". " << suppliers[i].getName() << " (" << suppliers[i].getBulstat() << ")" << endl;
    }

    int _choice;
    cout << endl << "Choose supplier (1-" << suppliers.size() << "): ";
    cin >> _choice;
    clearInput();

    if (_choice < 1 || _choice > suppliers.size())
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    OpticalMaterial _material;
    string _input;
    double _value;

    while (true) 
    {
        try 
        {
            cout << "Optics type: ";
            getline(cin, _input);
            _material.setType(_input);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
        }
    }

    while (true) 
    {
        try 
        {
            cout << "Thickness (mm): ";
            cin >> _value;
            clearInput();
            _material.setThickness(_value);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
            clearInput();
        }
    }

    while (true) 
    {
        try 
        {
            cout << "Diopter: ";
            cin >> _value;
            clearInput();
            _material.setDiopter(_value);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
            clearInput();
        }
    }

    while (true) 
    {
        try 
        {
            cout << "Material Name: ";
            getline(cin, _input);
            _material.setMaterialName(_input);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
        }
    }

    while (true) 
    {
        try 
        {
            cout << "Price (lv): ";
            cin >> _value;
            clearInput();
            _material.setPrice(_value);
            break;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
            clearInput();
        }
    }

    suppliers[_choice - 1].addMaterial(_material);
    cout << endl << "The material is added!" << endl;
}

void viewSuppliers(const vector<Supplier>& suppliers)
{
    if (suppliers.empty())
    {
        cout << endl << "There are no suppliers!" << endl;
        return;
    }

    cout << endl 
         << "╔════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                      LIST OF ALL SUPPLIERS                     ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;

    for (const auto& supplier : suppliers)
    {
        cout << supplier;

        if (!supplier.getMaterials().empty()) 
        {
            cout << endl << "Materials:" << endl;
            cout << "Name Type Thickness Diopter Price" << endl;
            cout << "────────────────────────────────────────────────────────────────" << endl;

            for (const auto& material : supplier.getMaterials()) 
            {
                cout << material << endl;
            }
        }
        else 
        {
            cout << "There are no materials." << endl;
        }
        cout << endl;
    }
}

void createOrder(vector<Supplier>& suppliers)
{
    if (suppliers.empty())
    {
        cout << endl << "There are no suppliers!" << endl;
        return;
    }

    cout << endl 
         << "╔════════════════════════════════════════════╗" << endl;
    cout << "║               CREATE AN ORDER              ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;

    cout << endl << "List of all suppliers:" << endl;
    for (int i = 0; i < suppliers.size(); i ++) 
    {
        cout << i + 1 << ". " << suppliers[i].getName() << " (" << suppliers[i].getBulstat() << ")" << endl;
    }

    int _choice;
    cout << endl << "Choose supplier (1-" << suppliers.size() << "): ";
    cin >> _choice;
    clearInput();

    if (_choice < 1 || _choice > suppliers.size())
    {
        cout << "Invalid choice!" << endl;
        return;
    }

    Supplier& _selectedSupplier = suppliers[_choice - 1];

    if (_selectedSupplier.getMaterials().empty())
    {
        cout << endl << "This supplier don't have any available materials!" << endl;
        return;
    }

    Order _order(&_selectedSupplier);

    cout << endl << "Available materials:" << endl;
    cout << "№ Name Type Thickness Diopter Price" << endl;
    cout << "────────────────────────────────────────────────────────────────" << endl;

    const auto& _materials = _selectedSupplier.getMaterials();
    for (int i = 0; i < _materials.size(); i ++)
    {
        cout << (i + 1) << " " << _materials[i] << endl;
    }

    char _continueOrder = 'y';
    while (_continueOrder == 'y' || _continueOrder == 'Y')
    {
        int _materialChoice, _quantity;

        cout << endl << "Choose material (1-" << _materials.size() << "): ";
        cin >> _materialChoice;

        if (_materialChoice < 1 || _materialChoice > _materials.size())
        {
            cout << "Invalid choice!" << endl;
            clearInput();
            continue;
        }

        cout << "Quantity: ";
        cin >> _quantity;
        clearInput();

        try 
        {
            _order.addItem(_materialChoice - 1, _quantity);
            cout << "The material is added to the order!" << endl;
        }
        catch (const exception& e) 
        {
            cout << "Error: " << e.what() << " Try again." << endl;
        }

        cout << endl << "Add other material? (y/n): ";
        cin >> _continueOrder;
        clearInput();
    }

    cout << _order;
}

void saveData(const vector<Supplier>& suppliers) 
{
    fstream file("suppliers.dat", ios::out | ios::trunc);

    if (!file.is_open()) 
    {
        cout << "Error while opening the file for saving!" << endl;
        return;
    }

    file << suppliers.size() << endl;
    for (const auto& supplier : suppliers) 
    {
        supplier.saveToFile(file);
    }

    file.close();
    cout << endl << "The data is added to 'suppliers.dat'!" << endl;
}

void loadData(vector<Supplier>& suppliers) 
{
    fstream file("suppliers.dat");

    if (!file) 
    {
        cout << endl << "The file 'suppliers.dat' does not exists." << endl;
        return;
    }

    int _supplierCount;
    file >> _supplierCount;
    file.ignore();

    suppliers.clear();
    for (int i = 0; i < _supplierCount; i ++)
    {
        Supplier supplier;
        supplier.loadFromFile(file);
        suppliers.push_back(supplier);
    }

    file.close();
    cout << endl << "Loaded " << _supplierCount << " suppliers from the file!" << endl;
}

void displayMenu() 
{
    cout << endl 
         << "╔═══════════════════════════════════════════╗" << endl;
    cout << "║         Supplier Management System        ║" << endl;
    cout << "║           of optical materials            ║" << endl;
    cout << "╠═══════════════════════════════════════════╣" << endl;
    cout << "║  1. Add a supplier                        ║" << endl;
    cout << "║  2. Add a material to supplier            ║" << endl;
    cout << "║  3. List of all suppliers                 ║" << endl;
    cout << "║  4. Create an order                       ║" << endl;
    cout << "║  5. Save the data into a file             ║" << endl;
    cout << "║  6. Load the data from a file             ║" << endl;
    cout << "║  0. Exit                                  ║" << endl;
    cout << "╚═══════════════════════════════════════════╝" << endl;
    cout << "Choose: ";
}

int main() 
{
    vector<Supplier> suppliers;
    int choice;

    do 
    {
        displayMenu();
        cin >> choice;
        clearInput();

        switch (choice) 
        {
        case 1:
            addSupplier(suppliers);
            break;
        case 2:
            addMaterialToSupplier(suppliers);
            break;
        case 3:
            viewSuppliers(suppliers);
            break;
        case 4:
            createOrder(suppliers);
            break;
        case 5:
            saveData(suppliers);
            break;
        case 6:
            loadData(suppliers);
            break;
        case 0:
            cout << endl 
                 << "╔════════════════════════════════════════════╗" << endl;
            cout << "║         Thanks for using the system!       ║" << endl;
            cout << "╚════════════════════════════════════════════╝" << endl;
            break;
        default:
            cout << endl << "Invalid choice! Try again." << endl;
        }

        if (choice != 0) 
        {
            cout << endl << "Press Enter to continue...";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}