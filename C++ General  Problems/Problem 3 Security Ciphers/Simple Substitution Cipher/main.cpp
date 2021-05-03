#include <iostream>
#include <string>
using namespace std ;
int main ()
{


    cout <<"Ahlan ya user ua habibi. \n";
    string choosenumber ;
    cout <<"What do you like to do today? \n";
    cout <<"1- Cipher a message \n";
    cout <<"2- Decipher a message \n";
    cout <<"3- End \n";
    cin >> choosenumber ;
        if (choosenumber == "1")
		{

        string name;
        string arrayofchar_1="abcdefghijklmnopqrstuvwxyz";
        char arrayOfletters[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        string key, arr[26];
        cout<<"Enter Your Key : ";
        cin>>key;
        cout<<"Please Enter The Message To Cipher : ";
        cin.ignore();
        getline(cin,name);
        int number=0;
        for(int i=0; i<5 ; i++)   // loop for key char in empty array (arr)
        {
            arr[i]=key[i];
        }
        for(int s=0 ; s<5 ; s++)   // loop for key
        {
            for(int j=0; j<26 ; j++)   // loop for array
            {
                if(key[s]==arrayOfletters[j])
                {
                    arrayOfletters[j]='#';
                }
            }
        }
        for(int i=5; i<26 ; i++)  // loop to compare the key char with arrayofletter char
        {
            if(arrayOfletters[number]!='#')
                arr[i]=arrayOfletters[number];
            else
                i--;
            number++;
        }
        for(int i=0 ; i<name.size() ; i++)  // loop on the input
        {
            for(int j=0 ; j<26 ; j++)  // loop in arrayofletter
            {
                if(name[i]==arrayofchar_1[j])
                {
                    cout<<arr[j]; // print the cipher chars this's found in empty array
                }
            }
            if (name[i]==' ')
            {
                cout<<" ";
            }
        }



	}
if (choosenumber == "2")
		{
        string name;
        string arrayofchar_1="abcdefghijklmnopqrstuvwxyz";
        char arrayOfletters[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        string key;
        char arr[26];
        cout<<"Enter Your key : ";
        cin>>key;
        cout<<"please enter the cipher to decipher : ";
        cin.ignore();
        getline(cin,name);
        int number=0;
        for(int i=0; i<5 ; i++)     // loop for key char in empty array (arr)
        {
            arr[i]=key[i];
        }
        for(int s=0 ; s<5 ; s++)    // loop for key
        {
            for(int j=0; j<26 ; j++)     // loop for array
            {
                if(key[s]==arrayOfletters[j])
                {
                    arrayOfletters[j]='#';
                }
            }
        }
        for(int i=5; i<26 ; i++)
        {
            if(arrayOfletters[number]!='#')
                arr[i]=arrayOfletters[number];
            else
                i--;
            number++;
        }
        for(int i=0 ; i<name.size() ; i++)  // loop on the input
        {
            for(int j=0; j<26 ; j++)    // loop in arrayofletter
            {
                if (arr[j]==name[i])
                {
                    cout<<arrayofchar_1[j];     // print the cipher chars this's found in array of letter
                }
            }
            if(name[i]==' ')
            {
                cout<<" ";
            }
        }


	}






    return 0 ;
}
