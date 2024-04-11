#include "Piece.h"

#pragma once
class RookPiece: public Piece
{

public:

	RookPiece();
	~RookPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
};

