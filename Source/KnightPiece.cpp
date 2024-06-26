#include<iostream>
#include<vector>
using namespace std;

#include "Headers/KnightPiece.h"
#include "Headers/functions.h"

void KnightPiece::getScope(pair<char, int> startPosition)
{
	vector<pair<int, int>> knightStep
	{ {2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1} };

	for (int i = 0; i < 8; i++)
	{
		char letter = startPosition.first;
		int number = startPosition.second;

		letter = char(int(letter) + knightStep[i].first);
		number += knightStep[i].second;
		
		if (lackYourPiece(letter, number)
			and positionIncludeInBoard(letter, number))
			currentMoveScope.insert({ letter, number });
	}
}

bool KnightPiece::checkMoveAccess(pair<char, int> finishPosition)
{
	return 0;
}
