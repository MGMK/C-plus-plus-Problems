#include "Sequence.h"

template<class T>
Sequence<T>::Sequence(){
    this->seq = 0;
}

template<class T>
Sequence<T>::Sequence(int length){
    if(length <= 0 || length%3 != 0){
        throw("An Error has occurred plz enter a different length\n");
    }
    this->length = length;
}

template<class T>
Sequence<T>::Sequence(const T* seq, int length){
    if(length <= 0 || length%3 != 0){  /// take length from user %3 (3 , 6 . ...) .
        throw("An Error has occurred plz enter a different length\n");
    }
    this->length = length;
    this->seq = new T[length + 1];
    for(int i = 0; i < length; ++i){
        this->seq[i] = seq[i];
    }
    this->seq[length] = '\0';  /// for bugs .
}


template<class T>
Sequence<T>::Sequence(Sequence& rhs){
    this->seq = new T[rhs.length + 1];
    this->length = rhs.length;
    for(int i = 0; i < this->length; ++i){
        this->seq[i] = rhs.seq[i];
    }
    this->seq[this->length] = '\0';
}

template<class T>
void Sequence<T>::Print(){
    cout << this->seq;
    cout << endl;
}

template<class T>
Sequence<T>::~Sequence(){
    delete[] this->seq;
}
template<class T>
Sequence<T> Sequence<T>::operator=(const Sequence<T>& rhs){
    delete[] seq;
    this->seq = new T[rhs.length + 1]; /// for bugs '/0'.
    this->length = rhs.length;
    for(int i = 0; i < this->length; ++i){
        this->seq[i] = rhs.seq[i];
    }
    this->seq[this->length] = '\0';
    return *this;
}
template<class T>
Sequence<T> Sequence<T>::operator+(const Sequence<T>& other){
    T *temp = new T[other.length + length + 1];
    int len = other.length + length;
    for(int i = 0; i < length; ++i){
        temp[i] = seq[i];
    }
    for(int i = 0; i < other.length; ++i){
        temp[i + length] = other.seq[i];
    }
    Sequence<T> s(temp, len);
    delete[] temp;
    return s;
}
template<class T>
bool Sequence<T>::operator==(const Sequence<T>& other){
    if(length ==other.length){
        for(int i=0;i<length;i++)
        {
            if(seq[i]!=other.seq[i])
                return false;
        }
    }
    return true;
}
template<class T>
bool Sequence<T>::operator!=(const Sequence<T>& other){
    if(*this == other){
        return false;
    }else{
        return true;
    }

}

/// for Bones .
template<class T>
void Sequence<T>::loadSequenceFromFile(const char* fileName){
    ifstream f;
    vector<T> t;
    T x ;
    f.open(fileName);
    while(f >> x)
    t.push_back(x);
    length = (int)t.size();
    delete[] this -> seq;
    this -> seq = new T[t.size() + 1];
    for(int i = 0; i < (int)t.size(); ++i){
        seq[i] = t[i];
    }
    seq[length] = '\0';
}
////////////////////////////////////////////
int max(int a, int b)
{
    return (a > b)? a : b;
}
template<class T>
char* LCS(T *X, T *Y, int s1, int s2)
{
    int lenLCS [s1+1][s2+1];
    int Size, i, j;

    for(i = 0; i <= s1; i++)
    {
        for(j = 0; j <= s2; j++)
        {
            if(i == 0 || j == 0)
            {
                lenLCS[i][j] = 0;
            }
            else if(X[i-1] == Y[j-1])
            {
                lenLCS[i][j] = lenLCS[i-1][j-1] + 1;
            }
            else
            {
                lenLCS[i][j] = max(lenLCS[i-1][j], lenLCS[i][j-1]);
            }
        }
    }

    i = s1;
    j = s2;
    Size = lenLCS[i][j]; ///Length of LCS

    char *LongestCommon  = new char [Size + 1];

    LongestCommon[Size] = '\0';

    while (i > 0 && j > 0)
    {
        if(X[i-1] == Y[j-1])
        {
            LongestCommon[Size-1] = X[i-1];
            Size--;
            i--;
            j--;

        }
        else if(lenLCS[i-1][j] > lenLCS[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }

    }

    return LongestCommon;
}
/// /////////////////////////////////////////////
template<class T>
char* Sequence<T>::Align(Sequence<T>* s2){
    return LCS(this->seq, s2->seq, this->length, s2->length);
}

int max(int a, int b, int c){
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

template<class T>
int GAlign(T *str1, T *str2, int gap){
    int S1 = sizeof(str1)/sizeof(str1[0]);
    int S2 = sizeof(str2)/sizeof(str2[0]);

    //int S1 = strlen(str1);
    //int S2 = strlen(str2);
    int Align [S1+1][S2+1];

    for (int i = 0; i <= S1; ++i)
        Align[0][i] = gap * i;
    for (int i = 0; i <= S2; ++i)
        Align[i][0] = gap * i;

    for (int i = 1; i <= S1; ++i)
    {
        for (int j = 1; j <= S2; ++j)
        {
            if (str1[i] == str2[j])
            {
                Align[i][j] = max(Align[i-1][j-1] +1,
                                  Align[i-1][j] +gap,
                                  Align[i][j-1] + gap);
            }
            else if (str1[i] != str2[j])
            {
                Align[i][j] = max(Align[i-1][j-1] -1,
                                  Align[i-1][j] + gap,
                                  Align[i][j-1] + gap);
            }
        }
    }

    int r = S1;
    int c = S2;
    string str1_aligned;
    string str2_aligned;

    for (; r >= 1 && c >= 1; --r)
    {
        if (str1[r] == str2[c])
        {
            if (Align[r][c] == Align[r-1][c-1] + 1)
            {
                str1_aligned = char(str1[r-1]) + str1_aligned;
                str2_aligned = char(str2[c-1]) + str2_aligned;
                --c;
            }

            else if (Align[r][c] == Align[r-1][c] + gap)
            {
                str1_aligned = char(str1[r-1]) + str1_aligned;
                str2_aligned = '-' + str2_aligned;
            }

            else
            {
                str1_aligned = '-' + str1_aligned;
                str2_aligned = (char)str2[c-1] + str2_aligned;
                --c;
            }
        }
        else if (str1[r] != str2[c])
        {
            if (Align[r][c] == Align[r-1][c-1] - 1)
            {
                str1_aligned = (char)str1[r-1] + str1_aligned;
                str2_aligned = (char)str2[c-1] + str2_aligned;
                --c;
            }

            else if (Align[r][c] == Align[r-1][c] + gap)
            {
                str1_aligned = (char)str1[r-1] + str1_aligned;
                str2_aligned = '-' + str2_aligned;
            }

            else
            {
                str1_aligned = '-' + str1_aligned;
                str2_aligned = (char)str2[c-1] + str2_aligned;
                --c;
            }

        }

    }

    while (r >= 1 && c < 1)
        {
            str1_aligned = (char)str1[r-1] + str1_aligned;
            str2_aligned = '-' + str2_aligned;
            --r;
        }
    while (c >= 1 && r < 1)
        {
            str1_aligned = '-' + str1_aligned;
            str2_aligned = (char)str2[c-1] + str2_aligned;
            --c;
        }

    cout << str1_aligned << endl;
    cout << str2_aligned << endl;
    return Align[S1][S2];

}

template<class T>
int Sequence<T>::GlobalAlign(Sequence<T>* s2){
    return GAlign(this->seq, s2->seq, -2);
}

template class Sequence<char>;
template class Sequence<int>;
