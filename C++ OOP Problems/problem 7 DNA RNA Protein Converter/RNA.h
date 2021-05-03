#ifndef RNA_H
#define RNA_H
#include "Sequence.h"
#include "Protein.h"

template<class T>
class DNA;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

template<class T>
class RNA : public Sequence<T>
{
      private:
        RNA_Type type;

  	public:
 	      // constructors and destructor
        RNA();
        RNA(const T* seq, int length, RNA_Type atype = mRNA);
        RNA(const RNA& rhs);
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein<T> ConvertToProtein(CodonsTable& table);
 	 	// function to convert the RNA sequence back to DNA
        DNA<T> ConvertToDNA();
};

#endif // RNA_H
