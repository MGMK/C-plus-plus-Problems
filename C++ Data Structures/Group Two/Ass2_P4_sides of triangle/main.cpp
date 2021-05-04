#include <iostream>

#include <bits/stdc++.h>

using namespace std;

void PossibleTriangle(int arr[] , int n ){

    bool check ;
    if ( n < 3 )   /// no Triangle have two sides
        cout << "Its not Possible To Make Triangle From This Array ."<< endl;

    else {
        sort(arr , arr+n);
        for ( int i = 0 ; i < n - 2 ; i++){  /// to check every three sides
            if( arr[i] + arr[i+1] > arr[i+2]){
                cout << "Its Possible To Make Triangle From This Array ."<< endl;
                check = 1;
                break;
            }
        }
        if(check != 1 )
            cout << "Its not Possible To Make Triangle From This Array ."<< endl;

    }

}
int main()
{
    int arr_size;
    cout << "Enter size of array :";
    cin >> arr_size;
    int arr[arr_size];
    cout << "Enter array Elements .\n";
    for(int i = 0 ; i < arr_size; i++){
        cout << "Enter Element number "<< i+1 << " : ";
        cin >> arr[i];
    }
//     int arr[] = {5 , 6 ,  4 , 1 , 2 };
//     int Size = sizeof(arr) / sizeof(int);
     PossibleTriangle(arr , arr_size);
    return 0;
}
