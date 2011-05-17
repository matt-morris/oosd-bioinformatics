/*
 * Sequence.h
 *
 *  Created on: May 16, 2011
 *      Author: Griffin DeJohn
 */

#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include "Pair.h"
#include "Substitution_Matrix.h"

#include <string>

class Sequence
{
	public:
		Sequence(string, string);

		string getAccession( );
		string getSequence( );
		Pair alignPairwise(Sequence, Pair (*)(Sequence, Sequence, Substitution_Matrix *, int, int, int (*)(int, int, int)), Substitution_Matrix *, int, int, int (*)(int, int, int));

	private:
		string accession;
		string sequence;
};

#endif /* SEQUENCE_H_ */
