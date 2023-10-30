//
// Created by Csongor on 10/16/2023.
//

#include "PointSet.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip>

bool exists[M+1][M+1]={false};

PointSet::PointSet(int n) {
    this->n = n;
    points.reserve(n);
    distances.reserve(n * (n - 1)/2);
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M); // return a number in the given range
    while(points.size() < n){
        int x = dist(mt);
        int y = dist(mt);
        //to-do
        Point p(x, y);
        points.push_back(Point(x, y));
    }
    computeDistances();
}

void PointSet::computeDistances() {

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) {
        return p1.getX() < p2.getX();
    });}


void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

void PointSet::printPoints() const {
    for (const Point &p : points) {
        cout << p.getX() << " " << p.getY() << endl;
    }
    cout << endl;
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printDistances() const {
    for (const double &d : distances) {
        cout << d << " ";
    }
    cout << endl;
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), [](const Point &p1, const Point &p2) {
        return p1.getY() < p2.getY();
    });
}


int PointSet::numDistinctDistances() {
    vector<double>::iterator ip;
    ip= std::unique(distances.begin(), distances.end());
    return ip - distances.begin();
}



