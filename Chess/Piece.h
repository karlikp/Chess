#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Piece
{
	vector <string> board;
	int numberCoord;
	char letterCoord;

public:
	static vector<pair<char, int>> currentMoveScope;
	
	Piece();
	~Piece();
	virtual void getScope(pair<char, int> startPosition) = 0;
	pair<char, int> getFinalPosition();
	bool moveValidation();
	bool scopeValidation();
	bool lackCheck();
	bool lackYourPiece(char letter, int number);
	bool checkEmptinessScope();

	friend class CheckValidation;
	
	

};

