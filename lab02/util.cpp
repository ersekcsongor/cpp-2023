//
// Created by Csongor on 10/2/2023.
//

#include "util.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    return distance(a, b) == distance(c, d);
}

void testIsSquare(const char *filename) {
    ifstream file(filename);
    if(!file)
    {
        cout << "Error oppening file" << endl;
        return;
    }

    while (true)
    {
        int x1,x2,x3,x4,y1,y2,y3,y4;
        file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if(!file)
        {
            break;
        }
        Point a(x1,y1);
        Point b(x2,y2);
        Point c(x3,y3);
        Point d(x4,y4);

        cout << a.getX() << " " << a.getY() << endl;
        cout << b.getX() << " " << b.getY() << endl;
        cout << c.getX() << " " << c.getY() << endl;
        cout << d.getX() << " " << d.getY() << endl;

        if(isSquare(Point(x1,y1), Point(x2,y2), Point(x3,y3), Point(x4,y4)))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];

    return points;
}

void deletePoints(Point* points){
    delete[] points;
}

void printArray(Point *points, int numPoints) {
    for(int i = 0; i < numPoints; i++)
    {
        points[i].print();
    }
}

bool compPoints(Point a,Point b)
{
    return a.getX() < b.getX();
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints,compPoints);
}
