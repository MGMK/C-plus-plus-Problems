#ifndef PROTEIN_H
#define PROTEIN_H
#include "CodonsTable.h"
#include "DNA.h"
using namespace std;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

template<class T>
class Protein : public Sequence<T>
{
     private:
          Protein_Type type;
          CodonsTable table;
     public:
          Protein();
          Protein(const T* sequence, int length, Protein_Type atype = Cellular_Function);
          Protein(const Protein<T>& rhs);
          vector<DNA<T> > getDNAStrandsEncodingMe(const DNA<T>& bigDNA);
};

#endif // PROTEIN_H
