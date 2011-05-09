/*
 * Smith_Waterman.cpp
 *
 *  Created on: May 3, 2011
 *      Author: Matt Morris
 */

#include "Smith_Waterman.h"

Smith_Waterman::Smith_Waterman(vector<char> *firstIn, vector<char> *secondIn, int penaltyIn, Substitution_Matrix *subIn)
//: Needleman_Wunsch(firstIn, secondIn, penaltyIn, subIn)    // Call the superclass constructor in the subclass' initialization list.
{
	sub = subIn;
	first = firstIn;
	second = secondIn;
	penalty = penaltyIn;
}

Pair *Smith_Waterman::align( )
{
	// construct the pair object...
	Pair *pair = new Pair( );

	// construct the table...
	vector<vector<int> >grid(first->size( ) + 1, vector<int>(second->size( ), 0));
	unsigned int i;
	unsigned int j;

	// set initial penalty values
	for (i = 0; i < first->size( ); i++)
	{
		grid[i][0] = i * penalty;
	}

	for (j = 0; j < second->size( ); j++)
	{
		grid[0][j] = j * penalty;
	}

	// set initial values according to sub_matrix
	for (i = 1; i < first->size( ); i++)
	{
		for (j = 1; j < second->size( ); j++)
		{
			grid[i][j] = sub->getScore(first->at((i - 1) * sizeof(char)), second->at((j - 1) * sizeof(char)));
		}
	}

	/* print the grid
	for (i = 0; i < first->size( ); i++)
	{
		for (j = 0; j < second->size( ); j++)
		{
			cout << "\t" << grid[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;*/

	// score the table...
	int match = 0;
	int insertion = 0;
	int deletion = 0;

	for (i = 1; i < first->size( ); i++)
	{
		for (j = 1; j < second->size( ); j++)
		{
			match = grid[i - 1][j - 1] + sub->getScore(first->at((i - 1) * sizeof(char)), second->at((j - 1) * sizeof(char)));
			insertion = grid[i][j - 1] + penalty;
			deletion = grid[i - 1][j] + penalty;

			grid[i][j] = max(max(match, insertion), deletion);
			if (grid[i][j] < 0)
			{
				grid[i][j] = 0;
			}
			//				cout << "\nInserting " << grid[i][j] << " into " << i << ", " << j;
		}
	}

	// trace back to find the alignment...
	string out1("");
	string out2("");

	// find highest value
	int highest = 0;
	for (unsigned int iTest = 0; iTest < first->size( ) - 1; iTest++)
	{
		for (unsigned int jTest = 0; jTest < second->size( ) - 1; jTest++)
		{
			if (grid[iTest][jTest] >= highest)
			{
				highest = grid[iTest][jTest];
				i = iTest;
				j = jTest;
			}
		}
	}
	//		i = first->size() - 1;
	//		j = second->size() - 1;
	int score;
	int score_diagonal;
	int score_up;
	int score_left;
	int matches = 0;

	while (i > 0 && j > 0)
	{
		score = grid[i][j];
		score_diagonal = grid[i - 1][j - 1];
		score_up = grid[i][j - 1];
		score_left = grid[i - 1][j];

		if (score == score_diagonal + sub->getScore(first->at((i - 1) * sizeof(char)), second->at((j - 1) * sizeof(char))))
		{
			pair->insertA(first->at((i - 1) * sizeof(char)));
			pair->insertB(second->at((j - 1) * sizeof(char)));
			i--;
			j--;
			matches++;/*
			cout << "\nDiagonal" << endl;
			cout << out1 << endl << out2 << endl;*/
		}
		else if (score == score_left + penalty)
		{
			pair->insertA(first->at((i - 1) * sizeof(char)));
			pair->insertB('-');
			i--;/*
			cout << "\nLeft" << endl;
			cout << out1 << endl << out2 << endl;*/
		}
		else //if (score == score_up + penalty)
		{
			pair->insertA('-');
			pair->insertB(second->at((j - 1) * sizeof(char)));
			j--;/*
			cout << "\nUp" << endl;
			cout << out1 << endl << out2 << endl;*/
		}
		if (grid[i][j] == 0)
		{
			break;
		}
	}

	pair->setMatches(matches);

	//		while (i > 0)
	//		{
	//			pair->insertA(first->at((i-1) * sizeof(char)));
	//			pair->insertB('-');
	//			i--;
	//			cout << "\nLeft" << endl;
	//			cout << out1 << endl << out2 << endl;
	//		}
	//
	//		while (j > 0)
	//		{
	//			pair->insertA('-');
	//			pair->insertB(second->at((j-1) * sizeof(char)));
	//			j--;
	//			cout << "\nUp" << endl;
	//			cout << out1 << endl << out2 << endl;
	//		}

	/* print the grid
	for (i = 0; i < first->size( ); i++)
	{
		for (j = 0; j < second->size( ); j++)
		{
			cout << "\t" << grid[i][j];
		}
		cout << endl;
	}*/

	pair->setScore(grid[first->size( ) - 1][second->size( ) - 1]);

	// return aligned sequence
	return pair;
}

Smith_Waterman::~Smith_Waterman( )
{
	// TODO Auto-generated destructor stub
}
