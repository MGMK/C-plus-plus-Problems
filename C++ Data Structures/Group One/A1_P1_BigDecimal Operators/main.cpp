#include <iostream>
#include "BigDecimal.h"
using namespace std;
int main()
{
    BigDecimal num1 ("-600000");
    BigDecimal num2 ("600000");
    BigDecimal num3("2000022222222222222222222222");
    BigDecimal num4("255555555555555555555555550");
    cout<<"sum is"<<endl;
    cout<<num1+num2<<endl<<endl;;
    cout<<"Diffrenece is "<<endl;
    cout<<num3-num4<<endl<<endl;;
    return 0;
}
