//
// Created by Csongor on 12/18/2023.
//

#include <sstream>
#include <fstream>
#include <algorithm>
#include "SimpleTextGenerator.h"

void SimpleTextGenerator::trainFromText(string trainingText) {
    string word;
    istringstream iss(trainingText);
    vector<string>words;
    while (iss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(remove_if(word.begin(), word.end(), [](char c) { return !isalpha(c); }), word.end());
        if (!word.empty()) {
            words.push_back(word);
        }
    }
    for(int i = 2 ; i < words.size();i++){
        string prefix = words[i-2] + " " + words[i-1];
        data[prefix].push_back(words[i]);
}
}
void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        stringstream buffer;
        buffer << file.rdbuf();
        trainFromText(buffer.str());
        file.close();
    } else{
        cout << "Failed to open file: " << filename << endl;
    }
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    stringstream result;
    result << startWords;
    istringstream iss(startWords);
    vector<string>startTokens;
    string token;
    while(iss >> token)
    {
        startTokens.push_back(token);
    }
    while (startTokens.size() < static_cast<size_t>(numWords)){
        string currentPrefix = startTokens[startTokens.size() - 2] + " " + startTokens[startTokens.size() - 1];
        if (data.find(currentPrefix) != data.end() && !data[currentPrefix].empty()) {
            int randomIndex = rand() % data[currentPrefix].size();
            std::string nextWord = data[currentPrefix][randomIndex];

            result << " " << nextWord;

            startTokens.push_back(nextWord);
        } else {
            break;
        }
    }

    return result.str();
}

void SimpleTextGenerator::printData() const {
    for(const auto &pair : data){
        cout << pair.first << ": " ;
        for(const auto &word : pair.second){
            cout << word << " ";
        }
        cout << endl;
    }
}
