#include "Vending_Machine_Items.h"
#include<iostream>
#include<fstream>
using namespace std;

Vending_Machine_Items::Vending_Machine_Items()
{
    //ctor
}

void Vending_Machine_Items::Vending_Machine_Money_input()
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
void Vending_Machine_Items::break_fun()
{
    while(true)
        break;
}
/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Vending_Machine_Items::Vending_Machine_Money_repeat_input()
{

    Vending_Machine_Money_input();
    Vending_Machine_Choices_Items();
    Vending_Machine_Money();
}

void Vending_Machine_Items::Vending_Machine_Anther_choice()
{
    cout <<"\n\n\nWelcome In Vending Machine .\n\n1- Pepsi\t\t\tPrice : 5  \tBound .\n2- Coffee\t\t\tPrice : 6  \tBound .\n3- Chocolate\t\t\tPrice : 15 \tBound .\n4- Ice Cream\t\t\tPrice : 10 \tBound .";
    cout << "\n5- Branch\t\t\tPrice : 4  \tBound .\n6- 7 Up\t\t\t\tPrice : 6  \tBound .\n7- Bonbonne\t\t\tPrice : 0.5 \tBound .\n8- Chipsy\t\t\tPrice : 20  \tBound .\n9- CocaCola\t\t\tPrice : 7  \tBound .";
    cout << "\n10- Chocolate Sweets\t\tPrice : 1  \tBound .\n0- If You Want To Retrieve Your Money And End Process .";
    cout << "\n\nEnter Your Choice Please:";
    cin >> item_Choice_number;
    while (new_temp > 0.5)
    {

        if (item_Choice_number == 1)    /// case one
        {

            if ( new_temp >= 5 )
            {
                if ( counter1 > 0){


                /// ///////// Case One . /////Case One .///////////////Case One ./////////////////Case One .//////////////////Case One .//////////////Case One .//////////Case One ./////////////

                if ( item_Choice_number == 1 && new_temp >= 5 )                             /// in case is  number of choice from list and the price input is >= 5 Bound
                {
                    cout << "Enter Number You Need From This Item :";
                    cin >> number_of_item;                                                       /// number of product

                    if ( number_of_item == 1 && new_temp >= 5)                              /// if choice number is 1 ( Pepsi Product ) and user need one input
                    {
                        cout << "\nPepsi Good Choice .\nYour Order Will Ready Now .\n";
                        new_temp= new_temp - (number_of_item*5);     /// to print the new reminder in anther item fun but in time more than 1
                        cout << "\nYour New Remaining Money is : " << new_temp << endl;

                        /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        ifstream myfile ("Pepsi.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter1 = array1[counter] ;
                                ++counter;
                            }
                        }
                        counter1 = counter1 - number_of_item ;
                        fstream file ("Pepsi.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter1 ;
                        }




                        break;
                    }
                    if ( number_of_item > 1 )
                    {
                        if (  new_temp >= 10 ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                        {
                            cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";
                            new_temp= new_temp - (number_of_item*5);    /// to print the new reminder in anther item fun but in time more than 1
                            cout << "\nYour New Remaining Money is : " << new_temp << endl;

                            /// File Part For Counter .
                            /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .
                            ifstream myfile ("Pepsi.txt",ios::in);
                            int counter = 0;
                            int array1[1];
                            if (myfile.is_open())
                            {
                                while (myfile >> array1[counter])
                                {
                                    counter1 = array1[counter] ;
                                    ++counter;
                                }
                            }
                            counter1 = counter1 - number_of_item ;
                            fstream file ("Pepsi.txt",ios::out);

                            if (file.is_open())
                            {
                                file << counter1 ;
                            }
                            if ( counter1 == 0)
                            {
                                cout << "This Item is Empty .\n" ;
                                break_fun();
                            }

                            break;
                        }
                        else                          /// if money == 5 and user need more than one product .
                        {
                            cout << "\nYour Money is Not Enough .\n";
                            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                            break;
                        }

                    }

                }
                if (new_temp < 5 )                          /// if money less than 5 bound .
                {
                    cout << "Your Money Is Not Enough . << Sorry >> ";
                    Vending_Machine_Money_repeat_input();
                    break;
                }
            }

            else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }

            }
        }
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (item_Choice_number == 2){
        if ( new_temp >= 6 ) /// case two
        {
                if ( counter2 > 0 ){
                /// ///////// Case Two . /////Case Two .///////////////Case Two ./////////////////Case Two .//////////////////Case Two .//////////////Case Two .//////////Case Two ./////////////

                if ( item_Choice_number == 2 && new_temp >= 6 )                             /// in case is  number of choice from list and the price input is >= 6 Bound
                {
                    cout << "Enter Number You Need From This Item :";
                    cin >> number_of_item;                                                       /// number of product

                    if ( number_of_item == 1 && new_temp >= 6)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
                    {
                        cout << "\nCoffee Good Choice .\nYour Order Will Ready Now .\n";
                        new_temp= new_temp - (number_of_item*6);    /// to print the new reminder in anther item fun but in time more than 1
                        cout << "\nYour New Remaining Money is : " << new_temp << endl;
                    /// File Part For Counter .
                    /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                    ifstream myfile ("Coffee.txt",ios::in);
                    int counter = 0;
                    int array1[1];
                    if (myfile.is_open())
                    {
                        while (myfile >> array1[counter])
                        {
                            counter2 = array1[counter] ;
                            ++counter;
                        }
                    }
                    counter2 = counter2 - number_of_item ;
                    fstream file ("Coffee.txt",ios::out);

                    if (file.is_open())
                    {
                        file << counter2 ;
                    }
                    if ( counter2 == 0)
                    {
                        cout << "This Item is Empty .\n" ;
                        break_fun();
                    }
                        break;

//                Vending_Machine_Money();

                    }
                    if ( number_of_item > 1 )
                    {
                        if ( new_temp >= 12 ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                        {
                            cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";
                            new_temp= new_temp - (number_of_item*6);    /// to print the new reminder in anther item fun but in time more than 1
                            cout << "\nYour New Remaining Money is : " << new_temp << endl;
                     /// File Part For Counter .
                    /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                    ifstream myfile ("Coffee.txt",ios::in);
                    int counter = 0;
                    int array1[1];
                    if (myfile.is_open())
                    {
                        while (myfile >> array1[counter])
                        {
                            counter2 = array1[counter] ;
                            ++counter;
                        }
                    }
                    counter2 = counter2 - number_of_item ;
                    fstream file ("Coffee.txt",ios::out);

                    if (file.is_open())
                    {
                        file << counter2 ;
                    }
                    if ( counter2 == 0)
                    {
                        cout << "This Item is Empty .\n" ;
                        break_fun();
                    }
                           break;
                        }
                        else                          /// if money == 5 and user need more than one product .
                        {
                            cout << "\nYour Money is Not Enough .\n";
                            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                            break;
                        }


                    }

                }
                if(new_temp < 6)
                {
                    cout <<"Your Money is Not Enough . << Thanks >> \n";
                    Vending_Machine_Money_repeat_input();
                    break;
                }
            }
            else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }
    }

/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if ( item_Choice_number == 3) /// case three
        {
            if (counter3 > 0 ){

            /// ///////// Case Three . /////Case Three .///////////////Case Three ./////////////////Case Three .//////////////////Case Three .//////////////Case Three. //////////////

            if (  new_temp >= 15 )                             /// in case is  number of choice from list and the price input is >= 15 Bound
            {
                cout << "Enter Number You Need From This Item :";
                cin >> number_of_item;                                                       /// number of product

                if ( number_of_item == 1 && new_temp >= 15)                              /// if choice number is 3 ( Pepsi Product ) and user need one input
                {
                    cout << "\nChocolate Good Choice .\nYour Order Will Ready Now .\n";
                    new_temp= new_temp - (number_of_item*15);    /// to print the new reminder in anther item fun but in time more than 1
                    cout << "\nYour New Remaining Money is : " << new_temp << endl;
                    /// File Part For Counter .
                    /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                    ifstream myfile ("Chocolate.txt",ios::in);
                    int counter = 0;
                    int array1[1];
                    if (myfile.is_open())
                    {
                        while (myfile >> array1[counter])
                        {
                            counter3 = array1[counter] ;
                            ++counter;
                        }
                    }
                    counter3 = counter3 - number_of_item ;
                    fstream file ("Chocolate.txt",ios::out);

                    if (file.is_open())
                    {
                        file << counter3 ;
                    }
                    if ( counter3 == 0)
                    {
                        cout << "This Item is Empty .\n" ;
                        break_fun();
                    }

                    break;

                }
                else                          /// if money == 5 and user need more than one product .
                {
                    cout << "\nYour Money is Not Enough .\n";
                    Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                    break;
                }


            }



            if(new_temp < 15)
            {
                cout <<"Your Money is Not Enough . << Thanks >> \n";
                Vending_Machine_Money_repeat_input();
                break;
            }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }




/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if ( item_Choice_number == 4) /// case four
        {
            if ( counter4 > 0 ){
            if ( new_temp >= 10 )
            {
                /// ///////// Case Four . /////Case Four .///////////////Case Four ./////////////////Case Four .//////////////////Case Four .//////////////Case Four. //////////////

                if ( item_Choice_number == 4 && new_temp >= 10 )                             /// in case is  number of choice from list and the price input is >= 10 Bound
                {
                    cout << "Enter Number You Need From This Item :";
                    cin >> number_of_item;                                                       /// number of product

                    if ( number_of_item == 1 && new_temp >= 10)                              /// if choice number is 4 ( Pepsi Product ) and user need one input
                    {
                        cout << "\nIce Cream Good Choice .\nYour Order Will Ready Now .\n";
                        new_temp= new_temp - (number_of_item*10);    /// to print the new reminder in anther item fun but in time more than 1
                        cout << "\nYour New Remaining Money is : " << new_temp << endl;
                        /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        ifstream myfile ("Ice_Cream.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter4 = array1[counter] ;
                                ++counter;
                            }
                        }
                        counter4 = counter4 - number_of_item ;
                        fstream file ("Ice_Cream.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter4 ;
                        }
                        if ( counter4 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                        break;
//                Vending_Machine_Money();
                    }
                }
                if(new_temp < 10)
                {
                    cout <<"Your Money is Not Enough . << Thanks >> \n";
                    Vending_Machine_Money_repeat_input();
                    break;
                }
            }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }


/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        if ( item_Choice_number == 5) /// case five
        {
            if ( counter5  > 0 ){
            if ( new_temp >= 4 )
            {
                /// ///////// Case Five . /////Case Five .///////////////Case Five ./////////////////Case Five .//////////////////Case Five .//////////////Case Five. //////////////

                if ( item_Choice_number == 5 && new_temp >= 4 )                             /// in case is  number of choice from list and the price input is >= 4 Bound
                {
                    cout << "Enter Number You Need From This Item :";
                    cin >> number_of_item;                                                       /// number of product

                    if ( number_of_item == 1 && new_temp >= 4)                              /// if choice number is 5 ( Pepsi Product ) and user need one input
                    {
                        cout << "\nBranch Good Choice .\nYour Order Will Ready Now .\n";
                        new_temp= new_temp - (number_of_item*4);    /// to print the new reminder in anther item fun but in time more than 1
                        cout << "\nYour New Remaining Money is : " << new_temp << endl;
                        /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        ifstream myfile ("Branch.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter5 = array1[counter] ;
                                ++counter;
                            }
                        }
                        counter5 = counter5 - number_of_item ;
                        fstream file ("Branch.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter5 ;
                        }
                        if ( counter5 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                        break;
//                Vending_Machine_Money();
                    }
                    if ( number_of_item > 1 )
                    {
                        if ( new_temp >= 8  ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                        {
                            cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";
                            new_temp= new_temp - (number_of_item*4);    /// to print the new reminder in anther item fun but in time more than 1
                            cout << "\nYour New Remaining Money is : " << new_temp << endl;
                            /// File Part For Counter .
                            /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                            ifstream myfile ("Branch.txt",ios::in);
                            int counter = 0;
                            int array1[1];
                            if (myfile.is_open())
                            {
                                while (myfile >> array1[counter])
                                {
                                    counter5 = array1[counter] ;
                                    ++counter;
                                }
                            }
                            counter5 = counter5 - number_of_item ;
                            fstream file ("Branch.txt",ios::out);

                            if (file.is_open())
                            {
                                file << counter5 ;
                            }
                            if ( counter5 == 0)
                            {
                                cout << "This Item is Empty .\n" ;
                                break_fun();
                            }
                            break;
                        }
                        else                          /// if money == 5 and user need more than one product .
                        {
                            cout << "\nYour Money is Not Enough .\n";
                            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                            break;
                        }


                    }

                }
                if(new_temp < 4)
                {
                    cout <<"Your Money is Not Enough . << Thanks >> \n";
                    Vending_Machine_Money_repeat_input();
                    break;
                }
            }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }


/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        if (item_Choice_number == 6) /// case six
        {
            if ( counter6 > 0 ){
            if ( new_temp >= 6 )
            {
                /// ///////// Case Six . /////Case Six .///////////////Case Six ./////////////////Case Six .//////////////////Case Six .//////////////Case Six .//////////Case Six ./////////

                if ( item_Choice_number == 6 && new_temp >= 6 )                             /// in case is  number of choice from list and the price input is >= 6 Bound
                {
                    cout << "Enter Number You Need From This Item :";
                    cin >> number_of_item;                                                       /// number of product

                    if ( number_of_item == 1 && new_temp >= 6)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
                    {
                        cout << "\7 Up Good Choice .\nYour Order Will Ready Now .\n";
                        new_temp= new_temp - (number_of_item*6);    /// to print the new reminder in anther item fun but in time more than 1
                        cout << "\nYour New Remaining Money is : " << new_temp << endl;
                        /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        ifstream myfile ("7_Up.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter6 = array1[counter] ;
                                ++counter;
                            }
                        }
                        counter6 = counter6 - number_of_item ;
                        fstream file ("7_Up.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter6 ;
                        }
                        if ( counter6 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                        break;
//                Vending_Machine_Money();
                    }
                    if ( number_of_item > 1 )
                    {
                        if (  new_temp >= 12 ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                        {
                            cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";
                            new_temp= new_temp - (number_of_item*6);    /// to print the new reminder in anther item fun but in time more than 1
                            cout << "\nYour New Remaining Money is : " << new_temp << endl;
                            /// File Part For Counter .
                            /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                            ifstream myfile ("7_Up.txt",ios::in);
                            int counter = 0;
                            int array1[1];
                            if (myfile.is_open())
                            {
                                while (myfile >> array1[counter])
                                {
                                    counter6 = array1[counter] ;
                                    ++counter;
                                }
                            }
                            counter6 = counter6 - number_of_item ;
                            fstream file ("7_Up.txt",ios::out);

                            if (file.is_open())
                            {
                                file << counter6 ;
                            }
                            if ( counter6 == 0)
                            {
                                cout << "This Item is Empty .\n" ;
                                break_fun();
                            }
                            break;
                        }
                        else                          /// if money == 5 and user need more than one product .
                        {
                            cout << "\nYour Money is Not Enough .\n";
                            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                            break;
                        }


                    }
                }
                if(new_temp < 6)
                {
                    cout <<"Your Money is Not Enough . << Thanks >> \n";
                    Vending_Machine_Money_repeat_input();
                    break;
                }
            }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }


/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        if (  item_Choice_number == 7) /// case seven
        {
            if ( counter7 > 0 ){
            if ( new_temp >= 0.5 )
            {
                /// ///////// Case Seven . /////Case Seven .///////////////Case Seven ./////////////////Case Seven .//////////////////Case Seven .//////////////Case Seven .///Case Seven .///

                if ( item_Choice_number == 7 && new_temp >= 0.5)                             /// in case is  number of choice from list and the price input is >= 0.5 Bound
                {
                    cout << "Enter Number You Need From This Item :";
                    cin >> number_of_item;                                                       /// number of product

                    if ( number_of_item == 1 && new_temp >= 0.5)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
                    {
                        cout << "\nBonbonne Good Choice .\nYour Order Will Ready Now .\n";
                        new_temp= new_temp - (number_of_item*0.5);    /// to print the new reminder in anther item fun but in time more than 1
                        cout << "\nYour New Remaining Money is : " << new_temp << endl;
                        /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        ifstream myfile ("Bonbonne.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter7 = array1[counter] ;
                                ++counter;
                            }
                        }
                        counter7 = counter7 - number_of_item ;
                        fstream file ("Bonbonne.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter7 ;
                        }
                        if ( counter7 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                        break;
//                Vending_Machine_Money();
                    }
                    if ( number_of_item > 1  )
                    {
                        if ( new_temp >= 1  ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                        {
                            cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";
                            new_temp= new_temp - (number_of_item*0.5);    /// to print the new reminder in anther item fun but in time more than 1
                            cout << "\nYour New Remaining Money is : " << new_temp << endl;
                            /// File Part For Counter .
                            /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                            ifstream myfile ("Bonbonne.txt",ios::in);
                            int counter = 0;
                            int array1[1];
                            if (myfile.is_open())
                            {
                                while (myfile >> array1[counter])
                                {
                                    counter7 = array1[counter] ;
                                    ++counter;
                                }
                            }
                            counter7 = counter7 - number_of_item ;
                            fstream file ("Bonbonne.txt",ios::out);

                            if (file.is_open())
                            {
                                file << counter7 ;
                            }
                            if ( counter7 == 0)
                            {
                                cout << "This Item is Empty .\n" ;
                                break_fun();
                            }
                            break;
                        }

                    }

                }
                if(new_temp < 0.5)
                {
                    cout <<"Your Money is Not Enough . << Thanks >> \n";
                    Vending_Machine_Money_repeat_input();
                    break;
                }
            }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }



/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        if ( item_Choice_number == 8)
        {
            cout <<"Your Money is Not Enough . << Thanks >> \n";
            Vending_Machine_Money_repeat_input();
            break;   /// the max money user will input it is 20 so no reminder money in this case .
        }


/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        if (item_Choice_number == 9) /// case nine
        {
            if ( counter9 > 0 ){
            if ( new_temp >= 7 )
            {
                /// ///////// Case Nine . ///Case Nine .//////////Case Nine .//////////Case Nine .//////////////////Case Nine .//////////////Case Nine .///Case Nine .///

                if ( item_Choice_number == 9 && new_temp >= 7)                             /// in case is  number of choice from list and the price input is >= 7 Bound
                {
                    cout << "Enter Number You Need From This Item :";
                    cin >> number_of_item;                                                       /// number of product

                    if ( number_of_item == 1 && new_temp >= 7)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
                    {
                        cout << "\nCocaCola Good Choice .\nYour Order Will Ready Now .\n";
                        new_temp= new_temp - (number_of_item*7);    /// to print the new reminder in anther item fun but in time more than 1
                        cout << "\nYour New Remaining Money is : " << new_temp << endl;
                        /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        ifstream myfile ("CocaCola.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter9 = array1[counter] ;
                                ++counter;
                            }
                        }
                        counter9 = counter9 - number_of_item ;
                        fstream file ("CocaCola.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter9 ;
                        }
                        if ( counter9 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                        break;
//                Vending_Machine_Money();
                    }
                    if ( number_of_item > 1 )
                    {
                        if ( new_temp >= 14  ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                        {
                            cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";
                            new_temp= new_temp - (number_of_item*7);    /// to print the new reminder in anther item fun but in time more than 1
                            cout << "\nYour New Remaining Money is : " << new_temp << endl;
                            /// File Part For Counter .
                            /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                            ifstream myfile ("CocaCola.txt",ios::in);
                            int counter = 0;
                            int array1[1];
                            if (myfile.is_open())
                            {
                                while (myfile >> array1[counter])
                                {
                                    counter9 = array1[counter] ;
                                    ++counter;
                                }
                            }
                            counter9 = counter9 - number_of_item ;
                            fstream file ("CocaCola.txt",ios::out);

                            if (file.is_open())
                            {
                                file << counter9 ;
                            }
                            if ( counter9 == 0)
                            {
                                cout << "This Item is Empty .\n" ;
                                break_fun();
                            }
                            break;
                        }
                        else                          /// if money == 5 and user need more than one product .
                        {
                            cout << "\nYour Money is Not Enough .\n";
                            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                            break;
                        }

                    }

                }
                if(new_temp < 7)
                    cout <<"Your Money is Not Enough . << Thanks >> \n";
                Vending_Machine_Money_repeat_input();
                break;
            }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }




/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        if ( new_temp >= 1 && item_Choice_number == 10) /// case ten
        {
            if ( counter10 > 0){
            if ( new_temp >= 1 )
            {
                /// ///////// Case Ten . ///Case Ten .//////////Case Ten .//////////Case Ten .//////////////////Case Ten .//////////////Case Ten .///Case Ten .///

                if ( item_Choice_number == 10 && new_temp >= 1)                             /// in case is  number of choice from list and the price input is >= 1 Bound
                {
                    cout << "Enter Number You Need From This Item :";
                    cin >> number_of_item;                                                       /// number of product

                    if ( number_of_item == 1 && new_temp >= 1)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
                    {
                        cout << "\nChocolate Sweets Good Choice .\nYour Order Will Ready Now .\n";
                        new_temp= new_temp - (number_of_item*1);    /// to print the new reminder in anther item fun but in time more than 1
                        cout << "\nYour New Remaining Money is : " << new_temp << endl;
                        /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        ifstream myfile ("Chocolate_Sweets.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter10 = array1[counter] ;
                                ++counter;
                            }
                        }
                        counter10 = counter10 - number_of_item ;
                        fstream file ("Chocolate_Sweets.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter10 ;
                        }
                        if ( counter10 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                        break;
//                Vending_Machine_Money();
                    }
                    if ( number_of_item > 1 )
                    {
                        if ( new_temp >= 2) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                        {
                            cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";
                            new_temp= new_temp - (number_of_item*1);    /// to print the new reminder in anther item fun but in time more than 1
                            cout << "\nYour New Remaining Money is : " << new_temp << endl;
                            /// File Part For Counter .
                            /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                            ifstream myfile ("Chocolate_Sweets.txt",ios::in);
                            int counter = 0;
                            int array1[1];
                            if (myfile.is_open())
                            {
                                while (myfile >> array1[counter])
                                {
                                    counter10 = array1[counter] ;
                                    ++counter;
                                }
                            }
                            counter10 = counter10 - number_of_item ;
                            fstream file ("Chocolate_Sweets.txt",ios::out);

                            if (file.is_open())
                            {
                                file << counter10 ;
                            }
                            if ( counter10 == 0)
                            {
                                cout << "This Item is Empty .\n" ;
                                break_fun();
                            }
                            break;
                        }
                    }

                }
                if(new_temp < 1)
                {
                    cout <<"Your Money is Not Enough . << Thanks >> \n";
                    Vending_Machine_Money_repeat_input();
                    break;
                }
            }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }

    }
}

/// /////////////////////////////////////////////////////////////////////////// /////////////////// /// ///////////


void Vending_Machine_Items::Vending_Machine_Choices_Items()
{

    while ( (input_money == 0.5) ||  (input_money == 1) || (input_money == 5) || (input_money == 10) || (input_money == 20)  )
    {

        cout <<"\n\n\nWelcome In Vending Machine .\n\n1- Pepsi\t\t\tPrice : 5  \tBound .\n2- Coffee\t\t\tPrice : 6  \tBound .\n3- Chocolate\t\t\tPrice : 15 \tBound .\n4- Ice Cream\t\t\tPrice : 10 \tBound .";
        cout << "\n5- Branch\t\t\tPrice : 4  \tBound .\n6- 7 Up\t\t\t\tPrice : 6  \tBound .\n7- Bonbonne\t\t\tPrice : 0.5 \tBound .\n8- Chipsy\t\t\tPrice : 20  \tBound .\n9- CocaCola\t\t\tPrice : 7  \tBound .";
        cout << "\n10- Chocolate Sweets\t\tPrice : 1  \tBound .";
        cout << "\n\nEnter Your Choice Please:";
        cin >> item_Choice_number;

/// ///////// Case One . /////Case One .///////////////Case One ./////////////////Case One .//////////////////Case One .//////////////Case One .//////////Case One ./////////////
        if ( item_Choice_number == 1 ){
                /// File Part For Counter .
                /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .
                /// i do this step before if condition to load file number and = with counter1 becouse if i do not do this the compilor don't know counter1 and so what in anther cases .
                ifstream myfile ("Pepsi.txt",ios::in);
                int counter = 0;
                int array1[1];
                if (myfile.is_open())
                {
                    while (myfile >> array1[counter])
                    {
                        counter1 = array1[counter] ;
                        ++counter;
                    }
                }

            if ( counter1 > 0 ){
        if ( item_Choice_number == 1 && input_money >= 5 )    /// in case is  number of choice from list and the price input is >= 5 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 5)                              /// if choice number is 1 ( Pepsi Product ) and user need one input
            {
                cout << "\nPepsi Good Choice .\nYour Order Will Ready Now .\n";

                counter1 = counter1 - number_of_item ;
                fstream file ("Pepsi.txt",ios::out);

                if (file.is_open())
                {
                    file << counter1 ;
                }
                if ( counter1 == 0)
                {
                    cout << "This Item is Empty .\n" ;
                    break_fun();
                }



                break;
            }
            if ( number_of_item > 1 )
            {
                if ( input_money >= 10 ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                {
                    cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";

                    counter1 = counter1 - number_of_item ;
                    fstream file ("Pepsi.txt",ios::out);

                    if (file.is_open())
                    {
                        file << counter1 ;
                    }
                    if ( counter1 == 0)
                    {
                        cout << "This Item is Empty .\n" ;
                        break_fun();
                    }


                    break;
                }
                else                          /// if money == 5 and user need more than one product .
                {
                    cout << "\nYour Money is Not Enough .\n";
                    Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                    break;
                }

            }
        }
        if (item_Choice_number == 1 && input_money < 5 )                          /// if money less than 5 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> .";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;
        }
               }
               else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }



/// ///////// Case Two . /////Case Two .///////////////Case Two ./////////////////Case Two .//////////////////Case Two .//////////////Case Two .//////////Case Two ./////////////
        if ( item_Choice_number == 2 ){ifstream myfile ("Coffee.txt",ios::in);
                int counter = 0;
                int array1[1];
                if (myfile.is_open())
                {
                    while (myfile >> array1[counter])
                    {
                        counter2 = array1[counter] ;
                        ++counter;
                    }
                }
                if ( counter2 > 0){
        if ( item_Choice_number == 2 && input_money >= 6 )                             /// in case is  number of choice from list and the price input is >= 6 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 6)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
            {
                cout << "\nCoffee Good Choice .\nYour Order Will Ready Now .\n";
                /// File Part For Counter .
                /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .


                counter2 = counter2 - number_of_item ;
                fstream file ("Coffee.txt",ios::out);

                if (file.is_open())
                {
                    file << counter2 ;
                }
                if ( counter2 == 0)
                {
                    cout << "This Item is Empty .\n" ;
                    break_fun();
                }
                break;

//                Vending_Machine_Money();

            }
            if ( number_of_item > 1 )
            {
                if ( input_money >= 12) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                {
                    cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";

                    /// File Part For Counter .
                    /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .


                    counter2 = counter2 - number_of_item ;
                    fstream file ("Coffee.txt",ios::out);

                    if (file.is_open())
                    {
                        file << counter2 ;
                    }
                    if ( counter2 == 0)
                    {
                        cout << "This Item is Empty .\n" ;
                        break_fun();
                    }
                    break;
                }
                else                          /// if money == 5 and user need more than one product .
                {
                    cout << "\nYour Money is Not Enough .\n";
                    Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                    break;
                }

            }

        }
        else if (item_Choice_number == 2 && input_money < 6 )                          /// if money less than 6 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;
        }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }

/// ///////// Case Three . /////Case Three .///////////////Case Three ./////////////////Case Three .//////////////////Case Three .//////////////Case Three. //////////////
        if ( item_Choice_number == 3 ){
                    ifstream myfile ("Chocolate.txt",ios::in);
                    int counter = 0;
                    int array1[1];
                    if (myfile.is_open())
                    {
                        while (myfile >> array1[counter])
                        {
                            counter3 = array1[counter] ;
                            ++counter;
                        }
                    }

                if ( counter3 > 0 ){
        if ( item_Choice_number == 3 && input_money >= 15 )                             /// in case is  number of choice from list and the price input is >= 15 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 15)                              /// if choice number is 3 ( Pepsi Product ) and user need one input
            {
                cout << "\nChocolate Good Choice .\nYour Order Will Ready Now .\n";
                    /// File Part For Counter .
                    /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .
                    counter3 = counter3 - number_of_item ;
                    fstream file ("Chocolate.txt",ios::out);

                    if (file.is_open())
                    {
                        file << counter3 ;
                    }
                    if ( counter3 == 0)
                    {
                        cout << "This Item is Empty .\n" ;
                        break_fun();
                    }
                break;

//                Vending_Machine_Money();

            }
            else                          /// if money == 5 and user need more than one product .
            {
                cout << "\nYour Money is Not Enough .\n";
                Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                break;
            }


        }
        else if (item_Choice_number == 3 && input_money < 15 )                          /// if money less than 15 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;
        }
                }
                else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }

/// ///////// Case Four . /////Case Four .///////////////Case Four ./////////////////Case Four .//////////////////Case Four .//////////////Case Four. //////////////
        if ( item_Choice_number == 4 ){ ifstream myfile ("Ice_Cream.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter4 = array1[counter] ;
                                ++counter;
                            }
                        }

                if ( counter4 > 0 ){
        if ( item_Choice_number == 4 && input_money >= 10 )                             /// in case is  number of choice from list and the price input is >= 10 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 10)                              /// if choice number is 4 ( Pepsi Product ) and user need one input
            {
                cout << "\nIce Cream Good Choice .\nYour Order Will Ready Now .\n";
     /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        counter4 = counter4 - number_of_item ;
                        fstream file ("Ice_Cream.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter4 ;
                        }
                        if ( counter4 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                break;
//                Vending_Machine_Money();
            }
            if ( number_of_item > 1 )
            {
                if ( input_money == 20 ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                {
                    cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";
     /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        counter4 = counter4 - number_of_item ;
                        fstream file ("Ice_Cream.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter4 ;
                        }
                        if ( counter4 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                    break;
                }
                else                          /// if money == 5 and user need more than one product .
                {
                    cout << "\nYour Money is Not Enough .\n";
                    Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                    break;
                }


            }
        }
        else if (item_Choice_number == 4 && input_money < 10 )                          /// if money less than 10 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;
        }
        }
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }


/// ///////// Case Five . /////Case Five .///////////////Case Five ./////////////////Case Five .//////////////////Case Five .//////////////Case Five. //////////////
        if ( item_Choice_number == 5) {
                        ifstream myfile ("Branch.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter5 = array1[counter] ;
                                ++counter;
                            }
                        }

                if ( counter5 > 0 ){
        if ( item_Choice_number == 5 && input_money >= 4 )                             /// in case is  number of choice from list and the price input is >= 4 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 4)                              /// if choice number is 5 ( Pepsi Product ) and user need one input
            {
                cout << "\nBranch Good Choice .\nYour Order Will Ready Now .\n";
/// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .
                        counter5 = counter5 - number_of_item ;
                        fstream file ("Branch.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter5 ;
                        }
                        if ( counter5 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                break;
            }
            if ( number_of_item > 1 )
            {
                if ( input_money >= 8 ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                {
                    cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";

/// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        counter5 = counter5 - number_of_item ;
                        fstream file ("Branch.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter5 ;
                        }
                        if ( counter5 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                    break;
                }
                else                          /// if money == 5 and user need more than one product .
                {
                    cout << "\nYour Money is Not Enough .\n";
                    Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                    break;
                }

            }
        }
        else if (item_Choice_number == 5 && input_money < 4 )                          /// if money less than 4 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;

        }}
        else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }

/// ///////// Case Six . /////Case Six .///////////////Case Six ./////////////////Case Six .//////////////////Case Six .//////////////Case Six .//////////Case Six ./////////
    if ( item_Choice_number == 6 ){ ifstream myfile ("7_Up.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter6 = array1[counter] ;
                                ++counter;
                            }
                        }

            if ( counter6 > 0 ){
        if ( item_Choice_number == 6 && input_money >= 6 )                             /// in case is  number of choice from list and the price input is >= 6 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 6)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
            {
                cout << "\7 Up Good Choice .\nYour Order Will Ready Now .\n";
  /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        counter6 = counter6 - number_of_item ;
                        fstream file ("7_Up.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter6 ;
                        }
                        if ( counter6 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                break;
//                Vending_Machine_Money();
            }
            if ( number_of_item > 1 )
            {
                if ( input_money >= 12 ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                {
                    cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";

  /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .


                        counter6 = counter6 - number_of_item ;
                        fstream file ("7_Up.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter6 ;
                        }
                        if ( counter6 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                    break;
                }
                else                          /// if money == 5 and user need more than one product .
                {
                    cout << "\nYour Money is Not Enough .\n";
                    Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                    break;
                }


            }
        }
        else if (item_Choice_number == 6 && input_money < 6 )                          /// if money less than 6 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;
        }}else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
    }

/// ///////// Case Seven . /////Case Seven .///////////////Case Seven ./////////////////Case Seven .//////////////////Case Seven .//////////////Case Seven .///Case Seven .///
        if (item_Choice_number == 7 ){  ifstream myfile ("Bonbonne.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter7 = array1[counter] ;
                                ++counter;
                            }
                        }
                if ( counter7 > 0 ){
        if ( item_Choice_number == 7 && input_money >= 0.5)                             /// in case is  number of choice from list and the price input is >= 0.5 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 0.5)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
            {
                cout << "\nBonbonne Good Choice .\nYour Order Will Ready Now .\n";
                /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .


                        counter7 = counter7 - number_of_item ;
                        fstream file ("Bonbonne.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter7 ;
                        }
                        if ( counter7 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                break;
//                Vending_Machine_Money();
            }
            if ( number_of_item > 1 )
            {
                if ( input_money > 0.5 )           /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                {
                    cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";

/// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .


                        counter7 = counter7 - number_of_item ;
                        fstream file ("Bonbonne.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter7 ;
                        }
                        if ( counter7 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                    break;
                }
            }
        }
        else if (item_Choice_number == 7 && input_money < 0.5 )                          /// if money less than 0.5 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;
        }
                }else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
            }
/// ///////// Case Eight . ///Case Eight .//////////Case Eight .//////////Case Eight .//////////////////Case Eight .//////////////Case Eight .///Case Eight .///
        if ( item_Choice_number == 8){ifstream myfile ("Ciphsy.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter8 = array1[counter] ;
                                ++counter;
                            }
                        }
                if ( counter8 > 0 ){
        if ( item_Choice_number == 8 && input_money >= 20)                             /// in case is  number of choice from list and the price input is >= 20 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 20)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
            {
                cout << "\Ciphsy Good Choice .\nYour Order Will Ready Now .\n";
                 /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .


                        counter8 = counter8 - number_of_item ;
                        fstream file ("Ciphsy.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter8 ;
                        }
                        if ( counter8 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                break;
            }

        }
        else if (item_Choice_number == 8&& input_money < 20 )                          /// if money less than 20 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;

        }}else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }}

/// ///////// Case Nine . ///Case Nine .//////////Case Nine .//////////Case Nine .//////////////////Case Nine .//////////////Case Nine .///Case Nine .///
if ( item_Choice_number == 9 ){  ifstream myfile ("CocaCola.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter9 = array1[counter] ;
                                ++counter;
                            }
                        }

        if ( counter9 > 0 ){
        if ( item_Choice_number == 9 && input_money >= 7)                             /// in case is  number of choice from list and the price input is >= 7 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 7)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
            {
                cout << "\nCocaCola Good Choice .\nYour Order Will Ready Now .\n";
                 /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        counter9 = counter9 - number_of_item ;
                        fstream file ("CocaCola.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter9 ;
                        }
                        if ( counter9 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                break;
            }
            if ( number_of_item > 1 )
            {
                if ( input_money >= 14) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                {
                    cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";

 /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        counter9 = counter9 - number_of_item ;
                        fstream file ("CocaCola.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter9 ;
                        }
                        if ( counter9 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                    break;
                }
                else                          /// if money == 5 and user need more than one product .
                {
                    cout << "\nYour Money is Not Enough .\n";
                    Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
                    break;
                }


            }
        }
        else if (item_Choice_number == 9 && input_money < 7)                          /// if money less than 7 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;
        }}else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }}
/// ///////// Case Ten . ///Case Ten .//////////Case Ten .//////////Case Ten .//////////////////Case Ten .//////////////Case Ten .///Case Ten .///
if ( item_Choice_number == 10 ){
                        ifstream myfile ("Chocolate_Sweets.txt",ios::in);
                        int counter = 0;
                        int array1[1];
                        if (myfile.is_open())
                        {
                            while (myfile >> array1[counter])
                            {
                                counter10 = array1[counter] ;
                                ++counter;
                            }
                        }
        if ( counter10 > 0 ){
        if ( item_Choice_number == 10 && input_money >= 1)                             /// in case is  number of choice from list and the price input is >= 1 Bound
        {
            cout << "Enter Number You Need From This Item :";
            cin >> number_of_item;                                                       /// number of product

            if ( number_of_item == 1 && input_money >= 1)                              /// if choice number is 2 ( Pepsi Product ) and user need one input
            {
                cout << "\nChocolate Sweets Good Choice .\nYour Order Will Ready Now .\n";
                 /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .

                        counter10 = counter10 - number_of_item ;
                        fstream file ("Chocolate_Sweets.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter10 ;
                        }
                        if ( counter10 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }

                break;
//                Vending_Machine_Money();
            }
            if ( number_of_item > 1 )
            {
                if ( input_money > 1 ) /// if choice number is 1 ( Pepsi Product ) and user need more than one product .
                {
                    cout << "\nYour Order Will Ready Now "<< number_of_item <<" Items Of Pepsi .\n";

 /// File Part For Counter .
                        /// load item number from file from ifstream and them  i do equation counter1 -= number_Of_item and then i store the new counter1 in Pepsi file from ofstream .


                        counter10 = counter10 - number_of_item ;
                        fstream file ("Chocolate_Sweets.txt",ios::out);

                        if (file.is_open())
                        {
                            file << counter10 ;
                        }
                        if ( counter10 == 0)
                        {
                            cout << "This Item is Empty .\n" ;
                            break_fun();
                        }
                    break;
                }
            }
        }
        else if (item_Choice_number == 10 && input_money < 1)                          /// if money less than 1 bound .
        {
            cout << "Your Money Is Not Enough . << Sorry >> ";
            Vending_Machine_Money_repeat_input();                                 /// if user want to input anther money or End the program .
            break;
        }
        }else{
                cout << "This Item Is Not in Machine Please Select Anther Item if you want or 0 To End The Process ."<<endl;
                Vending_Machine_Anther_choice();
            }
        }
    }
}




/// /////////////////////////////////////////////////////////////////////////// /////////////////// /// ///////////

void Vending_Machine_Items::Vending_Machine_Money()
{
    while(item_Choice_number > 0)
    {
        /// The Remaining Money Case One .
        if ( item_Choice_number == 1 && input_money >= 5)
        {
            temp = input_money - (number_of_item * 5) ;                              /// number of item user need it * 5 Price Of Item .
            if (temp >= 0)                                                            /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                new_temp= temp;                                  /// to print the first new reminder in repeat or anther choose function
                break;
            }
            if (temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";
                break;
//                Vending_Machine_Money_repeat_input();

            }
        }


        /// The Remaining Money Case Two .
        if ( item_Choice_number == 2 && input_money >= 6)
        {
            temp = input_money - (number_of_item * 6) ;  /// 6 Price Of Item .
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                new_temp= temp;                                  /// to print the first new reminder in repeat or anther choose function

                break;
            }
            if (temp < 0 )
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >>\n";
                break;
            }
        }

        /// The Remaining Money Case Three .
        if ( item_Choice_number == 3 && input_money >= 15)
        {
            temp = input_money - (number_of_item * 15) ;  /// 15 Price Of Item .
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                new_temp= temp ;                                  /// to print the first new reminder in repeat or anther choose function
                break;
            }
            if(temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";
                break;
            }
        }

        /// The Remaining Money Case Four .
        if ( item_Choice_number == 4 && input_money >= 10)
        {
            temp = input_money - (number_of_item * 10) ;  /// 10 Price Of Item .
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                new_temp= temp ;                                  /// to print the first new reminder in repeat or anther choose function
                break;

            }
            if(temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";
                break;
            }
        }

        /// The Remaining Money Case Five .
        if ( item_Choice_number == 5 && input_money >= 4)
        {
            temp = input_money - (number_of_item * 4) ;  /// 4 Price Of Item .
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                new_temp= temp;                                  /// to print the first new reminder in repeat or anther choose function
                break;

            }
            if(temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";
                break;
            }
        }

        /// The Remaining Money Case Six .
        if ( item_Choice_number == 6 && input_money >= 6)
        {
            temp = input_money - (number_of_item * 6) ;  /// 6 Price Of Item .
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                new_temp= temp;                                  /// to print the first new reminder in repeat or anther choose function
                break;

            }
            if(temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";
                break;
            }
        }

        /// The Remaining Money Case Seven .
        if ( item_Choice_number == 7 && input_money >= 0.5)
        {
            temp = input_money - (number_of_item * 0.5);  /// 0.5 Price Of Item .
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                new_temp= temp ;                                  /// to print the first new reminder in repeat or anther choose function
                break;

            }
            if(temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";
                break;
            }
        }


        /// The Remaining Money Case Eight.
        if ( item_Choice_number == 8 && input_money >= 20)
        {
            temp = input_money - (number_of_item * 20) ;  /// 20 Price Of Item .
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                ///new_temp= temp - (number_of_item*20);                                  /// to print the first new reminder in repeat or anther choose function
                break;

            }
            if(temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";
                break;
            }
        }

        /// The Remaining Money Case Nine .
        if ( item_Choice_number == 9 && input_money >= 7)
        {
            temp = input_money - (number_of_item * 7) ;  /// 7 Price Of Item .
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                cout << "\nYour Remaining Money is : " << temp << endl;
                new_temp= temp ;                                  /// to print the first new reminder in repeat or anther choose function
                break;

            }
            if(temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";
                break;
            }
        }

        /// The Remaining Money Case Ten .
        if ( item_Choice_number == 10 && input_money >= 1)
        {
            if (temp >= 0)   /// If Remaining Money is Negative Program Will Damage .
            {
                temp = input_money - (number_of_item * 1) ;
                cout << "\nYour Remaining Money is temp : " << temp << endl;
                new_temp= temp ;                                  /// to print the first new reminder in repeat or anther choose function
                break;
            }
            if(temp < 0)
            {
                cout <<"You Don't Have any Money Left Over . << Thanks >> \n";

                break;
            }
        }

    }
}
