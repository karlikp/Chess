#include "Piece.h"

#pragma once

class KnightPiece: public Piece
{
	vector<pair<char, int>> moveScope;
	vector<string> board;

public:

	KnightPiece(vector<string> board);
	~KnightPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual void checkMovePossibility(pair<char, int> finishPosition);
};

