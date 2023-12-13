//
// Created by Csongor on 12/11/2023.
//

#include <fstream>
#include <sstream>
#include <set>
#include "SettlementStatisticsImpl.h"

SettlementStatisticsImpl::SettlementStatisticsImpl(const multimap<string, Settlement> &data) : data(data) {}

int SettlementStatisticsImpl::numSettlements() const {
    return data.size();
}

int SettlementStatisticsImpl::numCounties() const {
    set<string>uniqueCountyCodes;
    for(auto &entry : data)
    {
        uniqueCountyCodes.insert(entry.first);
    }
    return static_cast<int>(uniqueCountyCodes.size());
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    int sum = 0;
    for(auto &entry : data)
    {
        if(entry.first == county)
        {
            sum++;
        }
    }
    return sum;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement>settlements;
    for(auto &entry : data)
    {
        if(entry.first == county )
        {
            settlements.push_back(entry.second);
        }
    }
    return settlements;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    for( auto &settlement : data)
    {
        if(settlement.first == county && settlement.second.getName() == name)
        {
            return settlement.second;
        }
    }
}

Settlement SettlementStatisticsImpl::maxPopulationDensity() const {
    int currentMaxPop = -1;
    Settlement maxPopSet;
    for(auto &entry : data)
    {
        if(entry.second.getPopulation() > currentMaxPop)
        {
            currentMaxPop = entry.second.getPopulation();
            maxPopSet = entry.second;
        }
    }
    return maxPopSet;
}

Settlement SettlementStatisticsImpl::minPopulationDensity() const {
    int currentMinPop = INT_MAX;
    Settlement minPopset;
    for(auto &entry : data)
    {
        if(entry.second.getPopulation() < currentMinPop){
            currentMinPop = entry.second.getPopulation();
            minPopset = entry.second;
        }
    }
    return minPopset;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement>settlements;
    for(auto &entry : data)
    {
        if(entry.second.getName() == name )
        {
            settlements.push_back(entry.second);
        }
    }
    return settlements;

}

void SettlementStatisticsImpl::readSettlements(string file) {
    ifstream ifs(file);
    string line;

    // Read and discard the first line
    if (getline(ifs, line)) {
        // Optionally, you can process or ignore the first line here if needed
        // For example, extracting column headers or validating content
    }

    while (getline(ifs, line)) {
        istringstream iss(line);
        string name, county, word;

        getline(iss, name, ',');
        getline(iss, county, ',');
        getline(iss, word);

        int population = 0;
        if (!word.empty()) {
            population = stoi(word);
        }

        Settlement settlement1{name, county, population};
        data.insert({county, settlement1});
    }
}

ostream &operator<<(ostream &os, SettlementStatisticsImpl &statistics) {
    for (auto &d : statistics.data){
        os << d.second.getName() << " " << d.second.getCounty() << " " << d.second.getPopulation() << endl;
    }
}




