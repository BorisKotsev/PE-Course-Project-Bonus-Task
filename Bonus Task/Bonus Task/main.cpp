#include <fstream>
#include <vector>
#include <algorithm>

#include "ElectoralDistrict.h"

int main() 
{
    int _count;

    cout << "Enter number of districts: ";
    while (!(cin >> _count) || _count <= 0) 
    {
        cout << "Error: Enter a positive number for number of districts: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<ElectoralDistrict> districts(_count);

    for (int i = 0; i < _count; i ++) 
    {
        cout << endl << "=== District " << i + 1 << " ===" << endl;
        districts[i].input();
    }

    ofstream outFile("districts.txt");
    if (!outFile) 
    {
        cerr << "Error while opening districts.txt!" << endl;
        return 1;
    }

    for (auto& d : districts) 
    {
        outFile << d.getDistrictName() << " - Winner: " << d.getWinningParty() << endl;
        outFile << "Parties:" << endl;

        for (int i = 0; i < d.getPartyCount(); i ++) 
        {
            outFile << " - " << d.getPartyName(i) << endl;
        }

        outFile << endl;
    }
    outFile.close();
    cout << endl << "The data is saved in districts.txt" << endl;

    ofstream resultFile("results.txt");
    if (!resultFile) 
    {
        cerr << "Error while opening results.txt!" << endl;
        return 1;
    }

    for (auto& d : districts) 
    {
        resultFile << d.getDistrictName() << " - Winner: " << d.getWinningParty() << endl;
        resultFile << "Parties and votes:" << endl;

        for (int i = 0; i < d.getPartyCount(); i ++) 
        {
            resultFile << " - " << d.getPartyName(i) << ": " << d.getVotes(i) << endl;
        }
        resultFile << endl;
    }

    resultFile.close();
    cout << endl << "The results are saved in results.txt" << endl;

    string _party;
    bool validParty = false;
    do
    {
        do 
        {
            cout << endl << "Enter a party for searching: ";
            cin >> _party;

            validParty = false;
            for (auto& d : districts) 
            {
                for (int i = 0; i < d.getPartyCount(); i ++) 
                {
                    if (d.getPartyName(i) == _party) 
                    {
                        validParty = true;
                        break;
                    }
                }
                if (validParty) 
                    break;
            }

            if (!validParty) 
            {
                cout << " The party \"" << _party << "\" does not exists. Try again." << endl;
            }

        } while (!validParty);

        vector<string> wonDistricts;
        for (auto& d : districts) 
        {
            if (d.isWinner(_party))
                wonDistricts.push_back(d.getDistrictName());
        }

        sort(wonDistricts.begin(), wonDistricts.end());

        cout << endl << "District in which " << _party << " won:" << endl;
        if (wonDistricts.empty()) 
            cout << "No." << endl;
        else 
            for (auto& name : wonDistricts) 
                cout << " - " << name << endl;

        cout << endl << "Districts without a winner:" << endl;
        bool noWinner = false;
        for (auto& d : districts) 
        {
            if (d.getWinningParty() == "No") 
            {
                cout << " - " << d.getDistrictName() << endl;
                noWinner = true;
            }
        }
        if (!noWinner) cout << "There are no districts." << endl;

		string _choice;

        cout << endl << "Do you want to search for an other party? (y/n): ";
        cin >> _choice;
		if (_choice != "y" && _choice != "Y") 
            break;

    } while (true);

    return 0;
}
