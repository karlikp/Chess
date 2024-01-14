#include <iostream>
#include <vector>
#include <string>

#include "Background.h"
#include "functions.h"

#include "BishopPiece.h"
#include "QueenPiece.h"
#include "KingPiece.h"
#include "KnightPiece.h"
#include "PawnPiece.h"
#include "RookPiece.h"

char Background::tempSign = {};
int Background::tempPieceValue = {};
int Background::tempRowIndex = {};
int Background::tempColumnIndex = {};
int Background::tempSignColumnIndex = {};

vector <string> Background::board = {};

vector<string> Background::getBoard()
{
	return board;
}

Background::Background()
{
	vector <string> intro = readStringsFromFile("introduction.txt");
	coutStringVector(intro);
	rules = readStringsFromFile("instruction.txt");
	coutStringVector(rules);
	cout << "[Start the game]";
	board = readStringsFromFile("chessBoard.txt");
}

void Background::showBoard()
{
	coutStringVector(board);
}

void Background::showRules()
{
	coutStringVector(rules);
}

void Background::setContainOfPosition(pair<char, int> coordinates)
{
	tempRowIndex = 10 - coordinates.second;
	tempColumnIndex = 4 + (coordinates.first - int('A')) * 3;
	tempSignColumnIndex = tempColumnIndex - 1;

	tempSign = board[tempRowIndex][tempSignColumnIndex];
	tempPieceValue = board[tempRowIndex][tempColumnIndex] - int('0');

}

int Background::getPieceValue()
{
	return tempPieceValue;
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

	board[rowIndex][columnIndex] = char(tempPieceValue + int('0'));
	board[rowIndex][signColumnIndex] = tempSign;

	board[tempRowIndex][tempColumnIndex] = '0';
	board[tempRowIndex][tempSignColumnIndex] = ' ';
}


