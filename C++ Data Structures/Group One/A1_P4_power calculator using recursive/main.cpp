#include <iostream>
int power(int a,unsigned int n);
int power1(int a,unsigned int n);
using namespace std;
int power(int a,unsigned int n)
{
    if(n==0)
        return 1;
    else
        return a*power(a,n-1);
}
int power1(int a,unsigned int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return a;
    else if(n%2==0)
        return power1(a,n/2)*power1(a,n/2);
    else if(n%2!=0)
        return  a*power1(a,n/2)*power1(a,n/2);
}
int main()
{

cout<<power1(3,2);
    return 0;
}
