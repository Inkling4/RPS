#include "playerclass.h"
#include "genericheader.h"
#include <iostream>
#include <string>

//Instance of Player class
Player Player0;

//Player pointer that points to player 0
Player* Player0Ref = &Player0;


/*
 *This will be a terminal based game about playing a game of rock paper scissors.
 */

int rng(int MinNumber, int MaxNumber)
{
	MaxNumber++;
	return rand() % (MaxNumber - MinNumber) + MinNumber;
}

//asks you to choose a hand, and returns the hand you chose (r/p/s).
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
*Converts input char to the full word for the hand
*For example, input 'r' returns "rock"
*returns "error" on invalid input
*/
std::string charToStringRPS(char RPSHand)
{
	RPSHand = tolower(RPSHand);

	switch (RPSHand)
	{
	case 'r':
		return "rock";
	case 'p':
		return "paper";
	case 's':
		return "scissors";
	default:
		std::cout << "In function charToStringRPS: Invalid input!";
		return "error";
	}
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
char randomHandChoice()
{
	int OpponentHandRoll = rng(0, 2);

	switch (OpponentHandRoll)
	{
	case (0):
		return 'r';
		
	case (1):
		return 'p';
	case (2):
		return 's';
	default:
		std::cout << "ERR: Opponent Hand invalid\n";
		return 'e';
	}
}

//Plays a round of rock paper scissors. Returns true if you win
bool playGame()
{
	using namespace std;
	
		bool InfiniteLoopLmao = false;

		while (!InfiniteLoopLmao)
		{
			//Clears terminal
			system("cls");
			char PlayerHand = chooseHand();
			char OpponentHand = randomHandChoice();
			system("cls");

			string OpponentChoiceString = charToStringRPS(OpponentHand);

			cout << "Rock Paper Scissors!\nYour opponent chose " << OpponentChoiceString << ".\n";

			//Does the battle. Very epic!
			int BattleResult = battle(PlayerHand, OpponentHand);
			//Switch statement that checks the result
			switch (BattleResult)
			{
			case 0:
				cout << "You win!\n";
				return true;
			case 1:
				cout << "You lost.\n";
				return false;
			case 2:
				cout << "It's a tie!\n";
				system("pause");
				break;
			case 3:
				cout << "wtf\n";
				system("pause");
				break;
			default:
				cout << "tf????\n";
				system("pause");
				break;
			}
		}
	

}

bool askToPlayAgain()
{
	using namespace std;
	char Answer;
	bool InfiniteLoopLmao = false;

	while (!InfiniteLoopLmao)
	{
		cout << "Do you want to play another round? (y/n): ";
		cin >> Answer;
		Answer = tolower(Answer);
		switch (Answer)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			cout << "\nPlease use y or n.\n";
			break;
		}
	}
	return true;
}

int main()
{
	//Sets random seed
	srand(time(0));
	bool HasGameEnded = false;

	//checks if player0ref is a null pointer just in case
	if (Player0Ref != nullptr)
	{
		std::cout << "Get ready to play the greatest rock paper scissors tournament ever!\n";
		system("pause");

		while (!HasGameEnded)
		{
			if (playGame())
			{
				system("pause");
				system("cls");
				Player0Ref->win();
			}
			else
			{
				system("pause");
				system("cls");
				Player0Ref->lose();
			}
				
			std::cout << "You now have " << Player0Ref->getWins() << " wins, and " << Player0Ref->getLosses() << " losses.\n";
			if (!askToPlayAgain())
			{
				HasGameEnded = true;
			}

		}
	}
	else
	{
		std::cout << "ERR: Player 0 is a null pointer!\n";
		return 1;
	}

	return 0;
}