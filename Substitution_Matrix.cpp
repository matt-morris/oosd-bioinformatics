/*
 * Substitution_Matrix.cpp
 *
 *  Created on: May 3, 2011
 *      Author: doubleemms
 */

#include "Substitution_Matrix.h"
#include <iostream>

using namespace std;

Substitution_Matrix::Substitution_Matrix(char orderIn[4], int matrixIn[4][4])// int **matrixIn)12//vector<vector<int> > *matrixIn)
//Substitution_Matrix::Substitution_Matrix(char c0, char c1, char c2, char c3, int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9)
{
	// constructor
	for (int i = 0;i < 4;i++)
	{
		order[i] = orderIn[i];
	}
	//matrix = matrixIn;

	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			matrix[i][j] = matrixIn[i][j];
		}
	}
}

int Substitution_Matrix::getScore(char a, char b)
{
	int score;
	for (unsigned int i = 0;i < 4;i++)
	{
		if (order[i] == a)
		{
			for (unsigned int j = 0;j < 4;j++)
			{
				if (order[j] == b)
				{
					score = matrix[i][j];
				}
			}
		}
	}
	return score;
}

void Substitution_Matrix::printMatrix()
{
	cout << endl;
	for (int i = 0;i < 4;i++)
	{
		cout << "\t" << order[i];
	}
	for (int i = 0;i < 4;i++)
	{
		cout << endl << order[i];
		for (int j = 0;j < 4;j++)
		{
			cout << "\t" << matrix[i][j];
		}
	}
}

Substitution_Matrix::~Substitution_Matrix()
{
	// clean up...
	delete order;
	delete matrix;
}
