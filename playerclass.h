#pragma once


class Player
{
private:
	//private variables
	int wins;
	int losses;
	int money;
public:
	//public functions
	Player();
	int getWins();
	int getLosses();
	int getMoney();
	void win();
	void lose();
	void obtainMoney(int change);
};
