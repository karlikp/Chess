#include <iostream>
#include <vector>


using namespace std;

#pragma once
class Piece
{
	vector <string> board;
	vector<pair<char, int>> moveScope;
	int numberCoord;
	char letterCoord;


public:
	Piece();
	~Piece();
	//void insertMoveScope(vector<pair<char, int>> tempMoveScope);
	virtual vector<pair<char, int>> getScope(pair<char, int> startPosition) = 0;

	pair<char, int> getFinalPosition();
	bool moveValidation();
	bool scopeValidation();
	bool lackCheck();
	bool lackYourPiece(char letter, int number);
	bool checkEmptinessScope();
	
	

};

