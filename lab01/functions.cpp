//
// Created by Csongor on 9/25/2023.
//
#include <cstring>
#include "functions.h"

bool setBit(int &number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    number |= (1 << order);
    return true;
}

int countBit(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            count++;
        }
        n /= 2;
    }
    return count;
}

double mean(double array[], int numElements) {
    double sum = 0;
    for (int i = 0; i < numElements; i++) {
        sum += array[i];
    }
    if (numElements == 0) {
        return NAN;
    } else {
        return sum / numElements;
    }
}

double stddev(double array[], int numElements) {
    double meanValue = mean(array, numElements);
    double sum = 0;
    for (int i = 0; i < numElements; i++) {
        sum += pow(array[i] - meanValue, 2);
    }
    return sqrt(sum / numElements);
}

pair<double, double> max2(double array[], int numElements) {
    double first = array[0];
    double second = array[0];
    for (int i = 0; i < numElements; i++) {
        if (array[i] > first) {
            second = first;
            first = array[i];
        } else if (array[i] > second) {
            second = array[i];
        }
    }
    if (numElements == 0) {
        return make_pair(NAN, NAN);
    } else if (numElements == 1) {
        return make_pair(first, second);
    } else {
        return make_pair(first, second);
    }
}

int countWord(string text) {
    int count = 0;
    istringstream inputstream(text);
    string word;
    double number;
    while (inputstream >> word) {
        istringstream wordstream(word);
        if (wordstream >> number) {
            continue;
        } else {
            count++;
        }

    }
    return count;
}

string code(string text) {
    for (char &c: text) {
        if (isalpha(c)) {
            if (c == 'z') {
                c = 'a';
            } else if (c == 'Z') {
                c = 'A';
            } else {
                c++;
            }
        }
    }
    return text;
}

string decode(string text) {
    for (char &c: text) {
        if (isalpha(c)) {
            if (c == 'a') {
                c = 'z';
            } else if (c == 'A') {
                c = 'Z';
            } else {
                c--;
            }
        }
    }
    return text;
}

string capitalizeWords(string text) {
    bool capitalizeNext = true;
    for (char &c :  text) {
        if(isalpha(c))
        {
            if(capitalizeNext)
            {
                c = toupper(c);
                capitalizeNext = false;
            }
            else{
                c = tolower(c);
            }
        } else{
            capitalizeNext = true;
        }
    }
    return text;
}


