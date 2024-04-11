#pragma once

#include <iostream>
#include <vector>

#include "Piece.h"


using namespace std;

class Player
{
	
	static int turnGuard;
	int white, black;
	static char currentSign;

public:

	Player();
	~Player() = default;
	static char getCurrentSign();
	static void setCurrentSign(char sign);
	pair<char, int> getStartPosition();
	static int getTurnGuard();
	void changeTurn();
	void announcementTurn();
	bool validationSign(pair<char, int> coords);
	void end();

	friend bool Piece::lackYourPiece(char letter, int number);
	friend class CheckValidation;
	
};

