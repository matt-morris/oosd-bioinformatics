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

int penalty(int open, int length, int extension)
{
	return open + ((length - 1) * extension);
}

int dynamic(vector<char> first, vector<char> second, int match, int mismatch, int open, int extension, int (*gap)(int, int, int))
{
	unsigned int i, j;
	int table[first.size( )][second.size( )];

	table[0][0] = 0;

	for (i = 1; i < first.size( ); i++)
	{
		table[i][0] = i * gap(open, 1, extension);
	}

	for (j = 1; j < second.size( ); j++)
	{
		table[0][j] = j * gap(open, 1, extension);
	}

	for (i = 1; i < first.size( ); i++)
	{
		for (j = 1; j < second.size( ); j++)
		{
			table[i][j] =
			(
				max
				(
					table[i - 1][j - 1] + (first.at(i - 1) == second.at(j - 1) ? match : mismatch),
					max(table[i][j - 1], table[i - 1][j]) + gap(open, 1, extension)
				)
			);
		}
	}

	return table[i - 1][j - 1];
}

int align(vector<char> first, vector<char> second, int (*eval)(vector<char>, vector<char>, int, int, int, int, int (*)(int, int, int)) = dynamic, int match = 1, int mismatch = 0, int open = -6, int extension = 0, int (*gap)(int, int, int) = penalty)
{
	return eval(first, second, match, mismatch, open, extension, gap);
}

int main( )
{
	char one[ ] = "HEAGAWGHEE", two[ ] = "PAWHEAE";
	vector<char> first(one, one + sizeof(one) / sizeof(char)), second(two, two + sizeof(two) / sizeof(char));
	cout << align(first, second) << endl;
	return 0;
}
