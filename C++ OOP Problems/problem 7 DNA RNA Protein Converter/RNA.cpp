#include "RNA.h"
#include "DNA.h"
template <class T>
RNA<T>::RNA()
{
   this->seq = 0;
}
template <class T>
RNA<T>::RNA(const T* seq,int length,RNA_Type atype)
{
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
        if(seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i] != 'U')
            throw("plz enter only ACGU...\n");
    }
}

template <class T>
RNA<T>::RNA(const RNA& rhs)
{
    this->seq = new T[rhs.length + 1];
    this->length = rhs.length;
    for(int i = 0; i < this->length; ++i){
        this->seq[i] = rhs.seq[i];
    }
    this->seq[this->length] = '\0';
    this->type = rhs.type;
}

template <class T>
void RNA <T>:: Print(){
 Sequence<T>::Print();
}

template<class T>
DNA<T> RNA<T>::ConvertToDNA(){
    T* temp=new T[this->length + 1];
    temp[this->length] = '\0';
    for(int i = 0; i < this->length; ++i){
        temp[i] = this->seq[i];
        if(temp[i] == 'U'){
            temp[i] = 'T';
        }
    }
    DNA<T> dna(temp, this->length, promoter);
    delete[] temp;
    return dna;
}
template<class T>
Protein<T> RNA<T>::ConvertToProtein(CodonsTable& table){
    T* protein = new T[this->length/3];
    int x = 0;
    bool continu = 1;
    for(int i = 0; i < this->length && continu; i+=3 ){
        for(int j = 0; j < 64 && continu; ++j){
            if(this->seq[i] == table.codons[j].value[0] && this->seq[i+1] == table.codons[j].value[1] && this->seq[i+2] == table.codons[j].value[2]){
                if(table.codons[j].AminoAcid == 'X'){
                    continu = 0;
                    break;
                }
                protein[x++] = table.codons[j].AminoAcid;
                break;
            }
        }
    }
    Protein<T> p(protein, x);
    delete[] protein;
    return p;
}

template class RNA<char>;
template class RNA<int>;
