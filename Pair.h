/*
 * Pair.h
 *
 *  Created on: May 3, 2011
 *     Authors: Griffin DeJohn and Matt Morris
 */

#ifndef PAIR_H_
#define PAIR_H_

#include <string>
#include <iostream>

using namespace std;

class Pair
{
	public:
		Pair( );
		virtual ~Pair( );

		string getA( );
		string getB( );
		int getMatches( );
		int getScore( );
		void writeReport(ofstream &);

		void insertA(char a);
		void insertB(char b);

		void setMatches(int);
		void setScore(int x);

	private:
		string SequenceA;
		string SequenceB;

		int matches;
		int score;
};

#endif /* PAIR_H_ */
