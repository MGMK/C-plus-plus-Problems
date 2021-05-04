#include <iostream>
#include "fraction.h"
using namespace std;
istream& operator>> (istream& in, fraction & f1)
{
    in>>f1.num_1>>f1.num_2;
    return in;
}
ostream& operator << (ostream& out, fraction & f1)
{
    out<<f1.num_1<<" / "<<f1.num_2<<endl;
    return out;

}
int main()
{
    int n1,n2,n3,n4;
    fraction ob(9,6);
    fraction ob2(8,24);
    fraction ob3,ob4,ob5,ob6;
    cout<<"the addition of two fraction = ";
    ob3=ob+ob2;
    cout<<ob3;
    cout<<endl;
    cout<<"the subtraction of two fraction = ";
    ob4=ob-ob2;
    cout<<ob4;
    cout<<endl;
    cout<<"the multiplication of two fraction = ";
    ob5=ob*ob2;
    cout<<ob5;
    cout<<endl;
    cout<<"the Division of two fraction = ";
    ob6=ob/ob2;
    cout<<ob6;
    cout<<endl;
    if(ob>ob2)
    {
        cout<<" the fraction 1 greater than fraction 2 : "<<" true "<<endl;
    }
    else
        cout<<" the fraction 1 greater than fraction 2 : "<<" false "<<endl;
    cout<<endl;
    if(ob<ob2)
    {
        cout<<" the fraction 2 greater than fraction 1 : "<<" true "<<endl;
    }
    else
        cout<<" the fraction 2 greater than fraction 1 : "<<" false "<<endl;
    cout<<endl;
    if(ob==ob2)
    {
        cout<<" the fraction 1 equal equal  fraction 2 : "<<" true "<<endl;
    }
    else
        cout<<" the fraction 1  equal equal  fraction 2 : "<<" false "<<endl;
    cout<<endl;
    if(ob>=ob2)
    {
        cout<<" the fraction 1 greater than or equal  fraction 2 : "<<" true "<<endl;
    }
    else
        cout<<" the fraction 1 greater than or equal fraction 2 : "<<" false "<<endl;
    cout<<endl;
    if(ob<=ob2)
    {
        cout<<" the fraction 2 greater than  or equal  fraction 1 : "<<" true "<<endl;
    }
    else
        cout<<" the fraction 2 greater than or equal fraction 1 : "<<" false "<<endl;
    cout<<endl;

    return 0;
}

