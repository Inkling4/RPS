#include "playerclass.h"

//player constructor, sets default values
Player::Player()
{
	wins = 0;
	losses = 0;
	money = 0;
}

//Returns the amount of wins the player has
int Player::getWins()
{
	return wins;
}

//Returns amount of losses the player has
int Player::getLosses()
{
	return losses;
}

//Returns the player's money amount
int Player::getMoney()
{
	return money;
}

//Changes the player's current amount of money by the parameter specified
void Player::obtainMoney(int change)
{
	money += change;
}

//Adds a win to the player
void Player::win()
{
	wins++;
}

//Adds a loss to the player
void Player::lose()
{
	losses++;
}



