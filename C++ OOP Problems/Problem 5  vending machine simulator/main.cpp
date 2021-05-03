#include "Vending_Machine_Items.h"
#include<iostream>
using namespace std;

int main()
{



    Vending_Machine_Items object;
    object.Vending_Machine_Money_input();
    object.Vending_Machine_Choices_Items();
    object.Vending_Machine_Money();

    int number;
    cout << "\n1- If You want to Anther Product .\n2- To Enter new money .\n3- IF You Want To End program .\nEnter Your Choose Please :";
    cin >> number;

    while(number==1)
    {
        object.Vending_Machine_Anther_choice();
        if (object.item_Choice_number == 0){break;}
        while (object.new_temp == 0)
        {
            break;
        };
    }
    while ( number == 2)
    {
        object.Vending_Machine_Money_repeat_input();
        break;
    }
    while ( number != 2 || number != 1)
    {
        break;
    }

    return 0;
}
