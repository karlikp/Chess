#pragma once

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Piece
{
	vector <string> board;
	int numberCoord;
	char letterCoord;

public:
	static set<pair<char, int>> currentMoveScope;
	
	Piece();
	~Piece();
	virtual void getScope(pair<char, int> startPosition) = 0;
	pair<char, int> getFinalPosition();
	bool scopeValidation();
	bool lackYourPiece(char letter, int number);
	bool checkEmptinessScope();

	friend class CheckValidation;
	friend void showAccessPositions();

	
	

};

