#include "KingPiece.h"

KingPiece::KingPiece(vector<string> table)
{
}

KingPiece::~KingPiece()
{
}

void KingPiece::getScope(pair<char, int> startPosition)
{

	vector<pair<int, int>> neighbourhood = { {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1} };

	for (int i = 0; i < 8; i++)
	{
		char letter = char(int(startPosition.first) + neighbourhood[i].first);
		int number = (startPosition.second) + neighbourhood[i].second;
		moveScope.push_back({ letter,number });
	}
}

void KingPiece::checkMovePossibility(pair<char, int> finishPosition)
{
}


