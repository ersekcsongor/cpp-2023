//
// Created by Csongor on 12/11/2023.
//

#ifndef LAB12_SETTLEMENTSTATISTICS_H
#define LAB12_SETTLEMENTSTATISTICS_H
#include "Settlement.h"
struct SettlementStatistics {
    virtual int numSettlements() const = 0;
    virtual int numCounties() const = 0;
    virtual int numSettlementsByCounty(const string& county) const = 0;
    virtual vector<Settlement> findSettlementsByCounty(
            const string& county) const = 0;
    virtual Settlement findSettlementsByNameAndCounty(
            const string& name, const string& county) const = 0;
    virtual Settlement maxPopulationDensity() const = 0;
    virtual Settlement minPopulationDensity() const = 0;
    virtual vector<Settlement> findSettlementsByName(const string& name) = 0;
};
#endif //LAB12_SETTLEMENTSTATISTICS_H
