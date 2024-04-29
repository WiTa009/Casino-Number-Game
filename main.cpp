

#include "casino_guessing.h"

#include <iostream>
#include <limits>


using namespace std;


static int validInput(int numberArray[6])
{
	int x;
	while(1)
	{
		try {
			// check if difficulty is an integer
			if (!(cin >> x))
				throw invalid_argument("Invalid input. Please enter an integer");

			//bool a = find(begin(numberArray), end(numberArray), x);
			for (int i = 0; i < sizeof(numberArray); i++) {
				if (x == numberArray[i])
				{
					return x;
				}
			}
			throw invalid_argument("Invalid input. Please choose from the difficulty options");
			
			//if (!(find(begin(numberArray), end(numberArray), x))) //(x in numberArray))	//(x == 1 or x == 2 or x == 3 or x == 4 or x == 5))
			//	throw invalid_argument("Invalid input. Please choose from the difficulty options");
		}
		catch (const invalid_argument& e)
		{
			cerr << e.what() << endl;
			std::cin.clear(); // Clear the fail state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
			continue;
		}

		return x;
	}

}


int chooseDifficulty(CasinoGuessing& casino)
{
	int x;
	string difficultyOptions[5] = { "Easy", "Normal", "Hard", "Extream", "Impossible" };
	int difficultyNumbers[6] = { 1,2,3,4,5,0 };
	string menu = "Choose difficulty:\n"
		"1: Easy\n"
		"2: Normal\n"
		"3. Hard\n"
		"4. Extream\n"
		"5. Impossible\n"
		"0. Exit\n";
	cout << menu << endl;

	x = validInput(difficultyNumbers);
	if (x == 0)
	{
		cout << endl << "Exiting" << endl << endl;
		return x;
	}
	cout << "Difficulty Choosen: " << difficultyOptions[x - 1] << endl << endl;
	casino.setDifficulty(x);
	return x;
}

void playCasino(CasinoGuessing& casino)
{	
	string difficultyOptions[5] = { "Easy", "Normal", "Hard", "Extream", "Impossible" };

	cout << "\nWelcome to the Casino: Guess The Number!" << endl;
	cout << "The difficuly is " << difficultyOptions[casino.getDifficulty()-1] << endl << endl;

	int start = 1;
	int end = pow(2, casino.getDifficulty()) + 1;

	int guessNumber;
	int casinoNumber;

	while (1)
	{
		cout << "Make a guess between " << start << " and " << end << endl;
		cout << "Enter '0' to exit." << endl;

		try {
			// Take the user guess
			cout << "Guess number: ";
			if (!(cin >> guessNumber))
				throw invalid_argument("Invalid input. Please enter an integer");
		}
		catch (const invalid_argument& e) {
			cerr << e.what() << endl;
			std::cin.clear(); // Clear the fail state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the invalid input
			continue;
		}

		// Check If exit or not
		if (guessNumber == 0)
		{
			cout << "Returning to difficulty selection!" << endl << endl;
			break;
		}
		// Check if guess matches casino number
		else {
			// Get Casino Number
			casinoNumber = casino.getCasinoNumber();

			if (guessNumber == casinoNumber)
			{
				cout << "You'r guess was right!" << endl;
				cout << "You win" << endl;
				casino.win();

				cout << endl << "You won some points! New point balance: " << casino.getPoints() << endl;;
			}
			else {
				cout << "You'r guess was wrong! The right number was: " << casinoNumber << endl;
				cout << "You lose" << endl;
				casino.lose();

				cout << endl << "You lost some points! New point balance: " << casino.getPoints() << endl;;
			}

		}


	}
}

void game(CasinoGuessing& casino)
{
	while (1)
	{
		// Choose the difficulty
		// Difficulty is set inside the casino class using "Pass by Refernece"
		int a = chooseDifficulty(casino);

		if (a == 0)
			break;

		playCasino(casino);

	}
}


int main()
{
	// Seed
	srand((unsigned)time(NULL));

	// Init the Casino
	CasinoGuessing casino(100);

	// Introduction Message
	string intro = "Welcome to the Casino Number Guessing Game\n"
		"In this game you will guess a number and if you guess the right number,\n"
		"you will win some money.";

	cout << intro << endl;


	// Load the game
	game(casino);

	return 0;
}