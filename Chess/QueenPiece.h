#include "Piece.h"

#pragma once
class QueenPiece : public Piece
{

public:

	QueenPiece();
	~QueenPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
};

