#include "Matrix_Claculation.h"
#include <iostream>
#include "Matrix.h"
using namespace std;
Matrix_Claculation::Matrix_Claculation()
{
    //ctor
}

Matrix_Claculation::~Matrix_Claculation()
{
    //dtor
}
void Matrix_Claculation::main_function(){

    int row1, row2, col1, col2 ;
    cout <<"Enter number of row one :";
    cin >> row1;
    cout <<"Enter number of col one :";
    cin >> col1;
    int data1[row1*col1];
    Matrix mat1(row1,col1, data1);
    cin >> mat1;

    cout <<"Enter number of row two :";
    cin >> row2;
    cout <<"Enter number of col two :";
    cin >> col2;
    int data2[row2*col2];
    Matrix mat2(row2, col2, data2);
    cin >> mat2;

    while(true)
    {
        string x;
        cout << "1- Mat1 + Mat2 . \n2- Mat1 - Mat2 .\n3- Mat1 * Mat2 .\n4- Transpose of Mat .\n5- To End .\n\n Enter your choose please : ";
        cin >> x ;
        if (  x ==  "1" )
        {
            while ( (row1 != row2 && col1 != col2) || (row1 == row2 && col1 != col2) || (row1 != row2 && col1 == col2) )
            {

                cout<<"they haven't same dimensions ." << endl << endl;
                break;
            }
            while ( row1 == row2 && col1 == col2)
            {

                Matrix mat3 = mat1 + mat2;
                cout <<"mat1 + mat2 : "  << endl << endl << mat3;
                break;
            }

        }
        else if ( x == "2")
        {
            while ( (row1 != row2 && col1 != col2) || (row1 == row2 && col1 != col2) || (row1 != row2 && col1 == col2) )
            {

                cout<<"they haven't same dimensions ." << endl << endl;
                break;
            }
            while ( row1 == row2 && col1 == col2)
            {

                Matrix mat3 =mat1 - mat2;
                cout <<"mat1 - mat2 : "  << endl << mat3 ;
                break;
            }
        }
        else if ( x == "3")
        {
            while ( col1 != row2)
            {

                cout<<"they haven't same dimensions ." << endl << endl;
                break;
            }
            while ( col1 == row2)
            {

                Matrix mat3 = mat1 * mat2;
                cout <<" mat1 * mat2 : "  << endl << mat3 ;
                break;
            }
        }

        else if ( x == "4")
        {
            char choice ;
            cout << "1- Test with mat1 . \n2- Test With mat2 . \n Enter your choose :" ;
            cin >> choice ;
            if ( choice == '1')
            {
                cout << "The Result is :\n"<< mat1.transpose()  << endl<< endl;
            }
            else if ( choice == '2')
            {
                cout << "The Result is :\n"<< mat2.transpose()  << endl<< endl;
            }
        }
        else if ( x == "5")
        {
            break;
        }
        else
        {
            continue;
        }
    }


}
