//
// Created by Csongor on 10/30/2023.
//

#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) :mRows(mRows),mCols(mCols){
    {
        mElements = new double* [mRows];
        for (int i = 0; i < mRows; ++i) {
            mElements[i] = new double [mCols];
        }
    }
}


Matrix::Matrix(const Matrix &what){
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    
    this->mElements = new double * [mRows];
    for (int i = 0; i < mRows; ++i) {
        mElements = new double * [mCols];
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
                os << mElements[i][j] << " ";
        }
        cout <<endl;
    }
    cout << endl;
}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
             mElements[i][j] = value;
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;

    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;

    cout << "Move constructor!" << endl;
}

Matrix::~Matrix() {
    for (int i = 0; i < mRows; ++i) {
        delete[] mElements[i];
    }
    delete[] mElements;
}

void Matrix::randomMatrix(int a, int b) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = rand() % b + a;
        }
    }
}

bool Matrix::isSquare() const {
    return mRows == mCols;
}


