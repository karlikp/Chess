#pragma once

#include <vector>

#include "Piece.h"
#include "Background.h"

class CheckValidation
{
	Piece* currentPiece;
	Background* chessGround;

	//unordered_map <pair<char, int>, vector<pair<char, int>>>
	//	positionWhitePiecesWithScope, positionBlackPiecesWithScope;
	vector<string> board;
	pair<char, int> blackKing, whiteKing;

	bool check;
	int turnGuard, white, black;
	
public:

	CheckValidation(Background* chessGround);
	~CheckValidation();
	void updateBoard();
	void updateTurnGuard();
	void InitialValidationScope(pair<char, int> currentPosition);
	void checkControl();
	void changeKingPosition(pair<char, int> newPosition);
};

