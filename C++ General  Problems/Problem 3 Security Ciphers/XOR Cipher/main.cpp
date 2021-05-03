#include <iostream>
#include <string>

using namespace std;

int main()
{
    while (true)
    {
        cout << "hello my dear user ! \n"<<"what do you like to do today ? \n";
        cout <<"1-cipher text \n"<<"2-decipher text \n"<<"3-End "<<endl;

        int q = 0;
        cin >> q ;
        if (q==1 || q==2)
        {
            cin.ignore();
            string encryption;
            string text;
            char input;
            cout <<"enter the text "<<endl;
            cin.ignore();
            getline(cin,text);
            cout<<"enter the secret letter ! "<<endl;
            cin>>input;
            for (int i=0; i<text.length(); i++)
            {
                    encryption+=(char)((int)text[i]^(int)input);
               }
        cout <<encryption<<endl;


        }else if (q==3){
        break;
        }else {
        cout<<"error! "<<endl;
        int main();
        }
    }

    return 0;
}
