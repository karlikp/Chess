#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "functions.h"
#include "Player.h"

#include "BishopPiece.h"
#include "QueenPiece.h"
#include "KingPiece.h"
#include "KnightPiece.h"
#include "PawnPiece.h"
#include "RookPiece.h"


using namespace std;

class Background
{
	vector <string> intro;
	vector <string> rules;
	static vector <string> board;
	
	int pieceValue, startRowIndex, startColumnIndex, startSignColumnIndex;
	/*int turnCounter = 0*/;
	
public:
	static char tempSign;
	static vector <string> getBoard();
	Background();
	void showBoard();

	void showRules();
	void setPiece(pair<char, int> coordinates);
	int getPieceValue();
	Piece* getPiece(int value);
	void move(pair<char, int> finalPosition);

	friend bool Piece::lackYourPiece(char letter, int number);
	friend bool occupiedPosition(char letter, int number);
	friend bool Player::validationSign(pair<char, int> coords);

	
};

