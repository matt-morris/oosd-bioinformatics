/*
 * Needleman_Wunsch.h
 *
 *  Created on: May 3, 2011
 *      Author: doubleemms
 */

#ifndef NEEDLEMAN_WUNSCH_H_
#define NEEDLEMAN_WUNSCH_H_

#include "Substitution_Matrix.h"
#include "Pair.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Needleman_Wunsch
{
public:
	Needleman_Wunsch(vector<char> *firstIn, vector<char> *secondIn, int penaltyIn, Substitution_Matrix *subIn);
	virtual ~Needleman_Wunsch();

	Pair *align();

private:
	Substitution_Matrix *sub;
	vector<char> *first;
	vector<char> *second;
	int penalty;
};

#endif /* NEEDLEMAN_WUNSCH_H_ */
