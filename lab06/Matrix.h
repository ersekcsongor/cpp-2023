//
// Created by Csongor on 10/30/2023.
//

#ifndef LAB6_MATRIX_H
#define LAB6_MATRIX_H
#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

class Matrix {

public:
//Methods
// Default constructor
    Matrix( int mRows = 10, int mCols =10);
// Copy constructor
    Matrix(const Matrix& what);
// Move constructor
    Matrix( Matrix&& what );
// Destructor
    ~Matrix();

    void printMatrix(ostream& os = cout) const;
    void fillMatrix(double value);
    void randomMatrix(int a, int b);
    bool isSquare() const;
    int getRows() const { return this->mRows;}
    int getCols() const { return this->mCols;}

private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};

#endif //LAB6_MATRIX_H
