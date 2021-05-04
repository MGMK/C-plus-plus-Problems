#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std ;

class fraction
{
public:
    fraction();
    int num_1,num_2;
    fraction (int num_1,int num_2);
    fraction operator+(fraction f2);
    fraction operator-(fraction f2);
    fraction operator*(fraction f2);
    fraction operator/(fraction f2);

    bool operator <(fraction f2);
    bool operator >(fraction f2);
    bool operator ==(fraction f2);
    bool operator <=(fraction f2);
    bool operator >=(fraction f2);

    void fraction_Reduce();

    friend istream& operator >> (istream& in, fraction & f1);
    friend ostream& operator << (ostream& out, fraction & f1);

};

#endif // FRACTION_H
