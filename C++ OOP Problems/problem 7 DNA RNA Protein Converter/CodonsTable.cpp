#include "CodonsTable.h"

CodonsTable::CodonsTable(const char* fileName)
{
    this->LoadCodonsFromFile(fileName);
}

char CodonsTable::getAminoAcid(const char* value){
    for(int i = 0; i < 64; ++i){
        if(strcmp(value , codons[i].value) == 0){
            return codons[i].AminoAcid;
        }
        //TODO  Throw Exception
    }
    return 'X';
}

CodonsTable::~CodonsTable()
{
    //dtor
}
void CodonsTable::LoadCodonsFromFile(const char* fileName){
    ifstream f;
    f.open(fileName);
    if(f.is_open()){
        Codon codon;
        int i = 0;
        while(f >> codon.value && f >> codon.AminoAcid){
            codon.value[3] = '\0';
            this->codons[i++] = codon;
        }
    }
}

void CodonsTable::setCodon(const char* value, char AminoAcid, int index){
    strcpy(this->codons[index].value , value);
    this->codons[index].AminoAcid = AminoAcid;
}
