#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <ctime>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void quickSort(int arr[], int left, int right) { // at first would be called
                                            // with left =0 & right = size-1
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

void merge_process(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /// Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /// Copy the remaining elements of R[] if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        /// Same as (l+r)/2, but avoids overflow for
        /// large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge_process(arr, l, m, r);
    }
}
int main()
{
    ofstream file;
    file.open ("time.csv");
    int number_of_arrays , Size;
    double diff_time_quick_sort , diff_time_merge_sort ;
    cout << "Enter number of array :";
    cin >> number_of_arrays ;
    for(int i = 0 ; i < number_of_arrays; i++)
    {

        cout<< "Enter Size of array number " << i+1 << " : ";
        cin >> Size ;
        int arr[Size];
        cout << "Elements of Array number "<< i+1 << " Before Sort is :\n";
        for(int i=0; i<Size; i++)
        {
            arr[i] = (rand()%100)+1;
            cout << arr[i] << endl;
        }
        cout << "Elements of Array number " << i+1 <<" After Quick Sort is :\n";
         clock_t quick_start = 0 ;
         cout << "\t\tQuick sort Function . "<< endl ;
        for(int i=0; i<Size; i++)
        {

            quickSort(arr, 0, Size-1);
            cout << arr[i] << endl;
        }
        clock_t quick_finish = clock();

        diff_time_quick_sort = quick_finish - quick_start ;
        diff_time_quick_sort = ((double)quick_finish)/CLOCKS_PER_SEC;
        cout << "The time is ( quick sort ) :" << diff_time_quick_sort   << " Sec ."<< endl ;

        file << diff_time_quick_sort << "," ;


        cout << "Elements of Array number " << i+1 <<" After Merge Sort is :\n";
         clock_t merge_start = 0 ;
         cout << "the Merge sort is : "<< endl ;
        for(int i=0; i<Size; i++)
        {

            mergeSort(arr, 0, Size-1);
            cout << arr[i] << endl;
        }
        clock_t merge_finish = clock();
        diff_time_merge_sort = merge_finish - merge_start ;
        diff_time_merge_sort = ((double)merge_finish)/CLOCKS_PER_SEC;
        cout << "The time is ( Merge sort ) :" << diff_time_merge_sort   << " Sec ."<< endl ;
        file <<diff_time_merge_sort  << endl ;

    }


}
