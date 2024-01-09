#include "KingPiece.h"
#include "functions.h"

KingPiece::KingPiece()
{
}

KingPiece::~KingPiece()
{
}

vector<pair<char, int>> KingPiece::getScope(pair<char, int> startPosition)
{
	vector<pair<char, int>> tempMoveScope;

	vector<pair<int, int>> kingStep = { {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1} };

	for (int i = 0; i < 8; i++)
	{
		char letter = char(int(startPosition.first) + kingStep[i].first);
		int number = (startPosition.second) + kingStep[i].second;

		if (lackYourPiece(letter, number)
			and positionIncludeInBoard(letter, number))
			tempMoveScope.push_back({ letter,number });
	}
	showAccessPositions(tempMoveScope);
	return tempMoveScope;
}

bool KingPiece::checkMoveAccess(pair<char, int> finishPosition)
{
	return 0;
}


