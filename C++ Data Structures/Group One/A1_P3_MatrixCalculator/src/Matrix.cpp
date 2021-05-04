#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(int row , int col , int num[])
{
    this->row = row;
    this->col = col;
    this->data = new int* [row];
    for(int i = 0 ; i < row ; i++){
        this->data[i]=new int [col];
    }
}
Matrix::~Matrix()
{
    for(int i = 0 ; i < row*col ; i++){
        delete data[i];
    }
    delete[] data;
}

Matrix Matrix:: operator+(Matrix mat1){

    int data3[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
    Matrix mat3(mat1.row,mat1.col , data3);  /// mat3 row = mat1 row and mat3 col = mat1 col .
    if(mat1.row == this->row && this->col==mat1.col){
        for (int i = 0 ; i < mat1.row; i++){
            for ( int j = 0 ; j < mat1.col; j++){
                mat3.data[i][j] = this->data[i][j] + mat1.data[i][j];      /// this step add data of mat1 and data from constuctor .

            }

        }
         return mat3 ;  ///  return new matrix .
    }

}

Matrix Matrix:: operator-(Matrix mat1){

    int data3[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
    Matrix mat3(mat1.row,mat1.col , data3);  /// mat3 row = mat1 row and mat3 col = mat1 col .
    if(mat1.row==this->row && this->col==mat1.col){
     for (int i = 0 ; i < mat1.row; i++){
        for ( int j = 0 ; j < mat1.col; j++){
            mat3.data[i][j] = this->data[i][j] - mat1.data[i][j];  /// this step - data of mat1 and data from constructor
        }
    }
     return mat3 ; ///  return new matrix .

    }

}
Matrix Matrix:: operator*(Matrix mat1){

    int data3[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
    Matrix mat3(this->col , mat1.row , data3 );  ///create mat3 will include the row from constructor and the row from mat1
    int sum = 0;
    if(mat1.row == this->col){
    for(int i=0; i<mat1.row; ++i)
         for(int j=0; j<col; ++j) {
            mat3.data[i][j] = 0;
         }


        for(int i=0; i < this->row; ++i)
        {
            for(int j=0; j < mat1.col; ++j)
            {
                mat3.data[i][j] = 0;
                for(int k = 0 ; k < this->col; k++){
                    mat3.data[i][j] = mat3.data[i][j] + ( this->data[i][k] * mat1.data[k][j] );   /// data of mat3 = data of mat1 * data from constructor
                }
            }
        }
        return mat3;
    }
}

Matrix Matrix::transpose()
{

        int data3[row*col]; /// if user input row = 2 and col = 3 this step will do array of data can contain 2 * 3 = 6 Element .
        Matrix mat3(row , col , data3);
        mat3.row=this->row;
        mat3.col=this->col;
        for(int i=0; i<this->row; i++)
        {
            for(int j=0; j<this->col; j++)
            {
                mat3.data[i][j] = this->data[j][i];
            }

        }
        return mat3;
}

ostream& operator<<(ostream& out, const Matrix& mat)
{
    for (int i = 0 ; i < mat.row; i++)
    {
        for ( int j = 0 ; j < mat.col; j++)
        {
            out << mat.data[i][j]<<" ";
            out << " ";
        }
        out << endl;
    }
    return out ;
}


istream& operator>>(istream& in,  Matrix& mat)
{
    cout << "Enter Data Of Matrix :\n";
    for (int i = 0 ; i < mat.row; i++)
    {
        for ( int j = 0 ; j < mat.col; j++)
        {
            in >> mat.data[i][j];
        }
    }
    return in ;
}
