#include <iostream>
#include <vector>
#include <string>

#include "Background.h"
#include "functions.h"

char Background::tempSign = {};
vector <string> Background::board = {};

vector<string> Background::getBoard()
{
	return board;
}

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

void Background::setPiece(pair<char, int> coordinates)
{
	int rowIndex = 10 - coordinates.second;
	int columnIndex = 4 + (coordinates.first - int('A')) * 3;
	int signColumnIndex = columnIndex - 1;

	tempSign = board[rowIndex][signColumnIndex];
	startPieceValue = board[rowIndex][columnIndex] - int('0');

}

pair<char,int> Background::getBoardContent()
{
	pair<char, int> piece(tempSign, startPieceValue);
	//piece.first = pieceSign;
	//piece.second = pieceValue;
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
		currentPiece = new PawnPiece(board);
		break;
	case 2:
		currentPiece = new KnightPiece(board);
		break;
	case 3:
		currentPiece = new BishopPiece(board);
		break;
	case 4:
		currentPiece = new RookPiece(board);
		break;
	case 5:
		currentPiece = new QueenPiece(board);
		break;
	case 6:
		currentPiece = new KingPiece(board);
		break;
	}
	return currentPiece;
}



