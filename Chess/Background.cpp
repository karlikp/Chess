#include <iostream>
#include <vector>
#include <string>

#include "Background.h"
#include "functions.h"

Background::Background()
{
	vector <string> intro = readStringsFromFile("introduction.txt");
	coutStringVector(intro);
	board = readStringsFromFile("chessBoard.txt");
	coutStringVector(board);
	rules = readStringsFromFile("rules.txt");
	coutStringVector(rules);
}

void Background::showBoard()
{
	coutStringVector(board);
}

void Background::showRules()
{
	coutStringVector(rules);
}

void Background::checkPiece(pair<char, int> coordinates)
{
	int vectorIndex = 10 - coordinates.second;
	int stringIndex = 4 + (coordinates.first - 65) * 3;
	int signStringIndex = stringIndex - 1;

	pieceSign = board[vectorIndex][signStringIndex];
	pieceValue = board[vectorIndex][stringIndex] - 48;

}

pair<char,int> Background::getBoardContent()
{
	pair<char, int> piece;
	piece.first = pieceSign;
	piece.second = pieceValue;
	return piece;
}

Player* Background::getPlayer()
{
	Player* person = nullptr;
	if (turnCounter == 0)
	{
		person = new White;
		turnCounter++;
	}
	else
	{
		person = new Black;
		turnCounter--;
	}
	return person;
}

Piece* Background::getPiece(int value)
{
	Piece* currentPiece = nullptr;
	switch (value)
	{
	case 1:
		currentPiece = new PawnPiece;
		break;
	case 2:
		currentPiece = new KnightPiece;
		break;
	case 3:
		currentPiece = new BishopPiece;
		break;
	case 4:
		currentPiece = new RookPiece;
		break;
	case 5:
		currentPiece = new QueenPiece;
		break;
	case 6:
		currentPiece = new KingPiece;
		break;
	}
	return currentPiece;
}

