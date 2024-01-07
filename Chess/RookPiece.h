#include "Piece.h"

#pragma once
class RookPiece: public Piece
{
	vector<pair<char, int>> moveScope;
	vector<string> board;

public:

	RookPiece(vector<string> board);
	~RookPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual void checkMovePossibility(pair<char, int> finishPosition);
};

