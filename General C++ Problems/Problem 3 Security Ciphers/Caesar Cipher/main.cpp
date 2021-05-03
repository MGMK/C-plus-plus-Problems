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
                }else if (c <65 || (c <96 && c >90) ||c >122)
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
                    else if (((i+x)<=25)&& i<26){
                        message[y]=array[i+x];
                        y+=1;
                        i=0;
                    }else if(((i+x)>52)&& i>=26){
                        message[y]=array[(i+x)-26];
                        i=0;
                        y+=1;
                    }else if (((i+x)<=52)&& i>=26)
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

            }cout << message <<endl<<endl;

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

                }else if (int(message[y])==32)
                {
                    y++;
                    i=0;

                } else if (message[y]== array[i])
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
                    }else if ((i-x)<26 && i >= 26){
                        message[y]=array[26+(i-x)];
                        y+=1;
                        i=0;
                }else if ((i-x)>=26 && i >= 26){
                    message[y]=array[(i-x)];
                        i=0;
                        y+=1;

                }}
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
