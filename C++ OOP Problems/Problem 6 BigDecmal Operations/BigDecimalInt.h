#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include<string>
#include<iostream>
using namespace std;
class BigDecimalInt
{
private:
    string decS;
    int deci;
public:
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    BigDecimalInt operator+ (BigDecimalInt another);
    BigDecimalInt operator- (BigDecimalInt another);
    friend ostream&operator<<(ostream &out,BigDecimalInt another);
    int define();
};

#endif // BIGDECIMALINT_H
