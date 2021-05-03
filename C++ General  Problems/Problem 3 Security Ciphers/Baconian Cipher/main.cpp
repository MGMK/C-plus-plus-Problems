#include <iostream>

using namespace std;

/*int pow(int base , int power)
{
    int res=1;
    for(int i=0; i<power ; i++ )
    {
        res=res*base;
    }
    return res;
}*/
int main()
{
    cout <<"Ahlan ya user ua habibi. \n";
    int choosenumber ;
    cout <<"What do you like to do today? \n";
    cout <<"1- Cipher a message \n";
    cout <<"2- Decipher a message \n";
    cout <<"3- End \n";
    cin >> choosenumber ;
    if (choosenumber == 1 )
    {
        string message ;
        cout <<"Please enter the message to cipher: " ;
        cin.ignore();
        getline(cin, message);
        string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string cipher[54] = {"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab","aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"};
        for (int  i = 0 ; i < message.length() ; i++)
        {
            for (int j=0 ; j< 54; j++)
            {
                if (message[i] == alphabet[j])
                {
                    cout << cipher[j];
                }
                if (message[i] == ' ')
                {
                    cout <<" ";
                    break;
                }

            }
        }
    }
else if (choosenumber == 2 )
{
        string cipher [800];
        cout << "before you enter your code follow this example \n(input :aaaaa aaaaa aaaaa , aaaaa aaaaa aaaaa ) \n\t(output :AAA AAA) \n";
        cout<<"Please enter the message to decipher : ";
        for (int i = 0 ; i < 1000 ;  i++)
        {
            cin>>cipher[i];
            if (cipher[i] == "aaaaa")
                cout << "A";
            else if (cipher[i] == "," )
                cout << "  ";             // 2 _space if the user Enter the ,
            else if (cipher[i] == "aaaab" )
                cout << "B";
            else if (cipher[i] == "aaaba")
                cout <<"C";
             else if (cipher[i] == "aaabb" )
                cout << "D";
            else if (cipher[i] == "aabaa" )
                cout << "E";
            else if (cipher[i] == "aabab")
                cout <<"F";
            else if (cipher[i] == "aabba")
                cout <<"G";
            else if (cipher[i] == "aabbb" )
                cout << "H";
            else if (cipher[i] == "abaaa")
                cout <<"I";
             else if (cipher[i] == "abaab" )
                cout << "J";
            else if (cipher[i] == "ababa" )
                cout << "K";
            else if (cipher[i] == "ababb")
                cout <<"L";
            else if (cipher[i] == "abbaa")
                cout <<"M";
            else if (cipher[i] == "abbab" )
                cout << "N";
            else if (cipher[i] == "abbba")
                cout <<"O";
            else if (cipher[i] == "abbbb" )
                cout << "P";
            else if (cipher[i] == "baaaa" )
                cout << "Q";
            else if (cipher[i] == "baaab")
                cout <<"R";
            else if (cipher[i] == "baaba")
                cout <<"S";
            else if (cipher[i] == "baabb" )
                cout << "T";
            else if (cipher[i] == "babaa")
                cout <<"U";
             else if (cipher[i] == "babab" )
                cout << "V";
            else if (cipher[i] == "babba" )
                cout << "W";
            else if (cipher[i] == "babbb")
                cout <<"X";
            else if (cipher[i] == "bbaaa")
                cout <<"Y";
            else if (cipher[i] == "bbaab")
                cout << "Z";

        }

}
    return 0;
}
