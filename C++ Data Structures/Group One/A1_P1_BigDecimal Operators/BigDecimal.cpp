#include "BigDecimal.h"
#include <iostream>
#include <string>
using namespace std;
BigDecimal::BigDecimal()
{
    num1="";
    //ctor
}
BigDecimal::BigDecimal(string num1)
{
    this-> num1=num1;

    //ctor
}

BigDecimal BigDecimal:: CallException (BigDecimal &num2){
    int diff=0;
    /// size of two numbers is equal.
    if(num1.size()==num2.num1.size())
    {
        /// case one
        if(num1[0]<num2.num1[0])
        {
            string temp ;
            temp=num1;
            num1=num2.num1;  /// swap .
            num2.num1=temp;
            /// //////////////
            diff=num1.size()-num2.num1.size(); /// find diff between them .
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48); /// convert int num1 to string .
                num2.num1[i]=int(num2.num1[i]-48);  /// convert int num2 to string .
                /// if bit of num1 < bit of num2 make diff
                if(num1[i]<num2.num1[i]) /// take remeder from next bit after swap.
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48); /// convert to char

                }
                if(num1[i]>=num2.num1[i])  /// if bit of num1 > bit of num2 make diff
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            return num2;
        }

        else
        {
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            cout<<"-";
            return num2;

        }
    }
}
BigDecimal BigDecimal:: CallFunctionSubtract (BigDecimal &num2)
{
    int diff=0,counter=0;
    /// if length of num1 > length of num2
    if(num1.size()>num2.num1.size())
    {
        diff=num1.size()-num2.num1.size();

        while(counter<diff)
        {
            /// increase 0 in left of num1 .
            num2.num1='0'+num2.num1;
            counter++;
        }
        for(int i=num1.size()-1; i>=0; i--)
        {
            num1[i]=int(num1[i]-48);
            num2.num1[i]=int(num2.num1[i]-48);

            if(num1[i]<num2.num1[i])
            {
                num1[i]=num1[i]+10;
                num1[i-1]=num1[i-1]-1;
                num2.num1[i]=num1[i]-num2.num1[i];
                num2.num1[i]=char(num2.num1[i]+48);
            }
            if(num1[i]>=num2.num1[i])
            {
                num2.num1[i]=(num1[i]-num2.num1[i]);
                num2.num1[i]=char(num2.num1[i]+48);
            }

        }
        num2.num1='-'+num2.num1;;
        return num2;
    }
    /// if length of num1 < length of num2
    if(num1.size()<num2.num1.size())
    {
        string temp ;
        temp=num1;
        num1=num2.num1;
        num2.num1=temp;
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            /// increase 0 in left of num2 .
            num2.num1='0'+num2.num1;
            counter++;
        }
        for(int i=num1.size()-1; i>=0; i--)
        {
            num1[i]=int(num1[i]-48);
            num2.num1[i]=int(num2.num1[i]-48);
            if(num1[i]<num2.num1[i])
            {
                num1[i]=num1[i]+10;
                num1[i-1]=num1[i-1]-1;
                num2.num1[i]=num1[i]-num2.num1[i];
                num2.num1[i]=char(num2.num1[i]+48);
            }
            if(num1[i]>=num2.num1[i])
            {
                num2.num1[i]=(num1[i]-num2.num1[i]);
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        return num2;
    }
    /// if length of num1 == length of num2
    if(num1.size()==num2.num1.size())
    {
        if(num1[0]<num2.num1[0])
        {
            string temp ;
            temp=num1;
            num1=num2.num1;
            num2.num1=temp;
            diff=num1.size()-num2.num1.size();
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            cout<<"-";
            return num2;
        }
        else
        {
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            return num2;

        }
    }
}

BigDecimal BigDecimal:: CallFunctionSum (BigDecimal &num2)
{
    int diff=0,counter=0;

    if(num1.size()>num2.num1.size())
    {
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;
        }
    }

    if(num2.num1.size()>num1.size())
    {
        diff=num2.num1.size()-num1.size();
        while(counter<diff)
        {
            num1='0'+num1;
            counter++;
        }
    }
    for(int i=num1.size()-1; i>=0; i--)
    {
        num1[i]=int(num1[i]-48);
        num2.num1[i]=int(num2.num1[i]-48);
        /// if num1[i] +num2[i] >=10 make sum and increase 1 to next bit .
        if(num1[i]+num2.num1[i]>=10)
        {
            /// if i reach to final bit and sum of this bits > 10 i will make sum operation
            /// and this - 10 from result and i append 1 in finial bit .
            if(i==0)
            {
                num2.num1[i]=num1[i]+num2.num1[i];
                num2.num1[i]-=10;
                cout<<"1";
            }
            else
            {
                num2.num1[i]=(num1[i]+num2.num1[i])-10;
                num1[i-1]+=1;
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        else
        {
            num2.num1[i]=num1[i]+num2.num1[i];
            num2.num1[i]=char(num2.num1[i]+48);
        }
    }
    return num2;
    /// don't make diff if two number is equal in length .
    if(num1.size()==num2.num1.size())
    {
    for(int i=num1.size()-1; i>=0; i--)
    {
        num1[i]=int(num1[i]-48);
        num2.num1[i]=int(num2.num1[i]-48);
        if(num1[i]+num2.num1[i]>=10)
        {
            if(i==0)
            {
                num2.num1[i]=num1[i]+num2.num1[i];
                num2.num1[i]-=10;
                 num2.num1[i]='1'+num2.num1[i];
            }
            else
            {
                num2.num1[i]=(num1[i]+num2.num1[i])-10;
                num1[i-1]+=1;
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        else
        {
            num2.num1[i]=num1[i]+num2.num1[i];
            num2.num1[i]=char(num2.num1[i]+48);
        }
    }
    return num2;
}
}
BigDecimal BigDecimal:: operator+ (BigDecimal &num2)
{
    BigDecimal b3;
    bool c=true;
    int diff=0,counter=0;
    /// case one num1 start with - and num2 start with +
    /// and num1 == num2 return 0;
    if(num1[0]=='-' && num2.num1[0]!='-' ){
      num2.num1= '0';
      c=false;
        return num2;
    }
    /// case one num1 start with - and num2 start with +
    /// and num1 != num2 return 0;

    if(c==true){
    if(num1[0]=='-' && num2.num1[0]!='-')
    {
        num1.erase(num1.begin()+ 0) ; /// remove sign .
        if(num1.size()==num2.num1.size()){
        CallException(num2);
        }
        else{CallFunctionSubtract(num2);}
       //cout<<'-';
        return num2;
        }
    }
    if(num1[0]=='-' && num2.num1[0]=='-')
    {
    /// remove sign
    num1.erase(num1.begin()+ 0) ;
    num2.num1.erase(num2.num1.begin()+0);
    CallFunctionSum(num2);
    return num2;

    }
    /// if num1 is + and num2 is - call function subtract .
      if(num1[0]!='-' && num2.num1[0]=='-')
    {
        //num1.erase(num1.begin()+ 0) ;
        num2.num1.erase(num2.num1.begin()+0);
        if(num2.num1.size()>num1.size()){
            cout<<"-";
        CallFunctionSubtract(num2);
        }
        if(num2.num1.size()<num1.size()){
           // cout<<"-";
            CallFunctionSubtract(num2);
            num2.num1.erase(num2.num1.begin()+0);

        }
        return num2;
    }
    /// before this the signs is diff .
    /// in this step the signs is the same and signs is + make normal oprations .
    if(num1.size()>num2.num1.size())
    {
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;

        }
    }
    if(num2.num1.size()>num1.size())
    {
        diff=num2.num1.size()-num1.size();
        while(counter<diff)
        {
            num1='0'+num1;
            counter++;
        }
    }
    for(int i=num1.size()-1; i>=0; i--)
    {
        num1[i]=int(num1[i]-48);
        num2.num1[i]=int(num2.num1[i]-48);
        if(num1[i]+num2.num1[i]>=10)
        {
            if(i==0)
            {
                num2.num1[i]=num1[i]+num2.num1[i];
                num2.num1[i]-=10;
                cout<<"1";
            }
            else
            {
                num2.num1[i]=(num1[i]+num2.num1[i])-10;
                num1[i-1]+=1;
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        else
        {
            num2.num1[i]=num1[i]+num2.num1[i];
            num2.num1[i]=char(num2.num1[i]+48);
        }



    }
    return num2;

}
BigDecimal BigDecimal:: operator- (BigDecimal &num2)
{
    if(num2.num1 == num1){
        num2.num1= '0';
        return num2;
    }
    int diff=0,counter=0;
    if(num1[0]=='-' && num2.num1[0]!='-')
    {
        num1.erase(num1.begin()+ 0) ;
        CallFunctionSum(num2);
        cout<<'-';
        return num2;
    }
    if(num1[0]=='-' && num2.num1[0]=='-')
    {
        num1.erase(num1.begin()+ 0) ;
        num2.num1.erase(num2.num1.begin()+ 0) ;
        CallFunctionSubtract(num2);
        return num2;
    }
    if(num1[0]!='-' && num2.num1[0]=='-')
    {
        num2.num1.erase(num2.num1.begin()+ 0) ;
        CallFunctionSum(num2);
        return num2;
    }
    if(num1.size()>num2.num1.size())
    {
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;
        }
        for(int i=num1.size()-1; i>=0; i--)
        {
            num1[i]=int(num1[i]-48);
            num2.num1[i]=int(num2.num1[i]-48);
            if(num1[i]<num2.num1[i])
            {
                num1[i]=num1[i]+10;
                num1[i-1]=num1[i-1]-1;
                num2.num1[i]=num1[i]-num2.num1[i];
                num2.num1[i]=char(num2.num1[i]+48);
            }
            if(num1[i]>=num2.num1[i])
            {
                num2.num1[i]=(num1[i]-num2.num1[i]);
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        return num2;
    }
    if(num1.size()<num2.num1.size())
    {
        string temp ;
        temp=num1;
        num1=num2.num1;
        num2.num1=temp;
        diff=num1.size()-num2.num1.size();
        while(counter<diff)
        {
            num2.num1='0'+num2.num1;
            counter++;
        }
        for(int i=num1.size()-1; i>=0; i--)
        {
            num1[i]=int(num1[i]-48);
            num2.num1[i]=int(num2.num1[i]-48);
            if(num1[i]<num2.num1[i])
            {
                num1[i]=num1[i]+10;
                num1[i-1]=num1[i-1]-1;
                num2.num1[i]=num1[i]-num2.num1[i];
                num2.num1[i]=char(num2.num1[i]+48);
            }
            if(num1[i]>=num2.num1[i])
            {
                num2.num1[i]=(num1[i]-num2.num1[i]);
                num2.num1[i]=char(num2.num1[i]+48);
            }
        }
        cout<<"-";
        return num2;
    }
    if(num1.size()==num2.num1.size())
    {
        if(num1[0]<num2.num1[0])
        {
            string temp ;
            temp=num1;
            num1=num2.num1;
            num2.num1=temp;
            diff=num1.size()-num2.num1.size();
            while(counter<diff)
            {
                num2.num1='0'+num2.num1;
                counter++;
            }
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            cout<<"-";
            return num2;
        }
        else
        {
            for(int i=num1.size()-1; i>=0; i--)
            {
                num1[i]=int(num1[i]-48);
                num2.num1[i]=int(num2.num1[i]-48);
                if(num1[i]<num2.num1[i])
                {
                    num1[i]=num1[i]+10;
                    num1[i-1]=num1[i-1]-1;
                    num2.num1[i]=num1[i]-num2.num1[i];
                    num2.num1[i]=char(num2.num1[i]+48);
                }
                if(num1[i]>=num2.num1[i])
                {
                    num2.num1[i]=(num1[i]-num2.num1[i]);
                    num2.num1[i]=char(num2.num1[i]+48);
                }
            }
            return num2;

        }
    }
}
ostream&operator<<(ostream&out,const BigDecimal &big)
{
    for(int i=0; i<big.num1.size(); i++)
    {
        out<<big.num1[i];

    }
    return out;
}

