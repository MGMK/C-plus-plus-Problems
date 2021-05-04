#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H
#include <iostream>
using namespace std;
class BigDecimal
{

    private:
    string num1;
    public:
        BigDecimal();
        BigDecimal (string num1); // Initialize from string
        BigDecimal (int decInt); // Initialize from integer
        BigDecimal operator+ (BigDecimal &anotherDec);
        BigDecimal operator- (BigDecimal &anotherDec);
        BigDecimal CallFunctionSum (BigDecimal &anotherDec);
         BigDecimal CallFunctionSubtract (BigDecimal &anotherDec);
         BigDecimal  CallException (BigDecimal &anotherDec);
        friend ostream&operator<<(ostream&out,const BigDecimal &big);
         bool operator== (BigDecimal &anotherDec);

   // protected:

};

#endif // BIGDECIMAL_H
