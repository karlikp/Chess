#include "Piece.h"

#pragma once
class BishopPiece: public Piece
{

public:

	BishopPiece() = default;
	~BishopPiece() = default;
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
	
};

