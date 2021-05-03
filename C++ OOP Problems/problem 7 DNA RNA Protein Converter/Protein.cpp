#include "Protein.h"
#include "RNA.h"
using namespace std ;

template<class T>
Protein<T>::Protein() : table("r.txt")
{

    this -> seq = 0;
}
template<class T>
Protein <T>::Protein(const T* seq, int length, Protein_Type atype) : table("r.txt"){
    this->length = length;
    this->seq = new T[length + 1];
    for(int i = 0; i < length; ++i){
        this->seq[i] = seq[i];
    }
    this->seq[length] = '\0';
    this->type = atype;
    for(int i = 0; i < length; ++i){
        if(seq[i] == 'B' || seq[i] == 'J' || seq[i] == 'O' || seq[i] == 'U' || seq[i] == 'X' || seq[i] == 'Z')
            throw("plz enter another sequence...\n");
    }
}

template<class T>
Protein<T>::Protein(const Protein<T>& rhs) : table("r.txt"){
    this->seq = new T[rhs.length + 1];
    this->length = rhs.length;
    for(int i = 0; i < this->length; ++i){
        this->seq[i] = rhs.seq[i];
    }
    this->seq[this->length] = '\0';
    this->type = rhs.type;
}


template<class T>
vector<DNA<T> > Protein<T>::getDNAStrandsEncodingMe(const DNA<T>& bigDNA){
    vector <DNA<T> > DNAvector;
    for(int i = 0; i < bigDNA.length - (3*this->length) + 1; ++i){
        T* temp = new T[this->length * 3 + 1];
        temp[this->length * 3] = '\0';
        for(int j = 0; j < this->length * 3; ++j){
            temp[j] = bigDNA.seq[i+j];
        }
        DNA<T> d(temp, this->length * 3);
        RNA<T> r(d.ConvertToRNA());
        Protein<T> p(r.ConvertToProtein(this->table));
        if(p == *this){
            DNAvector.push_back(d);
        }
    }
    return DNAvector;
}

template class Protein<char>;
template class Protein<int>;
