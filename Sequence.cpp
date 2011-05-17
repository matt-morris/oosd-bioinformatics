/*
 * Sequence.cpp
 *
 *  Created on: May 16, 2011
 *      Author: Griffin DeJohn
 */

#include "Sequence.h"
#include "Pair.h"
#include <string>

Sequence::Sequence(string accession, string sequence)
{
	this->accession = accession;
	this->sequence = sequence;
}

string Sequence::getAccession( )
{
	return accession;
}

string Sequence::getSequence( )
{
	return sequence;
}/*

Pair Sequence::alignPairwise(Sequence seq, Pair (*eval)(Sequence, Sequence, Substitution_Matrix *, int, int, int (*)(int, int, int)), Substitution_Matrix *sub, int open, int extension, int (*gap)(int, int, int))
{
	return eval(this, seq, sub, open, extension, gap);
}*/
