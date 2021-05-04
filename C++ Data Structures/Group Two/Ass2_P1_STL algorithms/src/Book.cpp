#include "Book.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Book Book::addBook()
{
    Book B;
    cout<<"enter the name of Book : ";
    getline(cin,B.name);
    cout<<"enter the author name of Book : ";
    getline(cin,B.author);
    cout<<"enter the publish_year of Book : ";
    getline(cin,B.publish_year);
    cout<<"enter the num_version of  Book : ";
    getline(cin,B.num_version);
    return B;

}
bool Book::search_name(vector<Book> b, string key)
{
    bool choice = 0;
    for(int i=0; i<b.size(); i++)
    {
        if(b[i].name==key)
            choice =1;
    }
    return choice;

}
bool Book::search_author( vector<Book>library,string key1)
{
    bool choice =0;
    for(int i=0; i<library.size(); i++)
    {
        if(library[i].author==key1)
            choice = 1;
    }
    return choice;
}
void Book::update_version(vector<Book>b, string n,string num)
{
    Book B;
    for(int i=0; i<b.size(); i++)
    {
        if(B.name==n)
        {
            B.num_version=num;
        }
    }
    cout<<" Data after Update "<<endl;
    for(int i=0; i<b.size(); i++)
    {
        cout<<b[i].name<<"   "<<b[i].author<<"   "<<b[i].publish_year<<"   "<<b[i].num_version<<endl;

    }
}
void Book::hight_num_version(vector<Book>b)
{
    vector<string> ver;
    for(int i=0; i<b.size(); i++)
    {
        ver[i]=b[i].num_version;
    }
    vector<string>::iterator it;

    it = max(ver.begin(),ver.end());//the iterator will have the pointer for the highest value

    cout << ver[it - ver.begin()];
    cout<<b[it - ver.begin()].name<<"   "<<b[it - ver.begin()].author<<"   "<<b[it - ver.begin()].publish_year<<b[it - ver.begin()].num_version<<endl;//it - ver.begin() this will return the position of the highest value
}
