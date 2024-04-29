#pragma once

#ifndef CASINO_GUESSING_H
#define CASINO_GUESSING_H

#include <cstdlib>
#include <iostream>
#include <string>

class CasinoGuessing
{
private:
	int points;
	int difficulty;
	int casinoNumber;

public:
	// constructor
	CasinoGuessing(int x);	// constructor
	int getDifficulty();	// Get the difficulty level
	void setDifficulty(int x);	// Set the difficulty level
	int getCasinoNumber();	// Get a random number based on the difficulty
	void win();	// The user has won, add points
	void lose();	// The user lost, remove points
	int getPoints();	// Get the number of points
};

#endif // CASIO_GUESSING_H
