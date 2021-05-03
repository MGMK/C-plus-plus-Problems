#include "BigDecimalInt.h"
#include<string>
#include<iostream>
#include<cmath>
using namespace std;

int BigDecimalInt:: define()
{

long long c = 0 ;
for (int i=decS.size()-1 ; i>=0 ;--i){
    c += ((decS[i]-'0')*pow(10,(decS.size()-1)-i));
return c ;
}


}
BigDecimalInt::BigDecimalInt(string decStr)
{
    decS=decStr;
    deci=0;
}

BigDecimalInt::BigDecimalInt(int decInt)
{
    deci=decInt;

}
BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt another)
{
    if(deci=0){
    int carry = 0 ;
    if(decS.size() < another.decS.size())
        swap(decS , another.decS);
    for (int i = (decS.size() - another.decS.size()-1) ; i>=0 ; --i)
        another.decS.insert(0,"0");
    for (int i = decS.size()-1 ; i >= 0 ; --i)
    {
        if (i > 0)
            decS[i] = ( ( (decS[i]-'0') + (another.decS[i]-'0') + carry) % 10 ) + '0';
        else
            decS[i] =  (decS[i]-'0') + (another.decS[i]-'0' ) + carry + '0' ;

        if ((decS[i]-'0')+(another.decS[i]-'0') > 9)
            carry = 1 ;
        else
            carry = 0 ;
    }
    int counter=0;
        for (int i = 0; i < decS.size();i++) {
            if (decS[i]-'0'==0) counter++;
            else break ;
    }
    if (decS[0]-'0'==0) decS.erase(0,counter);
    return decS ;
    }

}
BigDecimalInt BigDecimalInt:: operator- (BigDecimalInt another)
{
    if(decS.size() < another.decS.size() || define() < another.define()){
            swap(decS,another.decS);
            cout<<"-";
    }
    for (int i = (decS.size()-another.decS.size()-1) ; i>=0 ; --i) another.decS.insert(0,"0");
    for (int i = decS.size()-1 ; i >= 0 ; --i)
    {

        if (decS[i] >= another.decS[i]) another.decS[i] = (decS[i]-'0')-(another.decS[i]-'0')+ '0' ;
        else {
            another.decS[i] = ((decS[i]-'0') - (another.decS[i]-'0'))+10 + '0' ;
            if (i != 0) decS[i-1] = (decS[i-1]-'1')+ '0'  ;
            }
        }
    int counter=0;
    int i ;
    if ((int)another.decS[0]==45) i = 1;
    else  i = 0;
    for (i; i < another.decS.size();i++) {
            if (another.decS[i]-'0'==0) counter++;
            else break ;
    }
    if (another.decS[0]-'0'==0) another.decS.erase(0,counter);

    return another.decS ;
}


ostream&operator<<(ostream &out,BigDecimalInt another)
{
out<<another.decS;
return out;
}

