/*
 * test.cpp
 *
 *  Created on: Apr 7, 2011
 *      Author: griffin
 */

#include <iostream>
#include <vector>
using namespace std;

//static char GAP = '-';

int dynamic(vector<char> first, vector<char> second, int match, int mismatch, int gap)
{
	unsigned int i, j;
	int table[first.size( )][second.size( )];

	for (i = 0; i < first.size( ); i++)
	{
		table[i][0] = i * gap;
		cout << "table[" << i << "][0]: " << table[i][0] << endl;
	}

	for (i = 1; i < second.size( ); i++)
	{
		table[0][i] = i * gap;
		cout << "table[" << i << "][0]: " << table[i][0] << endl;
	}

	for (i = 1; i < first.size( ); i++)
	{
		for (j = 1; j < second.size( ); j++)
		{
			table[i][j] =
			(
				max
				(
					table[i - 1][j - 1] + first.at(i - 1) == first.at(j - 1) ? match : mismatch,
					max(table[i][j - 1], table[i - 1][j]) + gap
				)
			);
			cout << "table[" << i << "][" << j << "]: " << table[i][j] << endl;
		}
	}

	return table[i][j];
}

int align(vector<char> first, vector<char> second, int (*eval)(vector<char>, vector<char>, int, int, int) = dynamic, int match = 1, int mismatch = 0, int gap = -6)
{
	return eval(first, second, match, mismatch, gap);
}

int main ( )
{
	char one[ ] = "GCCACCGT", two[ ] = "GCCACCGT";
	vector<char> first(one, one + sizeof(one) / sizeof(char)), second(two, two + sizeof(two) / sizeof(char));
	for (unsigned int i = 0; i < first.size( ) - 1; i++)
	{
		//cout << first.at(i);
	}
	cout << align(first, second);
	return 0;
}
