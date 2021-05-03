#include <iostream>
#include <string>
using namespace std ;
int main ()
{


    cout <<"Ahlan ya user ua habibi. \n";
    int choosenumber ;
    cout <<"What do you like to do today? \n";
    cout <<"1- Cipher a message  \n "<<"2- Decipher a message \n"<<"3- End \n";
    cin >> choosenumber ;
    if (choosenumber == 1 )
    {
        int choise;
        cout << "if you want the 1 2 3 4 5 cipher press 1 \n ";
        cout << "if you want 5 4 3 2 1 cipher press 2  \n";
        cout <<"Enter your choise here : ";
        cin >> choise ;
        if (choise == 1)
        {
            cout <<"you in 1 2 3 4 5  cipher ";
            string massage ;
            cout <<"Please enter your message : " ;
            cin.ignore();
            getline(cin, massage);
            string  arrayofchar = "abcdefghijklmnopqrstuvxyz";
            string  arrayofcipher[26] = {"11","12","13","14","15","21","22","23","24","25","31","32","33","34","35","41","42","43","44","45","51","52","53","54","55"};
            for (int  i = 0 ; i < massage.length() ; i++)
            {
                for (int j=0 ; j < 27; j++)
                {
                    if (massage[i] == arrayofchar[j])
                    {
                        cout << arrayofcipher[j];
                    }
                    if (massage[i] == ' ')
                    {
                        cout <<"      ";
                        break;
                    }

                }
            }
        }
        else if (choise == 2 )
        {
            cout <<"you in 5 4 3 2 1 cipher ";
            string massage ;
            cout <<"Please enter your message : " ;
            cin.ignore();
            getline(cin, massage);
            string  arrayofchar = "abcdefghijklmnopqrstuvxyz";
            string  arrayofcipher[26] = {"55","51","54","52","53","15","11","14","12","13","45","41","44","42","43","25","21","24","22","23","35","31","34","32","33"};
            for (int  i = 0 ; i < massage.size() ; i++)
            {
                for (int j=0 ; j < 27; j++)
                {
                 if (massage[i] == arrayofchar[j])
                    {
                        cout << arrayofcipher[j];
                    }
                 if (massage[i] == ' ')
                    {
                        cout <<"      ";
                        break;
                    }

                }
            }
        }
    }




    else if (choosenumber == 2)
    {

        int choise;
        cout << "if you want the 1 2 3 4 5 Decipher press 1 \n ";
        cout << "if you want 5 4 3 2 1 Decipher press 2  \n";
        cout <<"Enter your choise here : ";
        cin >> choise ;
        if (choise == 1)
        {

        string cipher[800] ;
        cout << "before you enter your code follow this exzmple \n(input :11 11 11 , 11 11 11 ) \n\t(output :aaa aaa) \n";

        cout <<"Enter your cipher : ";
        for ( int i = 0 ; i < 1000 ; i++)
        {
            cin>>cipher[i];
            if (cipher[i] == "11")
            cout << "a";
            else if (cipher[i] =="12" )
                cout << "b";
            else if (cipher[i] == "13")
                cout <<"c";
             else if (cipher[i] == "14" )
                cout << "d";
            else if (cipher[i] == "15" )
                cout << "e";
            else if (cipher[i] == "21")
                cout <<"f";
            else if (cipher[i] == "22")
                cout <<"g";
            else if (cipher[i] == "23" )
                cout << "h";
            else if (cipher[i] == "24")
                cout <<"i";
             else if (cipher[i] == "25" )
                cout << "j";
            else if (cipher[i] == "31" )
                cout << "k";
            else if (cipher[i] == "32")
                cout <<"l";
            else if (cipher[i] == "33")
                cout <<"m";
            else if (cipher[i] == "34" )
                cout << "n";
            else if (cipher[i] == "35")
                cout <<"o";
            else if (cipher[i] == "41" )
                cout << "p";
            else if (cipher[i] == "42" )
                cout << "q";
            else if (cipher[i] == "43")
                cout <<"r";
            else if (cipher[i] == "44")
                cout <<"s";
            else if (cipher[i] == "45" )
                cout << "t";
            else if (cipher[i] == "51")
                cout <<"u";
             else if (cipher[i] == "52" )
                cout << "v";
            else if (cipher[i] == "53")
                cout <<"x";
            else if (cipher[i] == "54")
                cout <<"y";
            else if (cipher[i] == "55")
                    cout << "z";
            else if (cipher[i]== ",")
                        cout <<"   ";
        }
        }
        else if (choise == 2 )
        {

            cout <<"you in 5 4 3 2 1 cipher ";
            string massage ;
            cout <<"Please enter your message : " ;
        string cipher[800] ;
        cout << "before you enter your code follow this exzmple \n(input :55 55 55 , 55 55 55 ) \n\t(output :aaa aaa) \n";

        cout <<"Enter your cipher : ";
        for ( int i = 0 ; i < 1000 ; i++)
           {

            cin>>cipher[i];
            if (cipher[i] == "55")
            cout << "a";
            else if (cipher[i] =="51" )
                cout << "b";
            else if (cipher[i] == "54")
                cout <<"c";
             else if (cipher[i] == "52" )
                cout << "d";
            else if (cipher[i] == "53" )
                cout << "e";
            else if (cipher[i] == "15")
                cout <<"f";
            else if (cipher[i] == "11")
                cout <<"g";
            else if (cipher[i] == "14" )
                cout << "h";
            else if (cipher[i] == "12")
                cout <<"i";
             else if (cipher[i] == "13" )
                cout << "j";
            else if (cipher[i] == "45" )
                cout << "k";
            else if (cipher[i] == "41")
                cout <<"l";
            else if (cipher[i] == "44")
                cout <<"m";
            else if (cipher[i] == "42" )
                cout << "n";
            else if (cipher[i] == "43")
                cout <<"o";
            else if (cipher[i] == "25" )
                cout << "p";
            else if (cipher[i] == "21" )
                cout << "q";
            else if (cipher[i] == "24")
                cout <<"r";
            else if (cipher[i] == "22")
                cout <<"s";
            else if (cipher[i] == "23" )
                cout << "t";
            else if (cipher[i] == "35")
                cout <<"u";
             else if (cipher[i] == "31" )
                cout << "v";
            else if (cipher[i] == "34")

                cout <<"x";
            else if (cipher[i] == "32")
                cout <<"y";
            else if (cipher[i] == "33")
                    cout << "z";
            else if (cipher[i]== ",")
                        cout <<"   ";
        }
    }
    }
    return 0;


}

