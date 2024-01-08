#include "KingPiece.h"
#include "functions.h"

KingPiece::KingPiece(vector<string> table)
{
}

KingPiece::~KingPiece()
{
}

void KingPiece::getScope(pair<char, int> startPosition)
{

	vector<pair<int, int>> kingStep = { {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1} };

	for (int i = 0; i < 8; i++)
	{
		char letter = char(int(startPosition.first) + kingStep[i].first);
		int number = (startPosition.second) + kingStep[i].second;

		if(lackYourPiece(letter, number) 
			and positionIncludeInBoard(letter, number))
		moveScope.push_back({ letter,number });
	}
}

bool KingPiece::checkMoveAccess(pair<char, int> finishPosition)
{
}


