//
// Created by Csongor on 9/25/2023.
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H
#include <iostream>
#include <cmath>
#include <utility>
#include <string>
#include <sstream>
using namespace std;
int countBit(int n);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double *array, int numElements);
pair<double, double> max2(double array[], int numElements);
int countWord(string text);
string code(string text);
string decode(string text);
string capitalizeWords(string text);
#endif //CPP_2022_FUNCTIONS_H