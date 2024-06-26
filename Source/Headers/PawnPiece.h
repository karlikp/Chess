#include "Piece.h"

#pragma once
class PawnPiece: public Piece
{
	vector<string> board;
	int  number;
	char sign, letter;

public:

	PawnPiece(vector<string> board);
	~PawnPiece() = default;
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
	bool doubleStepIsEmpty();
	bool singleStepIsEmpty();
	void checkAttackScope();
	
};

