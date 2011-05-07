/*
 * Substitution_Matrix.h
 *
 *  Created on: May 3, 2011
 *      Author: doubleemms
 */

#ifndef SUBSTITUTION_MATRIX_H_
#define SUBSTITUTION_MATRIX_H_

using namespace std;

class Substitution_Matrix
{
public:
	Substitution_Matrix(char orderIn[4], int matrixIn[4][4]);//vector<vector<int> > *matrixIn);
//	Substitution_Matrix(char c0, char c1, char c2, char c3, int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9);
	virtual ~Substitution_Matrix();

	int getScore(char a, char b);

	void printMatrix();

private:
	//vector<char> *order;
	//vector<vector<int> > *matrix;
	char order[4];
	int matrix[4][4];
};

#endif /* SUBSTITUTION_MATRIX_H_ */
