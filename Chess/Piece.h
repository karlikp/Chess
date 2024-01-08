#include <iostream>
#include <vector>


using namespace std;

#pragma once
class Piece
{
	vector <string> board;
public:
	Piece();
	Piece(vector<string> board);
	~Piece();
	virtual void getScope(pair<char, int> startPosition) = 0;
	virtual bool checkMoveAccess(pair<char, int> finishPosition) = 0;
	void checkDetection();
	bool lackYourPiece(char letter, int number);
	/*bool checkAccessFinishPosition (pair<char,int> finishPosition)*/

};

