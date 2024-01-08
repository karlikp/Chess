#include "Piece.h"

#pragma once
class QueenPiece : public Piece
{
	vector<pair<char, int>> moveScope;
	vector<string> board;

public:

	QueenPiece(vector<string> board);
	~QueenPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
};

