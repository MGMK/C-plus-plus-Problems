#include <iostream>
#include <string>

using namespace std;

int main()

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


    return 0;

}
