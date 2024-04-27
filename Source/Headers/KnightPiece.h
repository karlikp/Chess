#include "Piece.h"

#pragma once

class KnightPiece: public Piece
{

public:

	KnightPiece() = default;
	~KnightPiece() = default;
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
};

