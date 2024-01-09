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

Piece* Background::getPiece(int value)
{
	Piece* currentPiece = nullptr;
	switch (value)
	{
	case 1:
		currentPiece = new PawnPiece(board);
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



