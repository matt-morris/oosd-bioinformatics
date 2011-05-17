/*
 * Needleman_Wunsch.h
 *
 *  Created on: May 3, 2011
 *     Authors: Griffin DeJohn and Matt Morris
 */

#ifndef NEEDLEMAN_WUNSCH_H_
#define NEEDLEMAN_WUNSCH_H_

#include "Pair.h"
#include "Sequence.h"
#include "Substitution_Matrix.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Needleman_Wunsch
{
public:
	Needleman_Wunsch(Sequence *firstIn, Sequence *secondIn, int penaltyIn, Substitution_Matrix *subIn);
	virtual ~Needleman_Wunsch();

	Pair *align();

private:
	Substitution_Matrix *sub;
	string first;
	string second;
	int penalty;
};

#endif /* NEEDLEMAN_WUNSCH_H_ */
