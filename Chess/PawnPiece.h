#include "Piece.h"

#pragma once
class PawnPiece: public Piece
{
	vector<string> board;
	vector<pair<char, int>> moveScope;
	int  number;
	char sign, letter;

public:

	PawnPiece(vector<string> board);
	~PawnPiece();
	virtual void getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
	bool doubleStepIsEmpty();
	bool singleStepIsEmpty();
	void checkAttackScope();
	
};

