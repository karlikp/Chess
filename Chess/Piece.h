#include <iostream>
#include <vector>


using namespace std;

#pragma once
class Piece
{
	vector <string> board;
	vector<pair<char, int>> moveScope;



public:
	Piece();
	~Piece();
	void insertMoveScope(vector<pair<char, int>> tempMoveScope);
	virtual vector<pair<char, int>> getScope(pair<char, int> startPosition) = 0;
	virtual bool checkMoveAccess(pair<char, int> finishPosition) = 0;
	bool lackYourPiece(char letter, int number);
	bool scopeIsEnough(pair<char, int> finishPosition);

};

