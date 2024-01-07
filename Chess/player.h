#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Player
{
	bool check = false; //I needn't know which king is checking, so te variable should be in base class
	static int turnCounter;
public:

	Player();
	~Player();

	static int getTurnCounter();
	
	virtual bool returnCheck();
	
	virtual void finish() = 0;

	friend Player* getPlayer();

	static void setTurnCounter(int turnNumber);

};

