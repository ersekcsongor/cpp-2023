#include <iostream>
#include "Matrix.h"
using namespace std;
int main() {
    std::cout << "Hello, Lab_06" << std::endl;
    Matrix m1(2,1);
    m1.fillMatrix(0);
    m1.printMatrix();
    Matrix m2(3,3);
    m2.fillMatrix(0);
    m2.printMatrix();
    m2.randomMatrix(1,10);
    m2.printMatrix();
    cout << m1.isSquare() << endl;
    return 0;
}