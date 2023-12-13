//
// Created by Csongor on 12/11/2023.
//

#include "Settlement.h"






const string &Settlement::getName() const {
    return name;
}

const string &Settlement::getCounty() const {
    return county;
}

int Settlement::getPopulation() const {
    return population;
}

void Settlement::setName(const string &name) {
    Settlement::name = name;
}

void Settlement::setCounty(const string &county) {
    Settlement::county = county;
}

void Settlement::setPopulation(int population) {
    Settlement::population = population;
}

ostream &operator<<(ostream &os, const Settlement settlement) {
    os << "Name: " <<  settlement.getName() << " ";
    os << "County: " <<  settlement.getCounty() << " ";
    os << "Population: " <<  settlement.getPopulation() << " ";
}

Settlement::Settlement(const string &name, const string &county, int population) : name(name), county(county),
                                                                                   population(population) {}



