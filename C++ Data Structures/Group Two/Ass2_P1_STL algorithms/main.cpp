#include <iostream>
#include "Book.h"
//#ifndef BOOK_H
//#define BOOK_H
#include<vector>
using namespace std;
int main()
{
    Book B;
    int choice;
    vector<Book>library;
    cout<<" **** WELCOME TO OUR PROGRAM *** "<<endl<<endl;

    library.push_back(B.addBook());
    library.push_back(B.addBook());
    cout<<B.search_name(library, "ll");
    cout<<endl;
    cout<<B.search_author(library, "kk");
    B.update_version(library,"ll","10");
    B.hight_num_version(library);


    return 0;
}
