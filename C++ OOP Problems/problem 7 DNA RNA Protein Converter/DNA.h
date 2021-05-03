#ifndef DNA_H
#define DNA_H
#include "Sequence.h"

template<class T>
class RNA;

enum DNA_Type{promoter, motif, tail, noncoding};

template<class T>
class DNA : public Sequence<T>
{
    private:
        DNA_Type type;
        T* complementary_strand;
    public:
        template<class U> friend class Protein;
 	 	// constructors and destructor
 	 	void BuildComplementaryStrand(int start = -1, int end = -1);
        DNA();
        DNA(const T* seq, int length, DNA_Type atype = promoter);
        DNA(const DNA& rhs);
 	 	// function printing DNA sequence information to user
        void Print();
        T* getComplementaryStrand();
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
         RNA<T> ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
};

#endif // DNA_H

