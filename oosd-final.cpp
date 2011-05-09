//============================================================================
// Name        : oosd-final.cpp
// Authors     : Griffin DeJohn and Matt Morris
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>

#include "Needleman_Wunsch.h"
#include "Smith_Waterman.h"
#include "Substitution_Matrix.h"
#include "Pair.h"

using namespace std;

int main( ) {
	//	hard-coded test values
	char order[4] = {'A', 'G', 'C', 'T'};

	int sub_matrix[4][4] =
	{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	/* [4][4];
	sub_matrix[0][0] = 10;
	sub_matrix[0][1] = -1;
	sub_matrix[0][2] = -3;
	sub_matrix[0][3] = -4;

	sub_matrix[1][0] = -1;
	sub_matrix[1][1] = 7;
	sub_matrix[1][2] = -5;
	sub_matrix[1][3] = -3;

	sub_matrix[2][0] = -3;
	sub_matrix[2][1] = -5;
	sub_matrix[2][2] = 9;
	sub_matrix[2][3] = 0;

	sub_matrix[3][0] = -4;
	sub_matrix[3][1] = -3;
	sub_matrix[3][2] = 0;
	sub_matrix[3][3] = 8;
	*/
	Substitution_Matrix *sub = new Substitution_Matrix(order, sub_matrix);

	int penalty = -6;

	vector<char> *first = new vector<char>( ), *second = new vector<char>( );

	ifstream file;
	char current;

	file.open("first");
	if (file.is_open( ))
	{
		while (!file.eof( ))
		{
			current = file.get( );
			first->push_back(current);
		}
	}
	file.close( );

	file.open("second");
	if (file.is_open( ))
	{
		while (!file.eof( ))
		{
			current = file.get( );
			second->push_back(current);
		}
	}
	file.close( );

	Pair *output;

	Needleman_Wunsch *needleman = new Needleman_Wunsch(first, second, penalty, sub);
	output = needleman->align( );
	cout << "Needleman-Wunsch" << endl;
	output->printReport( );

	Smith_Waterman *smith = new Smith_Waterman(first, second, penalty, sub);
	output = smith->align( );
	cout << endl << "Smith-Waterman" << endl;
	output->printReport( );

	return 0;
}
