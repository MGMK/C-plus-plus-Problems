#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix
{
    public:
        Matrix(int row , int col , int num[]);
        ~Matrix();
        Matrix operator+ (Matrix mat1);   /// return new matrix
        Matrix operator- (Matrix mat1);   /// return new matrix
        Matrix operator* (Matrix mat1);   /// return new matrix
        Matrix transpose();
        friend ostream& operator<<(ostream& out, const Matrix& mat);
        friend istream& operator>>(istream& in,  Matrix& mat);

        int row , col ;
        int** data;
};

#endif // MATRIX_H
