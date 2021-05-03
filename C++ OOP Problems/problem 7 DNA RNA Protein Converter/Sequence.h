#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

template<class T>
class Sequence
{
    protected:
        T* seq;
        int length;
    public:

 	 	// constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(const T* seq, int length);  /// take length and seq .
        Sequence(Sequence& rhs); /// copy cons.
        virtual ~Sequence();
        Sequence<T> operator=(const Sequence<T>& rhs);
        Sequence operator+(const Sequence& other);
        bool operator==(const Sequence& other);
        bool operator!=(const Sequence& other);
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print();
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend istream& operator >> (istream &in, Sequence<T> &s){
            int t;
            cout << "Please The Length of the Sequence: ";
            in >> t;
            delete[] s.seq;
            s.seq = new T[t + 1];
            for(int i = 0; i < t; ++i){
                in >> s.seq[i];
            }
            s.length = t;
            return in;
        }
        friend ostream& operator<<(ostream& out, const Sequence<T>& sequence){
            for(int i = 0; i < sequence.length; ++i){
                out << (char) sequence.seq[i];
            }
            return out;
        }
        char* Align(Sequence<T>* s1); /// lcs function .
        int GlobalAlign(Sequence<T>* s2);
        void loadSequenceFromFile(const char* fileName);  /// load seq from file .

};

#endif // SEQUENCE_H
