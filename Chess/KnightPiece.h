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
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
};

