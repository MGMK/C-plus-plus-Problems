#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int main()
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


            while (true){

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






    return 0;
}
