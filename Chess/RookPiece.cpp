#include "RookPiece.h"
#include "functions.h"

RookPiece::RookPiece()
{
}

RookPiece::~RookPiece()
{
}

void RookPiece::getScope(pair<char, int> startPosition)
{
	vector<pair<int, int>> rookStep = { {1,0}, {0,-1}, {-1,0}, {0,1} };

	
	for (int i = 0; i < 4; i++)
	{
		char letter = startPosition.first;
		int number = startPosition.second;

		for (int j = 0; j < 7; j++)
		{
			letter = char(int(letter) + rookStep[i].first);
			number += rookStep[i].second;


			if (lackYourPiece(letter, number)
				and positionIncludeInBoard(letter, number))
			{
				currentMoveScope.push_back({ letter, number });
			}

			if (occupiedPosition(letter, number)
				or (not positionIncludeInBoard(letter, number)))
				break;
		}
	}
	if (not currentMoveScope.empty())
		showAccessPositions(currentMoveScope);
}

bool RookPiece::checkMoveAccess(pair<char, int> finishPosition)
{
	return 0;
}
