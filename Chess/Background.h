#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "functions.h"
#include "Player.h"
#include "White.h"
#include "Black.h"


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
	
	//static char startSign;
	int startPieceValue;
	int turnCounter = 0;
	
	
public:
	static char tempSign;
	static vector <string> getBoard();
	Background();
	void showBoard();

	void showRules();
	void setPiece(pair<char, int> coordinates);
	pair<char,int> getBoardContent();
	Player* getPlayer();
	Piece* getPiece(int value);
	//static char getStartSign();

	friend bool Piece::lackYourPiece(char letter, int number);
	
	
};

