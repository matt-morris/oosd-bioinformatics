/*
 * Smith_Waterman.h
 *
 *  Created on: May 3, 2011
 *      Author: doubleemms
 */

#ifndef SMITH_WATERMAN_H_
#define SMITH_WATERMAN_H_

#include <vector>
#include <iostream>
#include <string>
#include "Substitution_Matrix.h"
//#include "Needleman_Wunsch.h"
#include "Pair.h"

using namespace std;

class Smith_Waterman //: public Needleman_Wunsch
{
public:
	Smith_Waterman(vector<char> *firstIn, vector<char> *secondIn, int penaltyIn, Substitution_Matrix *subIn);
	virtual ~Smith_Waterman();

	Pair *align();

private:
	Substitution_Matrix *sub;
	vector<char> *first;
	vector<char> *second;
	int penalty;
};

#endif /* SMITH_WATERMAN_H_ */
