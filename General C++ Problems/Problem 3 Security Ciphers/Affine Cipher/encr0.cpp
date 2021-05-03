#include <iostream>
#include <string>


using namespace std;
int FindA(int a)
{
    for(int i=0; i<26; ++i)
    {
        if((i*a)%26==1) return i;
    }
}

int main()
{
    while(true)
    {
        string input, encryption, decryption;
        int x,y,a,b;
        cout<<"Ahlan ya user ya habibi XD. What do you like to do today? \n1- Cipher a message \n2- Decipher a message \n3- End \n";
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
    return 0;
}
