/*
 * OOSD-PROG-3-DEMO.cpp
 *
 *  Created on: May 16, 2011
 *     Authors: Griffin DeJohn and Matt Morris
 */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Needleman_Wunsch.h"
#include "Pair.h"
#include "Sequence.h"
#include "Smith_Waterman.h"
#include "Substitution_Matrix.h"

using namespace std;

int main( )
{
	char order[4] = {'A', 'G', 'C', 'T'};

	int sub_matrix[4][4] =
	{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};

	Substitution_Matrix *sub = new Substitution_Matrix(order, sub_matrix);

	int penalty = -6;

	vector<Sequence *> data;

	ifstream file("sequence.fasta");

	if (file.is_open( ))
	{
		string temp, sequence, accession;
		while (file.good( ))
		{
			temp = sequence = accession = "";

			file.ignore(100, '>');
			file.ignore(13, '\n');

			getline(file, accession, '.');

			file.ignore(200, '\n');

			if (!file.eof( ))
			{
				while (file.peek( ) != '\n')
				{
					getline(file, temp);
					sequence += temp;
				}

				data.push_back(new Sequence(accession, sequence));
			}
			else
			{
				break;
			}
		}
	}

	file.close( );

	ofstream output("output.txt");

	string hr1 = "***************************************************************";
	string hr2 = "---------------------------------------------------------------";
	output << "Molecular epidemiology of HIV transmission in a dental practice" << endl;
	output << hr1 << endl;
	output << "Substitution Matrix" << endl;
	output << hr2 << endl;
	output << "  " << order[0] << " " << order[1] << " " << order[2] << " " << order[3] << endl;
	output << order[0] << " " << sub_matrix[0][0] << endl;
	output << order[1] << " " << sub_matrix[1][0] << " " << sub_matrix[1][1] << endl;
	output << order[2] << " " << sub_matrix[2][0] << " " << sub_matrix[2][1] << " " << sub_matrix[2][2] << endl;
	output << order[3] << " " << sub_matrix[3][0] << " " << sub_matrix[3][1] << " " << sub_matrix[3][2] << " " << sub_matrix[3][3] << endl;
	output << hr1 << endl;
	output << "Gap Penalty: " << penalty << endl;
	output << hr1 << endl;
	output << "Pairwise Alignment" << endl;

	for (unsigned int i = 0, j, k; i < data.size( ); i++)
	{
		for (j = i + 1; j < data.size( ); j++)
		{
			Pair *pair;

			output << hr1 << endl;
			output << "Top ---- " << data.at(i)->getAccession() << endl;
			output << "Bottom - " << data.at(j)->getAccession() << endl;
			output << hr2 << endl;

			Needleman_Wunsch *needleman = new Needleman_Wunsch(data.at(i), data.at(j), penalty, sub);
			pair = needleman->align( );
			output << "Needleman-Wunsch" << endl;
			output << hr2 << endl;
			output << pair->getA( ) << endl;

			for (k = 0; k < pair->getA( ).size( ); k++)
			{
				output << (pair->getA( ).at(k) == pair->getB( ).at(k) ? '|' : ' ');
			}

			output << endl << pair->getB( ) << endl << "Score: " << pair->getScore( ) << endl;

			Smith_Waterman *smith = new Smith_Waterman(data.at(i), data.at(j), penalty, sub);
			pair = smith->align( );
			output << hr2 << endl;
			output << "Smith-Waterman" << endl;
			output << hr2 << endl;
			output << pair->getA( ) << endl;

			for (k = 0; k < pair->getA( ).size( ); k++)
			{
				output << (pair->getA( ).at(k) == pair->getB( ).at(k) ? '|' : ' ');
			}

			output << endl << pair->getB( ) << endl << "Score: " << pair->getScore( ) << endl;
		}
	}

	output.close( );

	return 0;
}
