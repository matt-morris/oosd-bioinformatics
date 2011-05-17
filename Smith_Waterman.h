/*
 * Smith_Waterman.h
 *
 *  Created on: May 3, 2011
 *      Author: Matt Morris
 */

#ifndef SMITH_WATERMAN_H_
#define SMITH_WATERMAN_H_

#include "Pair.h"
#include "Sequence.h"
#include "Substitution_Matrix.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Smith_Waterman
{
public:
	Smith_Waterman(Sequence *firstIn, Sequence *secondIn, int penaltyIn, Substitution_Matrix *subIn);
	virtual ~Smith_Waterman();

	Pair *align();

private:
	Substitution_Matrix *sub;
	string first;
	string second;
	int penalty;
};

#endif /* SMITH_WATERMAN_H_ */
