/*
 * Needleman_Wunsch.cpp
 *
 *  Created on: May 3, 2011
 *     Authors: Griffin DeJohn and Matt Morris
 */

#include "Needleman_Wunsch.h"
#include "Pair.h"
#include "Sequence.h"
#include "Substitution_Matrix.h"

Needleman_Wunsch::Needleman_Wunsch(Sequence *firstIn, Sequence *secondIn, int penaltyIn, Substitution_Matrix *subIn)
{
	sub = subIn;
	first = firstIn->getSequence( );
	second = secondIn->getSequence( );
	penalty = penaltyIn;
}

Pair *Needleman_Wunsch::align( )
{
	// construct the pair object...
	Pair *pair = new Pair( );

	// construct the table...
	vector<vector<int> > grid(first.size( ) + 1, vector<int> (second.size( ), 0));
	unsigned int i;
	unsigned int j;

	// set initial penalty values
	for (i = 0; i < first.size( ); i++)
	{
		grid[i][0] = i * penalty;
	}

	for (j = 0; j < second.size( ); j++)
	{
		grid[0][j] = j * penalty;
	}

	// set initial values according to sub_matrix
	for (i = 1; i < first.size( ); i++)
	{
		for (j = 1; j < second.size( ); j++)
		{
			grid[i][j] = sub->getScore(first.at((i - 1) * sizeof(char)), second.at((j - 1) * sizeof(char)));
		}
	}

	// score the table...
	int match = 0;
	int insertion = 0;
	int deletion = 0;

	for (i = 1; i < first.size( ); i++)
	{
		for (j = 1; j < second.size( ); j++)
		{
			match = grid[i - 1][j - 1] + sub->getScore(first.at((i - 1) * sizeof(char)), second.at((j - 1) * sizeof(char)));
			insertion = grid[i][j - 1] + penalty;
			deletion = grid[i - 1][j] + penalty;

			grid[i][j] = max(max(match, insertion), deletion);
		}
	}

	i = first.size( ) - 1;
	j = second.size( ) - 1;
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

		if (score == score_diagonal + sub->getScore(first.at((i - 1) * sizeof(char)), second.at((j - 1) * sizeof(char))))
		{
			pair->insertA(first.at((i - 1) * sizeof(char)));
			pair->insertB(second.at((j - 1) * sizeof(char)));
			i--;
			j--;
			matches++;
		}
		else if (score == score_left + penalty)
		{
			pair->insertA(first.at((i - 1) * sizeof(char)));
			pair->insertB('-');
			i--;
		}
		else //if (score == score_up + penalty)
		{
			pair->insertA('-');
			pair->insertB(second.at((j - 1) * sizeof(char)));
			j--;
		}
	}

	pair->setMatches(matches);

	while (i > 0)
	{
		pair->insertA(first.at((i - 1) * sizeof(char)));
		pair->insertB('-');
		i--;
	}

	while (j > 0)
	{
		pair->insertA('-');
		pair->insertB(second.at((j - 1) * sizeof(char)));
		j--;
	}

	pair->setScore(grid[first.size( ) - 1][second.size( ) - 1]);

	return pair;
}

Needleman_Wunsch::~Needleman_Wunsch( )
{
	delete sub;
}
