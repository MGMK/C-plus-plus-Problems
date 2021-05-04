#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    string tempword;
    map<string, int> counters;
    map<string, int> erase_counters;
    cout << "If you Want To End Enter done .\n Enter Your Words :";
    while (cin >> s){
        if(s == "done")
            break;
        else
            ++counters[s];
            if(s[0] != 'a'){
                tempword += s;
                tempword += " ";
                ++erase_counters[s];
            }
    }
    cout << endl<< "The Output is :\n\n";

    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
        /// it -> first is the word
        /// it -> second is the counter
    }
    cout << ".......................................................................................\n";
    cout << "After Erase :\n\n";

    for (map<string, int>::const_iterator it = erase_counters.begin();it != erase_counters.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    return 0;
}
