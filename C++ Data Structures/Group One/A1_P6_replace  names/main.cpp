#include <bits/stdc++.h>
using namespace std;

class StudenName
{
public:
    StudenName()
    {
        name="";
    }
    StudenName(string n):name(n)
    {
        int Size=name.length();
        char arr[Size+1];
        strcpy(arr,name.c_str());
        fixname(spaceCount(name),arr,Size);
    }
    int spaceCount(string x)
    {
        int spaces=0;
        for(int i=0; i<x.length(); i++)
        {
            if(x[i]==' ')
                spaces++;
        }
        return spaces;
    }
/// ///////////////////////////////////////////////
    void fixname(int space,char arr[],int s)
    {
        if(space==0)
        {
            for(int i=0; i<2; i++)
            {
               cout<<name << " " << name << " " << name ;
            }

        }
        else if ( space == 1 )
        {
            for(int i=0; i<s; i++)
            {
                if(arr[i]==' ')
                {
                    name+= name.substr(i,s);
                }
            }
            cout<<name<<endl;
        }
    }
/// ///////////////////////////////////////////////

    void print(string name)
    {
        int Size=name.length();
        char arr[Size+1];
        strcpy(arr,name.c_str());
        spaceCount(name);
        /// if parts of name = 1
        if (spaceCount(name) == 0){
            cout << "\n(1) " << name << endl << "(2) " << name << endl << "(3) " << name << endl;
        }
        /// if parts of name = 2
        if (spaceCount(name) == 1){
            cout << "(1)" << " ";
            for( int i = 0 ; i < Size ; i++){
                for(int j = 0 ; j < i ; j++){
                    if(arr[i] == ' '){
                        cout <<arr[j];
                    }
                }
            }
            cout << endl << "(2) ";
            for( int i = 0 ; i < Size ; i++){
                for(int j = i ; j < Size ; j++){
                    if(arr[i] == ' '){
                        cout <<arr[j];
                    }
                }
            }

            cout << endl << "(3) ";
            for( int i = 0 ; i < Size ; i++){
                for(int j = i ; j < Size ; j++){
                    if(arr[i] == ' '){
                        cout <<arr[j];
                    }
                }
            }
        }

        /// if parts of name = 3 or more
        if (spaceCount(name) >= 2){

            string word = "";
            int z = 1 ;
            for (int i = 0 ; i < name.size() ; i++){
            if (name[i] == ' ')
            {
                   temp_vector.push_back(word);
                   cout <<"(" << z << ")" << word << endl;
                   word = "";
                   z++;
            }
            else
                word = word + arr[i];

            }
            temp_vector.push_back(word);
            cout <<"(" << z << ")" << word << endl;
        }

    }
/// ///////////////////////////////////////////////

    int replace_fun(int b ,int e){
        b--;
        e--;
        if(b < temp_vector.size() && e < temp_vector.size()){
            swap(temp_vector.at(b) , temp_vector.at(e));
        }
        else
            return false;
        for ( int i = 0 ; i < temp_vector.size(); i++){
            cout << temp_vector[i] << " ";
        }
}
private:
    string name;
    vector <string> temp_vector;
};
int main()
{
    string input;
    cout << "Enter Your String :";
    getline(cin,input);
    StudenName ob(input);

    while ( true ){
    char choose ;
    cout << "\n1- To print details of name .\n2- To Swap Parts of name ( You Should To input more than three words ) .\n3- To End Program .\n";
    cout << "Enter Your choose :";
    cin >> choose ;
    if( choose == '1')
        ob.print(input);
    else if (choose == '2' && ob.spaceCount(input) >= 2 ){

        int b , e ;
        cout << "Enter two parts number :";
        cin >> b >> e;
        ob.replace_fun(b , e);
    }
    else
        break;
    }
    return 0;
}
