#include "DNA.h"
#include "RNA.h"
template<class T>
DNA<T>::DNA(){
    this->seq = 0;
}
template<class T>
DNA<T>::DNA(const T* seq, int length, DNA_Type atype){
    if(length <= 0 || length%3 != 0){
        throw("An Error has occurred plz enter a different length\n");
    }
    this->length = length;
    this->seq = new T[length + 1];
    for(int i = 0; i < length; ++i){
        this->seq[i] = seq[i];
    }
    this->seq[length] = '\0';
    this->type = atype;
    for(int i = 0; i < length; ++i){
        if(seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i] != 'T')
            throw("plz enter only ACGT...\n");
    }
}

template<class T>
DNA<T>::DNA(const DNA& rhs){
    this->seq = new T[rhs.length + 1];
    this->length = rhs.length;
    for(int i = 0; i < this->length; ++i){
        this->seq[i] = rhs.seq[i];
    }
    this->seq[this->length] = '\0';
    this->type = rhs.type;
}


template<class T>
void DNA<T>::Print(){
    Sequence<T>::Print();
}

template<class T>
RNA<T> DNA<T>::ConvertToRNA(){
    T* temp=new T[this->length + 1];
    temp[this->length] = '\0';
    for(int i = 0; i < this->length; ++i){
        temp[i] = this->seq[i];
        if(temp[i]=='T'){
            temp[i] = 'U';
        }
    }
    RNA<T> rna(temp, this->length, mRNA);
    delete[] temp;
    return rna;
}

template<class T>
void DNA<T>::BuildComplementaryStrand(int start, int end){
    if(start < 0 || end <= 0 || end - start > this->length){
        start = 0;
        end = this->length - 1;
    }
    complementary_strand = new T[end - start + 1];
    complementary_strand[end - start] = '\0';
    for(int i = start; i <= end; ++i){
        if(this->seq[i] == 'A'){
            complementary_strand[i] = 'T';
        }else if(this->seq[i] == 'C'){
            complementary_strand[i] = 'G';
        }else if(this->seq[i] == 'G'){
            complementary_strand[i] = 'C';
        }else if(this->seq[i] == 'T'){
            complementary_strand[i] = 'A';
        }else{
            throw("Error.\nPlease enter only ACGT...\n");
        }
    }
    for(int i = 0; i < (end-start)/2 + 1; ++i)
        swap(complementary_strand[i], complementary_strand[end - start - i]);
}

template<class T>
T* DNA<T>::getComplementaryStrand(){
    return this->complementary_strand;
}

template class DNA<char>;
template class DNA<int>;
