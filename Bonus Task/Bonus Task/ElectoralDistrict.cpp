#include "ElectoralDistrict.h"

ElectoralDistrict::ElectoralDistrict() 
{
    m_districtName = "";
    m_totalVoters = 0;
    m_partyCount = 0;

    for (int i = 0; i < MAX_PARTIES; i ++)
    {
        m_votes[i] = 0;
        m_partyNames[i] = "";
    }
}

ElectoralDistrict::ElectoralDistrict(string _districtName, int _totalVoters, int _partyCount) 
{
    m_districtName = _districtName;
    m_totalVoters = _totalVoters;
    m_partyCount = _partyCount;

    for (int i = 0; i < m_partyCount; i ++) 
    {
        m_votes[i] = 0;
        m_partyNames[i] = "";
    }
}

void ElectoralDistrict::input() 
{
    cout << "Enter name of the district: ";
    while (true) 
    {
        getline(cin >> ws, m_districtName); 

        if (!m_districtName.empty()) 
            break;

        cout << "Error: The name can't be empty";
    }

    cout << "Total voters: ";
    while (!(cin >> m_totalVoters) || m_totalVoters < 0) 
    {
        cout << "Error: Enter a positive number for voters: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Party count: ";
    while (!(cin >> m_partyCount) || m_partyCount <= 0 || m_partyCount > MAX_PARTIES) 
    {
        cout << "Error: Enter a positive number between 1 and " << MAX_PARTIES << " for party count:";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < m_partyCount; i ++) 
    {
        cout << "Party name " << i + 1 << ": ";
        while (true) 
        {
            getline(cin >> ws, m_partyNames[i]);

            if (!m_partyNames[i].empty()) 
                break;

            cout << "Error: The name of the party can't be empty";
        }

        cout << "Votes for " << m_partyNames[i] << ": ";
        while (!(cin >> m_votes[i]) || m_votes[i] < 0) 
        {
            cout << "Error: Enter a positive number for " << m_partyNames[i] << ": ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    int totalVotes = 0;
    for (int i = 0; i < m_partyCount; i ++) 
    {
        totalVotes += m_votes[i];
    }

    while (totalVotes > m_totalVoters) 
    {
        cout << "Error: The total votes (" << totalVotes
             << ") is bigger then the voters (" << m_totalVoters << ")." << endl;
        cout << "Please, enter again the votes for every party:" << endl;

        totalVotes = 0;
        for (int i = 0; i < m_partyCount; i ++) 
        {
            cout << "Votes for " << m_partyNames[i] << ": ";
            while (!(cin >> m_votes[i]) || m_votes[i] < 0) 
            {
                cout << "Error: Enter positive number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            totalVotes += m_votes[i];
        }
    }

    if (totalVotes == 0) 
    {
        cout << "Warning: There are no voters in this district!" << endl;
    }
}

void ElectoralDistrict::print() 
{
    cout << endl << "District: " << m_districtName
                 << " | Total Voters: " << m_totalVoters
                 << " | Parties: " << m_partyCount << endl;

    for (int i = 0; i < m_partyCount; i ++) 
    {
        cout << " - " << m_partyNames[i] << ": " << m_votes[i] << endl;
    }

    cout << "Winner: " << getWinningParty() << endl;
}

string ElectoralDistrict::getDistrictName() 
{
    return m_districtName;
}

string ElectoralDistrict::getWinningParty() 
{
    if (m_partyCount == 0) 
        return "No";

    int maxVotes = m_votes[0];
    int winnerIndex = 0;
    bool tie = false;

    for (int i = 1; i < m_partyCount; i ++) 
    {
        if (m_votes[i] > maxVotes) 
        {
            maxVotes = m_votes[i];
            winnerIndex = i;
            tie = false;
        }
        else if (m_votes[i] == maxVotes) 
        {
            tie = true;
        }
    }

    return tie ? "No" : m_partyNames[winnerIndex];
}

bool ElectoralDistrict::isWinner(string _partyName) 
{
    return getWinningParty() == _partyName;
}

string ElectoralDistrict::getPartyName(int index)
{
    return m_partyNames[index];
}

int ElectoralDistrict::getPartyCount()
{
    return m_partyCount;
}

int ElectoralDistrict::getVotes(int index)
{
    return m_votes[index];
}

