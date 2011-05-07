//============================================================================
// Name        : oosd-final.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

#include "Needleman_Wunsch.h"
#include "Smith_Waterman.h"
#include "Substitution_Matrix.h"
#include "Pair.h"

using namespace std;

int main()
{
//	hard-coded test values
	char order[4] = {'A', 'G', 'C', 'T'};

	int sub_matrix[4][4];
//	sub_matrix[0][0] = 10;
//	sub_matrix[0][1] = -1;
//	sub_matrix[0][2] = -3;
//	sub_matrix[0][3] = -4;
//
//	sub_matrix[1][0] = -1;
//	sub_matrix[1][1] = 7;
//	sub_matrix[1][2] = -5;
//	sub_matrix[1][3] = -3;
//
//	sub_matrix[2][0] = -3;
//	sub_matrix[2][1] = -5;
//	sub_matrix[2][2] = 9;
//	sub_matrix[2][3] = 0;
//
//	sub_matrix[3][0] = -4;
//	sub_matrix[3][1] = -3;
//	sub_matrix[3][2] = 0;
//	sub_matrix[3][3] = 8;

	sub_matrix[0][0] = 1;
	sub_matrix[0][1] = 0;
	sub_matrix[0][2] = 0;
	sub_matrix[0][3] = 0;

	sub_matrix[1][0] = 0;
	sub_matrix[1][1] = 1;
	sub_matrix[1][2] = 0;
	sub_matrix[1][3] = 0;

	sub_matrix[2][0] = 0;
	sub_matrix[2][1] = 0;
	sub_matrix[2][2] = 1;
	sub_matrix[2][3] = 0;

	sub_matrix[3][0] = 0;
	sub_matrix[3][1] = 0;
	sub_matrix[3][2] = 0;
	sub_matrix[3][3] = 1;

	Substitution_Matrix *sub = new Substitution_Matrix(order, sub_matrix);
	sub->printMatrix();
	cout << endl << endl;

	// hard-coded test sequences
	int penalty = -6;
	char one[ ] = "AGACTAGTTAC", two[ ] = "CGAGACGT";	// hard-coded test values
//	char one[ ] = "HEAGAWGHEE", two[ ] = "PAWHEAE";
	vector<char> *first = new vector<char>(one, one + sizeof(one) / sizeof(char));
	vector<char> *second = new vector<char>(two, two + sizeof(two) / sizeof(char));

	Needleman_Wunsch *needleman = new Needleman_Wunsch(first, second, penalty, sub);

	Pair *output = needleman->align();
	cout << endl << output->getA() << endl << output->getB() << endl << "Score:  " << output->getScore() << endl;


	Smith_Waterman *smith = new Smith_Waterman(first, second, penalty, sub);
	Pair *smith_output = smith->align();
	cout << endl << smith_output->getA() << endl << smith_output->getB() << endl << "Score:  " << smith_output->getScore() << endl;

	return 0;
}
