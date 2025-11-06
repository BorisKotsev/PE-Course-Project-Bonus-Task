#pragma once

#include <iostream>
#include <string>

using namespace std;

const int MAX_PARTIES = 50;  

class ElectoralDistrict {
 
public:
    ElectoralDistrict();
    ElectoralDistrict(string _districtName, int _totalVoters, int _partyCount);

    void input();                       
    void print();   

    string getDistrictName();
    string getWinningParty();
    bool isWinner(string _partyName);

	string getPartyName(int index);
    int getPartyCount();
    int getVotes(int index);

private:
    string m_districtName;
    int m_totalVoters;
    int m_partyCount;
    int m_votes[MAX_PARTIES];
    string m_partyNames[MAX_PARTIES];
};

