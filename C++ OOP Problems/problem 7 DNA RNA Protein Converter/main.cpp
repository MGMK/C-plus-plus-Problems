#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include "Sequence.h"
#include "Protein.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include "RNA.h"

using namespace std;

int main()
{
    Sequence<char> s1, s2, s3;
    CodonsTable Table("r.txt");
    string input;
    bool running = true;
    int choice;
    while(running){ ///  bool condition .
        try{
            cout<< "1- Convert DNA -> RNA. \n"
                << "2- Convert DNA -> Protein. \n"
                << "3- Convert RNA -> DNA. \n"
                << "4- Convert RNA -> Protein. \n"
                << "5- list DNA strands encoding Protein. \n"
                << "6- Load sequence from file.\n"
                << "7- Align 2 sequences using LCS.\n"
                << "8- Align 2 sequences using global alignment.\n"
                << "9- Check Two Seq is Equal or not .\n"
                << "10- Check Two Seq is Equal or not .\n"
                << "11- Add Two Sequence .\n"
                << "12- Exit.\n";
                cin >> choice;
                switch(choice){ /// choice input .
                    case 1:{
                        cout << "Enter DNA: ";
                        cin >> input;
                        DNA<char> d1(input.c_str(), input.length());
                        cout << d1.ConvertToRNA() << endl;
                        break;
                    }
                    case 2:{
                        cout << "Enter DNA: ";
                        cin >> input;
                        DNA<char> d1(input.c_str(), input.length());
                        RNA<char> r(d1.ConvertToRNA());
                        cout << r.ConvertToProtein(Table);
                        break;
                    }
                    case 3:{
                        cout << "Enter RNA: ";
                        cin >> input;
                        RNA<char> r1(input.c_str(), input.length());
                        cout << r1.ConvertToDNA();
                        break;
                    }
                    case 4:{
                        cout << "Enter RNA: ";
                        cin >> input;
                        RNA<char> r1(input.c_str(), input.length());
                        cout << r1.ConvertToProtein(Table);
                        break;
                    }
                    case 5:{
                        cout << "Enter DNA: ";
                        cin >> input;
                        DNA<char> d1(input.c_str(), input.length());
                        cout << "Enter Protein: ";
                        cin >> input;
                        Protein<char> p1(input.c_str(), input.length());
                        vector<DNA<char> > v;
                        v = p1.getDNAStrandsEncodingMe(d1);
                        break;
                    }
                    case 6:{
                        char f[100];
                        cout << "Enter file name: ";
                        cin >> f;
                        s1.loadSequenceFromFile(f);
                        break;
                    }
                    case 7:{
                        cout << "Enter Sequence 1: ";
                        cin >> s1;
                        cout << "Enter Sequence 2: ";
                        cin >> s2;
                        cout << s1.Align(&s2);
                        break;
                    }
                    case 8:{
                        cout << "Enter Sequence 1: ";
                        cin >> s1;
                        cout << "Enter Sequence 2: ";
                        cin >> s2;
                        cout << s1.GlobalAlign(&s2);
                        break;
                    }
                    case 9:{
                        cout << "Enter Sequence 1: ";
                        cin >> s1;
                        cout << "Enter Sequence 2: ";
                        cin >> s2;

                        if ( s1 == s2){
                            cout << "Two Seq is Equal .\n";
                        }
                        else
                            cout << "Two Seq is not Equal .\n";
                        break;
                    }
                    case 10:{
                        cout << "Enter Sequence 1: ";
                        cin >> s1;
                        cout << "Enter Sequence 2: ";
                        cin >> s2;

                        if ( s1 != s2){
                            cout << "Two Seq is not Equal .\n";
                        }
                        else
                            cout << "Two Seq is Equal .\n";
                        break;
                    }
                    case 11:{
                        cout << "Enter Sequence 1: ";
                        cin >> s1;
                        cout << "Enter Sequence 2: ";
                        cin >> s2;
                        cout << "New Sequence is : " << s1 + s2 ;
                        break;
                    }
                    case 12:{
                        running = 0;
                        break;
                    }
                    default:
                        throw("Invalid choice.\n");
                        break;
                }
        }catch(const char* error){
            cout << error << endl;
        }
    }
    return 0;
}
