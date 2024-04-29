
#include "casino_guessing.h"
#include <cmath>

using namespace std;

CasinoGuessing::CasinoGuessing(int x) : points(x), difficulty(0), casinoNumber(0) {}

int CasinoGuessing::getDifficulty() {
	return difficulty;
}

// Set the difficulty level
void CasinoGuessing::setDifficulty(int x) {
	difficulty = x;
}

// Get a random number based on the difficulty
int CasinoGuessing::getCasinoNumber() {
	// Easy: 2
	// Normal: 4
	// Hard: 8
	// Extream: 16
	// Impossible: 32
	// rand() % 32 + 1 = 1 - 33
	int difficultyMultiplyer = pow(2, difficulty);
	//cout << "Difficulty Multiplyer: " << difficultyMultiplyer << endl;
	casinoNumber = rand() % difficultyMultiplyer + 1;
	cout << "\n\nControl Casino Number: " << casinoNumber << endl << endl;
	return casinoNumber;
}

// The user has won, add points
void CasinoGuessing::win()
{
	int newPoints = points + pow(2, difficulty);
	points = newPoints;
}

// The user lost, remove points
void CasinoGuessing::lose() {
	points -= 2;
}

// Get the number of points
int CasinoGuessing::getPoints()
{
	return points;
}