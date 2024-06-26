#include "Headers/QueenPiece.h"
#include "Headers/functions.h"

void QueenPiece::getScope(pair<char, int> startPosition)
{
	vector<pair<int, int>> bishopStep = { {1,1}, {1,-1}, {-1,-1}, {-1,1} };

	for (int i = 0; i < 4; i++)
	{
		char letter = startPosition.first;
		int number = startPosition.second;

		for (int j = 0; j < 7; j++)
		{
			letter = char(int(letter) + bishopStep[i].first);
			number += bishopStep[i].second;


			if (lackYourPiece(letter, number)
				and positionIncludeInBoard(letter, number))
			{
				currentMoveScope.insert({ letter, number });
			}

			if (occupiedPosition(letter, number))
				break;
		}
	}
	vector<pair<int, int>> rookStep = { {1,0}, {0,-1}, {-1,0}, {0,1} };
	{
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
					currentMoveScope.insert({ letter, number });
				}

				if (occupiedPosition(letter, number)
					or (not positionIncludeInBoard(letter, number)))
					break;
			}
		}
	}
}

bool QueenPiece::checkMoveAccess(pair<char, int> finishPosition)
{
	return 0;
}
