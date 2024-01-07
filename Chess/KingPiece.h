#include "Piece.h"

#pragma once
class KingPiece: public Piece
{
	bool Check = false;
	vector<pair<char, int>> moveScope;
	vector<string> board;

public:

	KingPiece(vector<string> board);
	~KingPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual void checkMovePossibility(pair<char, int> finishPosition);
};

