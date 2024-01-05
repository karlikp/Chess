#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Player.h"
#include "White.h"
#include "Black.h"

#include "Piece.h"
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
	vector <string> board;
	char pieceSign;
	int pieceValue;
	int turnCounter = 0;
	
	
public:

	Background();
	void showBoard();
	void showRules();
	void checkPiece(pair<char, int> coordinates);
	pair<char,int> getBoardContent();
	Player* getPlayer();
	Piece* getPiece(int value);
	
};

