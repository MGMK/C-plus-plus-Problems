#include "fraction.h"
#include<iostream>
using namespace std;
fraction::fraction()
{

}
fraction::fraction(int a,int b)
{
    num_1=a;
    num_2=b;
    fraction_Reduce() ;
}
void fraction::fraction_Reduce()
{
    int x = min(num_1,num_2), gcd = 1;
    for  (int i=1; i<=x; i++)
    {
         if(num_1%i==0 && num_2%i==0)
        {
            gcd = i ;
        }
    }
    num_1 /= gcd ;
    num_2 /= gcd ;

}
fraction fraction:: operator +(fraction f2)
{

    fraction object;
    object.num_1=num_1*f2.num_2+num_2*f2.num_1;
    object.num_2=num_2*f2.num_2;
    return object;

}
fraction fraction:: operator -(fraction f2)
{

    fraction object;
    object.num_1=num_1*f2.num_2-num_2*f2.num_1;
    object.num_2=num_2*f2.num_2;
    return object;
}
fraction fraction:: operator*(fraction f2)
{
    fraction of;
    of.num_1=num_1*f2.num_1;
    of.num_2=num_2*f2.num_2;
    return of;
}
fraction fraction:: operator/(fraction f2)
{
    fraction mut;
    mut.num_1=num_1*f2.num_2;
    mut.num_2=num_2*f2.num_1;
    return mut;
}
bool fraction  ::operator <(fraction f2)
{
    fraction ob;
    float numeric1,numeric2;
    numeric1=num_1/num_2;
    numeric2=ob.num_1/ob.num_2;
    if (numeric1<numeric2)
    {
        return true;
    }
    else
        return false;

}
bool fraction:: operator >(fraction f2)
{
    fraction ob1;
    float numeric1,numeric2;
    numeric1=num_1/num_2;
    numeric2=ob1.num_1/ob1.num_2;
    if (numeric1>numeric2)
    {
        return true;
    }
    else
        return false;
}
bool fraction::operator ==(fraction f2)
{
    fraction ob2;
    float numeric1,numeric2;
    numeric1=num_1/num_2;
    numeric2=ob2.num_1/ob2.num_2;
    if (numeric1==numeric2)
    {
        return true;
    }
    else
        return false;
}
bool fraction:: operator <=(fraction f2)
{
    fraction ob3;
    float numeric1,numeric2;
    numeric1=num_1/num_2;
    numeric2=ob3.num_1/ob3.num_2;
    if (numeric1<=numeric2)
    {
        return true;
    }
    else
        return false;

}
bool fraction :: operator >=(fraction f2)
{
    fraction ob4;
    float numeric1,numeric2;
    numeric1=num_1/num_2;
    numeric2=ob4.num_1/ob4.num_2;
    if (numeric1>=numeric2)
    {
        return true;
    }
    else
        return false;

}

