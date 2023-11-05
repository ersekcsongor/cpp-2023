//
// Created by Csongor on 10/30/2023.
//

#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) :mRows(mRows),mCols(mCols){
    {
        mElements = new double *[mRows];
        for (int i = 0; i < mRows; ++i) {
            mElements[i] = new double[mCols];
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

Matrix operator+(const Matrix &x, const Matrix &y) {
    if((x.mRows != y.mRows )||(x.mCols != y.mCols))
    {
        throw  out_of_range("Matrix dimensions are different!");
    }
    Matrix z;
    z.fillMatrix(0);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < x.mCols;  ++j) {
            z.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return z;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if((x.mCols != y.mRows ))
    {
        throw  out_of_range("Matrix dimensions are different!");
    }
    Matrix z;
    z.fillMatrix(0);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols;  ++j) {
            for (int k = 0; k < x.mCols; ++k) {
                z.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return z;

}

istream &operator>>(istream &is, Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

double *Matrix::operator[](int index) {
    return mElements[index];
}

double *Matrix::operator[](int index) const {
    return mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this != &mat) {
        for (int i = 0; i < mRows; ++i) {
            delete[] mElements[i];
        }
        delete[] mElements;
        mRows = mat.mRows;
        mCols = mat.mCols;
        mElements = new double * [mRows];
        for (int i = 0; i < mRows; ++i) {
            mElements[i] = new double [mCols];
        }
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                mElements[i][j] = mat.mElements[i][j];
            }
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    if (this != &mat) {
        for (int i = 0; i < mRows; ++i) {
            delete[] mElements[i];
        }
        delete[] mElements;
        mRows = mat.mRows;
        mCols = mat.mCols;
        mElements = mat.mElements;
        mat.mRows = 0;
        mat.mCols = 0;
        mat.mElements = nullptr;
    }
    return *this;
}





