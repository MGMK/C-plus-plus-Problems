#include "BigDecimalInt.h"
#include <iostream>
#include<string>
using namespace std;

int main()
{
    BigDecimalInt num1("111111111111111111111111111111"),num2("222222222222222222222222222223");
    cout<<num1-num2;

    return 0;
}
