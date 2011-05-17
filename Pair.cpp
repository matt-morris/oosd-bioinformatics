/*
 * Pair.cpp
 *
 *  Created on: May 3, 2011
 *     Authors: Griffin DeJohn and Matt Morris
 */

#include "Pair.h"
#include <iostream>
#include <string>

using namespace std;

Pair::Pair( )
{
	SequenceA = "";
	SequenceB = "";
}

string Pair::getA( )
{
	return SequenceA;
}

string Pair::getB( )
{
	return SequenceB;
}

int Pair::getMatches( )
{
	return matches;
}

int Pair::getScore( )
{
	return score;
}

void Pair::insertA(char a)
{
	SequenceA.insert(0, sizeof(char), a);
}

void Pair::insertB(char b)
{
	SequenceB.insert(0, sizeof(char), b);
}

void Pair::setMatches(int x)
{
	matches = x;
}

void Pair::setScore(int x)
{
	score = x;
}

Pair::~Pair( )
{

}
