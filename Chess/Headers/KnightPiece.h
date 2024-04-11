#include "Piece.h"

#pragma once

class KnightPiece: public Piece
{

public:

	KnightPiece();
	~KnightPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
};

