#include <iostream>
#include <vector>
#include <string>

#include "Headers/Background.h"
#include "Headers/functions.h"

#include "Headers/BishopPiece.h"
#include "Headers/QueenPiece.h"
#include "Headers/KingPiece.h"
#include "Headers/KnightPiece.h"
#include "Headers/PawnPiece.h"
#include "Headers/RookPiece.h"

char Background::tempSign = {};
char Background::tempPieceLetter = {};
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
	
	rules = readStringsFromFile("introduction.txt");
	coutStringVector(rules);
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
	tempPieceLetter = board[tempRowIndex][tempColumnIndex];

}

char Background::getPieceLetter()
{
	return char(tempPieceLetter);
}

Piece* Background::getPiece(char pieceValue)
{
	Piece* currentPiece = nullptr;
	switch (pieceValue)
	{
	case 'P':
		currentPiece = new PawnPiece(board);
		break;
	case 'H':
		currentPiece = new KnightPiece;
		break;
	case 'B':
		currentPiece = new BishopPiece;
		break;
	case 'R':
		currentPiece = new RookPiece;
		break;
	case 'Q':
		currentPiece = new QueenPiece;
		break;
	case 'K':
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

	board[rowIndex][columnIndex] = tempPieceLetter;
	board[rowIndex][signColumnIndex] = tempSign;

	board[tempRowIndex][tempColumnIndex] = '0';
	board[tempRowIndex][tempSignColumnIndex] = ' ';
}


