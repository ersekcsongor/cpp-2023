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
    friend Matrix operator+(const Matrix& x, const Matrix& y);
    friend Matrix operator*(const Matrix& x, const Matrix& y);
    // extractor operator
    friend istream & operator>>(istream& is, Matrix& mat);
    // inserter operator
    friend ostream & operator<<(ostream& os, const Matrix& mat);
    // index operator
    double* operator[] (int index);
    // index operator that works on constant matrices!
    double* operator[] (int index) const;
    // Copy assignment
    // operation is permitted between matrices having the same dimensions
    // otherwise throws an exception (out_of_range)
    Matrix & operator=(const Matrix& mat);
    // Move assignment
    Matrix & operator=(Matrix&& mat);

private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};

#endif //LAB6_MATRIX_H
