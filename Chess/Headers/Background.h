#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Player.h"

using namespace std;

class Background
{
	vector <string> intro;
	vector <string> rules;
	static vector <string> board;
	static int tempPieceValue, tempRowIndex, tempColumnIndex, tempSignColumnIndex;
	
public:
	static char tempSign;
	static vector <string> getBoard();
	Background();
	void showBoard();

	void showRules();
	static void setContainOfPosition(pair<char, int> position);
	static int getPieceValue();
	Piece* getPiece(int value);
	void move(pair<char, int> finalPosition);

	friend bool Piece::lackYourPiece(char letter, int number);
	friend bool occupiedPosition(char letter, int number);
	friend bool Player::validationSign(pair<char, int> coords);
	friend pair<char, int> Player::getStartPosition();
	friend class CheckValidation;
	
};

