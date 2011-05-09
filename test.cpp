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
	int table[first.size( )][second.size( )], horizontal[(first.size( ) - 1) + (second.size( ) - 1)], vertical[(first.size( ) - 1) + (second.size( ) - 1)];
	unsigned int i, j;

	table[0][0] = 0;

	for (i = 1; i < first.size( ); i++)
	{
		table[i][0] = i * gap(open, 1, extension);
		horizontal[i] = 1;
	}

	for (j = 1; j < second.size( ); j++)
	{
		table[0][j] = j * gap(open, 1, extension);
		vertical[j] = 1;
	}

	int up, diagonal, left;
	for (i = 1; i < first.size( ); i++)
	{
		for (j = 1; j < second.size( ); j++)
		{
			up = table[i][j - 1] + gap(open, 1, extension);
			diagonal = table[i - 1][j - 1] + (first.at(i - 1) == second.at(j - 1) ? match : mismatch);
			left = table[i - 1][j] + gap(open, 1, extension);

			if (diagonal >= left && diagonal >= up)
			{
				table[i][j] = diagonal;
				horizontal[i * j] = 1;
				vertical[i * j] = 1;
			}
			else if (left >= up)
			{
				table[i][j] = left;
				horizontal[i * j] = 1;
				vertical[i * j] = 0;
			}
			else
			{
				table[i][j] = up;
				horizontal[i * j] = 0;
				vertical[i * j] = 1;
			}
		}
	}
	i = j -= 1;

	/*vector<char> top, bottom;
	unsigned int k, l;
	while (i > 1 || j > 1)
	{
		k = horizontal[i * j], l = vertical[i * j];
		cout << "i = " << i << ", j = " << j << ", k = " << k << ", l = " << l << endl;
		top.insert(top.begin( ), (k == 0 ? GAP : first.at(i)));
		bottom.insert(bottom.begin( ), (l == 0 ? GAP : second.at(i)));
		if (i > 1) i -= k;
		if (j > 1) j -= l;
	}
	for (int z = 1; z < (first.size( ) - 1) + (second.size( ) - 1); z++)//i = 0; i < top.size( ); i++)
	{
		//cout << top.at(i);
		cout << horizontal[i];
	}
	cout << endl;
	for (int z = 1; z < (first.size( ) - 1) + (second.size( ) - 1); z++)//j = 0; j < bottom.size( ); j++)
	{
		//cout << bottom.at(j);
		cout << vertical[i];

	}
	cout << endl;*/

	return table[first.size( ) - 1][second.size( ) - 1];
}

int align(vector<char> first, vector<char> second, int (*eval)(vector<char>, vector<char>, int, int, int, int, int (*)(int, int, int)) = dynamic, int match = 1, int mismatch = 0, int open = -6, int extension = 0, int (*gap)(int, int, int) = penalty)
{
	return eval(first, second, match, mismatch, open, extension, gap);
}

int main1( )
{
	char one[ ] = "AGTATCGTAGCTGATCGTAGTAGC", two[ ] = "ATGACTAGTCGTCGATGCTACAC";//"AGACTAGTTAC", two[ ] = "CGAGACGT";
	vector<char> first(one, one + sizeof(one) / sizeof(char)), second(two, two + sizeof(two) / sizeof(char));
	cout << align(first, second) << endl;
	return 0;
}
