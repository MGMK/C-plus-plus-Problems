#include "Vending_Machine_comstumer.h"
#include "Vending_Machine_Items.h"
#include<iostream>
using namespace std;

void Vending_Machine_comstumer::Vending_Machine_Money_input()
{
    cout << "Welcome Sir How Much You Have ?\nYour Input Should Be ( 0.5 or 1 or 5 or 10 or 20) Bound .\n\nEnter Your Money Please:";
    cin >> input_money;


    while ( input_money != 0.5 && input_money != 1 && input_money != 5 && input_money != 10 && input_money != 20)
    {
        cout << "Your Money Not In Rang\n";
        cout << "Enter Your Money Again Please :";
        cin >> input_money ;

        if ( (input_money == 0.5) ||  (input_money == 1) || (input_money == 5) || (input_money == 10) || (input_money == 20) )
        {
            break;
        }
    }
}
void Vending_Machine_comstumer::break_fun()
{
    while(true)
        break;
}


