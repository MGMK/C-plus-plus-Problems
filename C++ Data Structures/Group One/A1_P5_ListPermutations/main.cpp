#include <iostream>

using namespace std;
void ListPermutations(string s);
long factorial(int a);
void RecPermute(string soFar, string rest,string words[]);
long x=0;
void RecPermute(string soFar, string rest,string words[])
{
    if (rest == "")  // No more characters
    {
        words[x]=soFar;
        x++;
    }

    else // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++)
        {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining,words);
        }
    if(rest=="" && x==factorial(soFar.length()+rest.length()))
    {
        for(int i=0; i<x; i++)
        {
            for(int j=i+1; j<x; j++)
            {
                if(words[i]==words[j])
                {
                    words[j]="!!";
                }
            }
        }
        for(int i=0; i<x; i++)
        {
            if(words[i]!="!!")
            {
                cout<<words[i]<<endl;
            }
        }
    }
}
// "wrapper" function
void ListPermutations(string s)
{
    string words[factorial(s.length())];
    RecPermute("", s,words);
}

long factorial(int a)
{
    if(a==0)
        return 1;
    else
        return a*factorial(a-1);
}

int main()
{
 ListPermutations("Makka");

    return 0;
}
