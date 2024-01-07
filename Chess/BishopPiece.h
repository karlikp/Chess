#include "Piece.h"

#pragma once
class BishopPiece: public Piece
{
	vector<pair<char, int>> moveScope;
	vector<string> board;

public:

	BishopPiece(vector<string> board);
	~BishopPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual void checkMovePossibility(pair<char, int> finishPosition);
	
};

