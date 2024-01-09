#include "Piece.h"

#pragma once
class PawnPiece: public Piece
{
	vector<string> board;
	vector<pair<char, int>> tempMoveScope;
	int  number;
	char sign, letter;

public:

	PawnPiece(vector<string> board);
	~PawnPiece();
	virtual vector<pair<char, int>> getScope(pair<char, int> startPosition);
	virtual bool checkMoveAccess(pair<char, int> finishPosition);
	bool doubleStepIsEmpty();
	bool singleStepIsEmpty();
	void checkAttackScope();
	
};

