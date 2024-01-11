#include "Player.h"
#include "functions.h"

int Player::turnCounter = -1;

Player::Player()
{
	if (turnCounter == 1 or turnCounter == -1)
	{
		turnCounter = 0;
		currentSign = ' ';
	}
	else
	{
		turnCounter = 1;
		currentSign = '-';
	}
}

Player::~Player()
{
}

int Player::getTurnCounter()
{
	return turnCounter;
}

pair<char, int> setStartPosition()
{
	cout << "\nType in coordinate of your piece, which you're going to do a move"
		<< " (for example: D2) ";
	pair<char, int> checkCoords;
	char sign;
	do
	{
		checkCoords = getPosition();
		sign = getSign(checkCoords);
	} while (checkCoords.second != 0 and sign);

	return checkCoords;
}

bool validationSign(pair<char, int> coords)
{
	int rowIndex = 10 - coords.second;
	int columnIndex = 4 + (coords.first - int('A')) * 3;
	int signColumnIndex = columnIndex - 1;
	vector<string> board = Background::getBoard();

	if (board[rowIndex][signColumnIndex] == currentSign)
		return true;
	else
		return false;
}

bool Player::returnCheck()
{
	return check;
}
