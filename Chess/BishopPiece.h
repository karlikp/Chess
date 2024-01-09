#include "Piece.h"

#pragma once
class BishopPiece: public Piece
{

public:

	BishopPiece();
	~BishopPiece();
	virtual vector<pair<char, int>> getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
	
};

