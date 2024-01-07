#include<iostream>
#include<vector>
using namespace std;

#include "KnightPiece.h"
#include "functions.h"

KnightPiece::KnightPiece(vector<string> table)
{
}

KnightPiece::~KnightPiece()
{
}

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
			moveScope.push_back({ letter, number });
	}
	for (auto i : moveScope)
	{
		cout << "[" << i.first << "," << i.second << "]";
	}
}

void KnightPiece::checkMovePossibility(pair<char, int> finishPosition)
{
}
