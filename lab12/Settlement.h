//
// Created by Csongor on 12/11/2023.
//

#ifndef LAB12_SETTLEMENT_H
#define LAB12_SETTLEMENT_H
#include <iostream>
#include <vector>

using namespace std;
class Settlement {
private:
    string name = "";
    string county = "";
    int population = 0;
public:

    Settlement(const string &name = "", const string &county = "", int population = 0);
    const string &getName() const;
    const string &getCounty() const;
    int getPopulation() const;
    void setName(const string &name);
    void setCounty(const string &county);
    void setPopulation(int population);

    friend ostream &operator << (ostream &os,const Settlement settlement);
    // constructor, getters, setters, inserter operator
};


#endif //LAB12_SETTLEMENT_H
