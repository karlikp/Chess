#include <iostream>
#include <vector>
#include <string>

#include "Background.h"
#include "functions.h"

char Background::tempSign = {};
int Background::pieceValue = {};
int Background::startRowIndex = {};
int Background::startColumnIndex = {};
int Background::startSignColumnIndex = {};

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
	//coutStringVector(board);
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
	startRowIndex = 10 - coordinates.second;
	startColumnIndex = 4 + (coordinates.first - int('A')) * 3;
	startSignColumnIndex = startColumnIndex - 1;

	tempSign = board[startRowIndex][startSignColumnIndex];
	pieceValue = board[startRowIndex][startColumnIndex] - int('0');

}

int Background::getPieceValue()
{
	return pieceValue;
}

Piece* Background::getPiece(int pieceValue)
{
	Piece* currentPiece = nullptr;
	switch (pieceValue)
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

void Background::move(pair<char, int> finalPosition)
{
	int letterCoord = finalPosition.first;
	char numberCoord = finalPosition.second;

	int rowIndex = 10 - numberCoord;
	int columnIndex = 4 + (letterCoord - int('A')) * 3;
	int signColumnIndex = columnIndex - 1;

	board[rowIndex][columnIndex] = char(pieceValue + int('0'));
	board[rowIndex][signColumnIndex] = tempSign;

	board[startRowIndex][startColumnIndex] = '0';
	board[startRowIndex][startSignColumnIndex] = ' ';
}


