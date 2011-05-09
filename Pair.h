/*
 * Pair.h
 *
 *  Created on: May 3, 2011
 *      Author: doubleemms
 */

#ifndef PAIR_H_
#define PAIR_H_

#include <string>

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
		void printReport( );

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
