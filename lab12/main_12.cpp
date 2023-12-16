#include <iostream>
#include <fstream>
#include <sstream>
#include "Settlement.h"
#include "SettlementStatisticsImpl.h"
int main() {
    std::cout << "Hello, Lab_12" << std::endl;
    Settlement settlement1("Abrud","Alba",2500);
    cout  << settlement1 << endl;
    multimap<string,Settlement>megyek;
    SettlementStatisticsImpl settlementStatistics1(megyek);
    multimap <string, Settlement> settlementData;
    SettlementStatisticsImpl setlStat1(settlementData);
    setlStat1.readSettlements("telepulesek.csv");
//    cout << setlStat1;
    cout <<  "Number of settlements: " << setlStat1.numSettlements() << endl;
    cout <<  "Number of counties:0"<< setlStat1.numCounties() << endl;
    cout <<  "Number of settlements in Alba county: " << setlStat1.numSettlementsByCounty("AB") << endl;
    vector<Settlement>settlements;
    cout <<  "Settlement by Name and County: " << setlStat1.findSettlementsByNameAndCounty("Sanmiclaus","AB") << endl;
    settlements = setlStat1.findSettlementsByCounty("AB");
    vector<Settlement>settlements2;
    cout << "Finding settlements with the same name from different counties: " << endl;
    settlements2 = setlStat1.findSettlementsByName("Sanmiclaus");
    for(auto &e : settlements2)
    {
        cout << e << endl;
    }
    cout << "Settlement with the highest population: " <<  setlStat1.maxPopulationDensity() <<  endl;
    cout <<  "Settlement with the lowest population: " << setlStat1.minPopulationDensity() <<  endl;
    return 0;
}