#include <iostream>
#include <string>
#include<cmath>
#include <algorithm>
using namespace std;
//  This function belongs to cipher number zero
int FindA(int a)
{
    for(int i=0; i<26; ++i)
    {
        if((i*a)%26==1) return i;
    }
}
//End of This function
int main()
{
    int cipher_number;
    cout <<"\t\t\t\t\t\t Ahlan ya user ya habibi. \n"<<"if you want Affine Cipher press 0 . \n"<<"if you want Caesar Cipher press 1 . \n";
    cout <<"if you want Atbash Cipher press 2 . \n"<<"if you want ROT13 Cipher press 3 . \n"<<"if you want Baconian Cipher  press 4 . \n";
    cout <<"if you want Simple Substitution Cipher press 5 . \n"<<"if you want Polybius Square Cipher press 6 . \n"<<"if you want Morse Cipher press 7 . \n";
    cout <<"if you want XOR Cipher  press 8 . \n"<<"if you want Rail-fence Cipher press 9 . \n"<<"To End press any key but not this numbers . \n";
    cout << "\n\nEnter your cipher number please :";
    cin >> cipher_number ;
    if (cipher_number == 0 )
    {
        while(true)
        {
            string input, encryption, decryption;
            int x,y,a,b;
            cout<<"Ahlan ya user ya habibi. \n What do you like to do today? \n1- Cipher a message \n2- Decipher a message \n3- End \n";
            cin>>x;

            switch(x)
            {
            case 1:
                cout<< "please enter the decipher keys a and b for the letter to be deciphered in (ax+b)%26"<<'\n';
                cin>>a>>b;
                while (a<0 && b<0)
                {
                    cout<<"a & b must be > 0 please re-enter them : ";
                    cin>> a>>b;
                }
                cout<<"Please enter the message : \n";
                cin.ignore();
                getline(cin,input);
                for (int i=0; i<(int)input.length(); ++i)
                {
                    if((int)input[i]==32)
                    {
                        encryption += " ";
                        continue;
                    }
                    else if((int)input[i]<=90 && (int)input[i]>=65)
                    {
                        y = input[i]-'A';
                        encryption +=(char)((a*y+b)%26 +'A');
                    }
                    else if ((int)input[i]<=122 && (int)input[i]>=97)
                    {
                        y = input[i]-'a';
                        encryption +=(char)((a*y+b)%26 +'a');
                    }
                    else
                    {
                        encryption += input[i];
                    }
                }
                cout<<"Your encrypted message is "<<'"'<<encryption<<'"'<<'\n';
                break;

            case 2:
                cout<< "please enter the cipher keys a,b and c for the letter to be ciphered in a(x-b)%c"<<'\n';
                cin>>a>>b;
                while (a<0 && b<0)
                {
                    cout<<"a & b must be > 0 please re-enter them : ";
                    cin>> a>>b;
                }
                a = FindA(a);
                cout << a<<'\n';
                cout<<"Please enter the message : \n";
                cin.ignore();
                getline(cin,input);
                for (int i=0; i<(int)input.length(); ++i)
                {
                    if((int)input[i]==32)
                    {
                        decryption += " ";
                        continue;
                    }
                    else if((int)input[i]<=90 && (int)input[i]>=65)
                    {
                        y = input[i]-'A';
                        y = (a*(y-b))%26;
                        (y<0)? y+=26:y;
                        decryption += (char)( y + 65);
                    }
                    else if ((int)input[i]<=122 && (int)input[i]>=97)
                    {
                        y = input[i]-'a';
                        y = (a*(y-b))%26; //insxchmrwbglqvafkpuzejotyd
                        (y<0)? y+=26:y;
                        decryption += (char)( y + 97);
                    }
                    else
                    {
                        decryption += input[i];
                    }
                }
                cout<<"Your decrypted message is "<<'"'<<decryption<<'"'<<'\n';
                break;
            case 3:
                return 0;
            default :
                cout<<"Invalid Input"<<endl;
                main();
            }
        }

    }
    else if (cipher_number == 1)
    {
        while (true)
        {
            string array = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

            cout << "hello my dear user ! \n"<<"what do you like to do today ? \n";
            cout <<"1-cipher text \n"<<"2-decipher text \n"<<"3-End "<<endl;

            int q = 0;
            cin >> q ;
            if (q == 1)
            {
                cout << "what is the number of shifts you want ? (maximum 25 shifts)  "<<endl;
                int x ;
                cin >> x ;
                while (x>25 || x<0)
                {

                    cout<<"error ! "<<endl;
                    cout << "what is the number of shifts you want ? (maximum 25 shifts)  "<<endl;
                    int x ;
                    cin >> x ;

                }
                cin.ignore();
                string message ;
                cout <<"enter the text you wanna cipher "<<endl;
                getline(cin,message);
                int (y) = 0 ;
                int i = 0 ;
                int c ;
                while (i<53 )
                {
                    c=(int)message[y];
                    if (int(message[y])==32)
                    {
                        y++;
                        i=0;
                    }
                    else if (c <65 || (c <96 && c >90) ||c >122)
                    {
                        y++;
                        i=0;
                    }
                    else if (message[y]== array[i] )
                    {

                        if (((i+x)>25)&& i<26)
                        {
                            message[y]=array[(i+x)-26];
                            i=0;
                            y+=1;
                        }
                        else if (((i+x)<=25)&& i<26)
                        {
                            message[y]=array[i+x];
                            y+=1;
                            i=0;
                        }
                        else if(((i+x)>52)&& i>=26)
                        {
                            message[y]=array[(i+x)-26];
                            i=0;
                            y+=1;
                        }
                        else if (((i+x)<=52)&& i>=26)
                        {
                            message[y]=array[i+x];
                            y+=1;
                            i=0;

                        }
                    }
                    else

                    {
                        i++;
                    }

                }
                cout << message <<endl<<endl;

            }
            else if (q==2)
            {
                cout << "what is the number of shifts you did ? (maximum 25 shifts) "<<endl;
                int x ;
                cin >> x ;
                while (x>25 || x<0)
                {

                    cout<<"error ! "<<endl;
                    cout << "what is the number of shifts you did ? (maximum 25 shifts)  "<<endl;
                    int x ;
                    cin >> x ;
                }
                cin.ignore();
                string message ;
                cout <<"enter the text you wanna decipher "<<endl;
                getline(cin,message);
                int (y) = 0 ;
                int i = 0 ;
                int c ;
                while (i<53)
                {
                    c= (int)message[y];
                    if (c <65 || (c <96 && c >90) ||c >122)
                    {
                        y++;
                        i=0;

                    }
                    else if (int(message[y])==32)
                    {
                        y++;
                        i=0;

                    }
                    else if (message[y]== array[i])
                    {
                        if ((i-x)>=0 && i < 26)
                        {
                            message[y]=array[(i-x)];
                            i=0;
                            y+=1;
                        }
                        else if ((i-x)<0 && i < 26)
                        {
                            message[y]=array[26+(i-x)];
                            y+=1;
                            i=0;
                        }
                        else if ((i-x)<26 && i >= 26)
                        {
                            message[y]=array[26+(i-x)];
                            y+=1;
                            i=0;
                        }
                        else if ((i-x)>=26 && i >= 26)
                        {
                            message[y]=array[(i-x)];
                            i=0;
                            y+=1;

                        }
                    }
                    else
                    {
                        i++;
                    }

                }

                cout << message <<endl<<endl;
            }
            else if (q==3)
            {
                break;
            }
            else
            {
                cout<<"ERROR"<<endl;

            }

        }

    }
    else if (cipher_number == 2)
    {

        while (true)
        {
            string array = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            cout << "hello my dear user ! \n"<<"what do you like to do today ? \n";
            cout <<"1-cipher text \n"<<"2-decipher text \n"<<"3-End "<<endl;

            int q = 0;
            cin >> q ;
            if (q == 1)
            {

                cin.ignore();
                string message ;
                cout <<"enter the text you wanna cipher "<<endl;
                getline(cin,message);
                int (y) = 0 ;
                int i = 0 ;
                int c ;
                while (i<53 )
                {
                    if (message[y]== array[i] )
                    {
                        if (i<26)
                        {
                            message[y]=array[25-i];
                            i=0;
                            y++;
                        }
                        else
                        {
                            message[y]=array[25+(52-i)];
                            i=0;
                            y++;
                        }
                    }
                    else if ((int)message[y] ==32)
                    {
                        y++;
                        i=0;
                    }
                    else

                    {
                        i++;
                    }

                }
                cout << message <<endl<<endl;

            }
            else if (q==2)
            {

                cin.ignore();
                string message ;
                cout <<"enter the text you wanna decipher "<<endl;
                getline(cin,message);
                int (y) = 0 ;
                int i = 0 ;
                int c ;
                while (i<53)
                {
                    if (message[y]== array[i])
                    {
                        if (i<26)
                        {
                            message[y]=array[25-i];
                            i=0;
                            y++;
                        }
                        else
                        {
                            message[y]=array[25+(52-i)];
                            i=0;
                            y++;
                        }
                    }
                    else if (int(message[y])==32)
                    {
                        y++;
                        i=0;

                    }
                    else
                    {
                        i++;
                    }

                }

                cout << message <<endl<<endl;
            }
            else if (q==3)
            {
                break;
            }
            else
            {
                cout<<"ERROR"<<endl;

            }

        }
    }
        else if (cipher_number == 3)
        {
            while (true)
    {
        string array = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        cout << "hello my dear user ! \n"<<"what do you like to do today ? \n";
        cout <<"1-cipher text \n"<<"2-decipher text \n"<<"3-End "<<endl;

        int q = 0;
        cin >> q ;
        if (q == 1)
        {

            cin.ignore();
            string message ;
            cout <<"enter the text you wanna cipher "<<endl;
            getline(cin,message);
            int (y) = 0 ;
            int i = 0 ;
            int c ;
            while (i<53 )
            {
            if ((int)message[y] ==32)
                {
                    y++;
                    i=0;
                }
                else if (message[y]== array[i] )
                {
                    if (i<13 || (i>=26 && i<39)){
                        message[y]=array[13+i];
                        i=0;
                        y++;
                    }else if (i>=13 && i<26) {
                        message[y]=array[13-(26-i)];
                        i=0;
                        y++;
                    }else if (i>=39){
                        message[y]=array[39-(52-i)];
                        i=0;
                        y++;
                    }
                }
                else

                {
                    i++;
                }

            }cout << message <<endl<<endl;

        }
        else if (q==2)
        {

            cin.ignore();
            string message ;
            cout <<"enter the text you wanna decipher "<<endl;
            getline(cin,message);
            int (y) = 0 ;
            int i = 0 ;
            int c ;
            while (i<53)
            {
            if (int(message[y])==32)
                {
                    y++;
                    i=0;

                } else if (message[y]== array[i] )
                {
                    if (i<13 || (i>=26 && i<39)){
                        message[y]=array[13+i];
                        i=0;
                        y++;
                    }else if (i>=13 && i<26) {
                        message[y]=array[13-(26-i)];
                        i=0;
                        y++;
                    }else if (i>=39){
                        message[y]=array[39-(52-i)];
                        i=0;
                        y++;
                    }
                }
                else
                {
                    i++;
                }

            }

            cout << message <<endl<<endl;
        }
        else if (q==3)
        {
            break;
        }
        else
        {
            cout<<"ERROR"<<endl;

        }

}



        }
        else if (cipher_number == 4)
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


        }
        else if (cipher_number == 5)
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
                string choise;
                cout << "if you want the zebra cipher press any word but this word include 5 char \n ";
                cout << "if you want the cairo cipher press cairo word \n";
                cout <<"Enter your choise here : ";
                cin >> choise ;
                if (choise != "cairo")
                {
                    cout <<"you in zebra cipher ";
                    string name ;
                    cout <<"Please enter the message to cipher: " ;
                    cin.ignore();
                    getline(cin, name);
                    string  arrayofchar = "abcdefghijklmnopqrstuvwxyz.,";
                    char arrayofcipher [] = {'z','e','b','r','a','c','d','f','g','h','i','j','k','l','m','n','o','p','q','s','t','u','v','w','x','y','z'};
                    for (int  i = 0 ; i < name.length() ; i++)
                    {
                        for (int j=0 ; j< 29; j++)
                        {
                            if (name[i] == arrayofchar[j])
                            {
                                cout << arrayofcipher[j];
                            }
                            if (name[i] == ' ')
                            {
                                cout <<" ";
                                break;
                            }

                        }
                    }
                }
                else if ( choise == "cairo" )
                {
                    cout <<"you in cairo cipher ";
                    string name ;
                    cout <<"Please enter the message to cipher: " ;
                    cin.ignore();
                    getline(cin, name);
                    string  arrayofchar = "abcdefghijklmnopqrstuvwxyz";
                    char arrayofcipher [] = {'c','a','i','r','o','b','d','e','f','g','h','j','k','l','m','n','p','q','s','t','u','v','w','x','y','z'};
                    for (int  i = 0 ; i < name.length() ; i++)
                    {
                        for (int j=0 ; j< 29; j++)
                        {
                            if (name[i] == arrayofchar[j])
                            {
                                cout << arrayofcipher[j];
                            }
                            if (name[i] == ' ')
                            {
                                cout <<" ";
                                break;
                            }

                        }
                    }
                }
            }

            else if (choosenumber == 2)
            {
                string choise;
                cout << "if you want the zebra cipher press any word but this word include 5 char \n ";
                cout << "if you want the cairo cipher press cairo word \n";
                cout <<"Enter your choise here : ";
                cin >> choise ;
                if (choise != "cairo" )
                {
                    cout <<"you in zebra cipher ";
                    string name ;
                    cout <<"Please enter your message : " ;
                    cin.ignore();
                    getline(cin, name);
                    string  arrayofchar = "abcdefghijklmnopqrstuvwxyz";
                    char arrayofcipher [] = {'z','e','b','r','a','c','d','f','g','h','i','j','k','l','m','n','o','p','q','s','t','u','v','w','x','y','z'};
                    for (int  i = 0 ; i < name.length() ; i++)
                    {
                        for (int j=0 ; j< 29; j++)
                        {
                            if (name[i] == arrayofcipher[j])
                            {
                                cout << arrayofchar[j];
                            }
                            if (name[i] == ' ')
                            {
                                cout <<" ";
                                break;
                            }

                        }
                    }
                }
                else if ( choise == "cairo" )
                {
                    cout <<"you in cairo cipher ";
                    string name ;
                    cout <<"Please enter the message to cipher: " ;
                    cin.ignore();
                    getline(cin, name);
                    string  arrayofchar = "abcdefghijklmnopqrstuvwxyz";
                    char arrayofcipher [] = {'c','a','i','r','o','b','d','e','f','g','h','j','k','l','m','n','p','q','s','t','u','v','w','x','y','z'};
                    for (int  i = 0 ; i < name.length() ; i++)
                    {
                        for (int j=0 ; j< 29; j++)
                        {
                            if (name[i] == arrayofcipher[j])
                            {
                                cout << arrayofchar[j];
                            }
                            if (name[i] == ' ')
                            {
                                cout <<" ";
                                break;
                            }

                        }
                    }
                }


            }


        }
        else if (cipher_number == 6)
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

        }
        else if (cipher_number == 7)
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
                string Morse[52] = {".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ",".-- ","-..- ","-.-- ","--.. ",".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ",".-- ","-..- ","-.-- ","--.. "};
                for (int  i = 0 ; i < message.length() ; i++)
                {
                    for (int j=0 ; j< 29; j++)
                    {
                        if (message[i] == alphabet[j])
                        {
                            cout << Morse[j];
                        }
                        if (message[i] == ' ')
                        {
                            cout <<"   ";
                            break;
                        }

                    }
                }
            }
            else if (choosenumber == 2)
            {
                string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                string Morse[52] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
                string decryption;
                cin.ignore();
                string message ;
                cout <<"Enter your cipher (for example, ... --- ...  ... --- ...) :  "<<endl;
                getline(cin,message);
                string letter;
                for(int i=0; i< message.length(); i++)
                {
                    while (/*(int)*/message[i]!=32)
                    {

                        letter+=message[i];
                        i++;
                    }
                    for(int j=0 ; j<26; ++j)
                    {
                        if(letter == Morse[j])
                        {
                            decryption += alphabet[j];
                            letter="";
                        }
                    }
                    if (/*(int)*/message[i]==32)
                    {
                        if (/*(int)*/(message[i+1]==32 && message[i+2] == 32)||(message[i+1]==32))
                        {
                            decryption+=" ";
                        }
                    }


                }
                cout<<decryption;


            }


        }
        else if (cipher_number == 8)
        {
            cout  << "COMING SOON USER";
            // Coming soon

        }
        else if (cipher_number == 9)
        {
            while (true)
            {

                cout<<"hello my dear user ! what do you wanna do today ? "<<endl<<"enter 1 to cipher ,2 to decipher ,3 to end ! "<<endl;
                int q ;
                cin >> q;
                if (q==1)
                {
                    cout <<"enter your key (must be more than one ) ! "<<endl;
                    int key, len ;
                    cin >> key ;
                    while (key < 2)
                    {
                        cout <<"enter your key (must be more than one ) ! "<<endl;
                        cin >> key ;
                    }
                    cout <<"enter the text you wanna encrypt ! "<<endl;
                    string str,encryption;
                    cin.ignore();
                    getline(cin,str);
                    len = str.length();
                    for(int i=0; i<str.length(); ++i)
                        if(str[i] == ' ') str.erase(i,1);
                    len = str.length();
                    string arr[key][len];
                    for (int row=0; row < key; ++row)
                    {
                        for(int column=0; column < len; ++column)
                        {
                            arr[row][column]='-';
                        }
                    }

                    int row =0,column=0;
                    while (column < len)
                    {
                        while (row<key)
                        {
                            if (column==len) break;
                            arr[row][column]=str[column];
                            row++;
                            column++;

                        }
                        row-=2;
                        while (row>0)
                        {
                            if (column==len) break;
                            arr[row][column]=str[column];
                            row--;
                            column++;
                        }

                        if (column==len) break;
                    }
                    for (int row=0; row < key; ++row)
                    {
                        for(int column=0; column < len; column++)
                        {
                            cout<<arr[row][column];
                        }
                        cout<<endl;
                    }

                    for (int row=0; row < key; ++row)
                    {
                        for(int column=0; column < len; column++)
                        {
                            if (arr[row][column]!="-")encryption+=arr[row][column];
                        }
                    }
                    cout<<encryption<<endl<<endl<<endl;
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
                }
                else if (q==2)
                {
                    cout <<"enter your key (must be more than one ) ! "<<endl;
                    int key, len ;
                    cin >> key ;
                    while (key < 2)
                    {
                        cout <<"enter your key (must be more than one ) ! "<<endl;
                        cin >> key ;
                    }
                    cout <<"enter the text you wanna decrypt ! "<<endl;
                    string str,decryption,input;
                    cin.ignore();
                    getline(cin,str);
                    input=str;
                    len = str.length();
                    for(int i=0; i<str.length(); ++i)
                        if(str[i] == ' ') str.erase(i,1);
                    len = str.length();
                    string arr[key][len];

                    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


                    while (true)
                    {

                        for (int row=0; row < key; ++row)
                        {
                            for(int column=0; column < len; ++column)
                            {
                                arr[row][column]='-';
                            }
                        }

                        int row =0,column=0;

                        //fill the array with the input string

                        while (column < len)
                        {
                            while (row<key)
                            {
                                if (column==len) break;
                                arr[row][column]=str[column];
                                row++;
                                column++;

                            }
                            row-=2;
                            while (row>0)
                            {
                                if (column==len) break;
                                arr[row][column]=str[column];
                                row--;
                                column++;
                            }

                            if (column==len) break;
                        }

                        //loop to collect letters of encryption

                        for (int row=0; row < key; ++row)
                        {
                            for(int column=0; column < len; column++)
                            {
                                if (arr[row][column]!="-")decryption+=arr[row][column];

                            }
                        }
                        if (decryption==input)break;
                        str=decryption;
                        decryption="";

                    }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                    //loop to print the array


                    cout <<str<<endl;
                }

            }

        }










        return 0;
    }
