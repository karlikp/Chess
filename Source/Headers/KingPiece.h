#include "Piece.h"

#pragma once
class KingPiece: public Piece
{
	bool Check = false;

public:

	KingPiece() = default;
	~KingPiece() = default;
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
};

