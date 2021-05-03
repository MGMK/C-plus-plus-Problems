#ifndef CODONSTABLE_H
#define CODONSTABLE_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std ;

struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

class CodonsTable
{
     public:
       Codon codons[64];
        void LoadCodonsFromFile(const char* codonsFileName);
 	 	// constructors and destructor
        CodonsTable(const char* fileName);
        ~CodonsTable();
        char getAminoAcid(const char* value);
        void setCodon(const char* value, char AminoAcid, int index);
};

#endif // CODONSTABLE_H
