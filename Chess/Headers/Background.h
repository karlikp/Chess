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
	static int tempRowIndex, tempColumnIndex, tempSignColumnIndex;
	static char tempPieceLetter;
	
public:
	static char tempSign;
	static vector <string> getBoard();
	Background();
	void showBoard();

	void showRules();
	static void setContainOfPosition(pair<char, int> position);
	static char getPieceLetter();
	Piece* getPiece(char value);
	void move(pair<char, int> finalPosition);

	friend bool Piece::lackYourPiece(char letter, int number);
	friend bool occupiedPosition(char letter, int number);
	friend bool Player::validationSign(pair<char, int> coords);
	friend pair<char, int> Player::getStartPosition();
	friend class CheckValidation;
	
};

