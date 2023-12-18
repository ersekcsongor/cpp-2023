//
// Created by Csongor on 12/18/2023.
//

#ifndef LAB13_SIMPLETEXTGENERATOR_H
#define LAB13_SIMPLETEXTGENERATOR_H
#include "TextGenerator.h"
#include <vector>
#include <map>
#include <unordered_map>

class SimpleTextGenerator: public TextGenerator {
    unordered_map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const; // a map kiíratása
};

#endif //LAB13_SIMPLETEXTGENERATOR_H
