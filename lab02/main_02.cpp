#include <iostream>
#include "Point.h"
#include "util.h"
#include <cstdlib>
using namespace std;

ostream& operator<<(ostream& os, Point p) {
    os << "(" << p.getX() << ", " << p.getY() << ")";
    return os;
}

int main(int argc, char **argv) {
    /*Point p1(1, 2);
    p1.print();
    cout << endl;
    Point *pp1 = new Point(300, 400);
    Point *pp2 = new Point(500, 1000);
    pp1->print();
    cout << endl;
    pp2->print();
    delete pp1;
    delete pp2;
    cout << distance(Point(1, 1), Point(2, 2));*/
    int numPoints = 10;

    testIsSquare("points.txt");

    Point *points = createArray(numPoints);
    printArray(points, numPoints);

    for (int i = 0; i < numPoints; ++i) {
        points[i] = Point(rand() % 100, rand() % 100);
    }
    cout << endl;
    cout <<"Printed array:"<< endl;
    printArray(points,numPoints);
    cout << endl;
    cout <<"Sorted array:"<< endl;
    sortPoints(points,numPoints);
    printArray(points,numPoints);
    cout << endl <<"Closest Points:" << endl;
    cout << closestPoints(points,numPoints).first << " " << closestPoints(points,numPoints).second << endl;
    cout << endl <<"Farthest Points:" << endl;
    farthestPointsFromOrigin(points,numPoints);
    deletePoints(points);
    return 0;
}