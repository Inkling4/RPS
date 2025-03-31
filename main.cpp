#include "playerclass.h"
#include "genericheader.h"
#include <iostream>

//Creates instance of player class
Player Player0;

//Makes player pointer and points it to player 0
Player* Player0Ref = &Player0;


/*
 *This will be a terminal based game about playing a game of rock paper scissors.
 */

//Returns a random integer between parameters, including the min and max
int rng(int MinNumber, int MaxNumber)
{
	MaxNumber++;
	return rand() % (MaxNumber - MinNumber) + MinNumber;
}

//returns the hand you chose (r/p/s).
char chooseHand()
{
	using namespace std;
	char PlayerHand;
	bool PlayerHandChosen = false;
	//Inputs hand
	while (!PlayerHandChosen)
	{
		cout << "Rock, Paper, or Scissors? (r/p/s): ";
		cin >> PlayerHand;
		PlayerHand = tolower(PlayerHand);
		if (PlayerHand == 'r' || PlayerHand == 'p' || PlayerHand == 's')
		{
			PlayerHandChosen = true;
			system("cls");
		}
		else
		{
			cout << "\nInvalid input!\n";
			system("pause");
			//Clears terminal
			system("cls");
		}
	}
	return PlayerHand;
}

/*
*Compares hands of player and opponent,
*returns 0 if player wins, 1 if opponent wins, 2 if tied.
*Returns 3 if there is an invalid input.
*/
int battle(char player, char opponent)
{
	switch (player)
	{
	case 'r':
		switch (opponent)
		{
		case 'r':
			return 2;
		case 'p':
			return 1;
		case 's':
			return 0;
		default:
			return 3;
		}
	case 'p':
		switch (opponent)
		{
		case 'r':
			return 0;
		case 'p':
			return 2;
		case 's':
			return 1;
		default:
			return 3;
		}
	case 's':
		switch (opponent)
		{
		case 'r':
			return 1;
		case 'p':
			return 0;
		case 's':
			return 2;
		default:
			return 3;
		}

	default:
		return 3;
	}
}

//Returns r, p, or s randomly.
char opponentHandChoice()
{
	int OpponentHandRoll = rng(0, 2);

	switch (OpponentHandRoll)
	{
	case (0):
		return 'r';
		
	case (1):
		return 'p';
		break;
	case (2):
		return 's';
		break;
	default:
		std::cout << "ERR: Opponent Hand invalid";
		return 'e';
	}
}


//Plays a round of rock paper scissors. Returns true if you win
bool playGame()
{
	using namespace std;
	system("cls");
	//checks if it is a null pointer just in case
	if (Player0Ref != nullptr)
	{
		char PlayerHand = chooseHand();
		char OpponentHand = opponentHandChoice();

		//Does the battle. Very epic!
		int BattleResult = battle(PlayerHand, OpponentHand);
	switch (BattleResult)
	{
	case 0:
		return true;
	case 1:
		return false;
	case 2:
		//tba, this is a tie
		return true;
	case 3:
		cout << "wtf";
		return false;
	default:
		cout << "tf????";
		return false;
	}

		

		
	}
	else
	{
		cout << "ERR: Player 0 is a null pointer!\n";
		return false;
	}
}



int main()
{
	//Sets random seed
	srand(time(0));
	std::cout << "Get ready to play the greatest rock paper scissors tournament ever!\n";
	system("pause");

	if (playGame())
	{
		std::cout << "You win!";
	}
	else
	{
		std::cout << "You lose :c";
	}


	

	return 0;
}