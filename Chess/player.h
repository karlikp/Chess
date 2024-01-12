#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Player
{
	bool check = false; //I needn't know which king is checking, so te variable should be in base class
	int turnGuard;
	char currentSign = ' ';
	pair<char, int> blackKing{ 'E', 1 }, whiteKing{ 'A', 1 };

	

public:

	Player();
	~Player();
;
	pair<char, int> getStartPosition();
	bool validationSign(pair<char, int> coords);
	void changeTurn();

	bool returnCheck();
	void finish();

};

