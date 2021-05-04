#include <stdio.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <time.h>
using namespace std;
// A binary search based function to find the position
// where item should be inserted in a[low..high]
void create(double time1, double time2)
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("times.csv", ios::out | ios::app);

    fout << "Insertion Sort" << ", " << "Binary Insertion Sort" << "\n";

    // Insert the data to file
    fout << time1 << ", " << time2 << "\n";;
    fout << "\n";

    fout.close();
}
int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low])?  (low + 1): low;

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}
// Function to sort an array a[] of size 'n'
void create(double time1, double time2)
{
    // file pointer
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("times.csv", ios::out | ios::app);

    fout << "Insertion Sort" << ", " << "Binary Insertion Sort" << "\n";

    // Insert the data to file
    fout << time1 << "   ,   " << time2 << "\n";;
    fout << "\n";

    fout.close();
}
void insertionSort(int a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        // find location where selected sould be inseretd
        loc = binarySearch(a, selected, 0, j);

        // Move all elements after location to create space
        while (j >= loc)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}


int main()
{
    int a[] = {37, 23, 0, 17, 12, 72, 31,46, 100, 88, 54};
    int n = sizeof(a)/sizeof(a[0]);

    insertionSort(a, n);

    cout<<"sorted array is = : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<"    ";
    }



    return 0;
}
