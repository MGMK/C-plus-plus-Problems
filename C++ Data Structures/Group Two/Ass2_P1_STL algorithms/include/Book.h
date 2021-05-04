#ifndef BOOK_H
#define BOOK_H
#include "Book.h"
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Book
{
public:
    string name,author,publish_year,num_version;
    Book addBook();
    bool search_name(vector<Book>b, string key);
    bool search_author(vector<Book>b,string key);
    void update_version(vector<Book>b, string n, string num);
    void hight_num_version(vector<Book>b);
};

#endif // BOOK
