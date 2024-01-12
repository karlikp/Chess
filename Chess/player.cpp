#include "Player.h"
#include "functions.h"


Player::Player()
{
	int white = 0;
	turnGuard = white;
}

Player::~Player()
{
}

pair<char, int> Player::getStartPosition()
{
	cout << "\nType in coordinate of your piece, which you're going to do a move"
		<< " (for example: D2) ";
	pair<char, int> checkPosition;
	char sign;
	do
	{
		checkPosition = getPosition();
	}while (not (checkPosition.second != 0) or not validationSign(checkPosition));

	return checkPosition;
}

void Player::changeTurn()
{
	int white = 0, black = 1;

	if (turnGuard == 1 or turnGuard == -1)
	{
		turnGuard = white;
		currentSign = ' ';
	}
	else
	{
		turnGuard = black;
		currentSign = '-';
	}
}

bool Player::validationSign(pair<char, int> coords)
{
	int rowIndex = 10 - coords.second;
	int columnIndex = 4 + (coords.first - int('A')) * 3;
	int signColumnIndex = columnIndex - 1;
	vector<string> board = Background::getBoard();

	if (board[rowIndex][signColumnIndex] == currentSign)
		return true;
	else
	{
		cout << "\nYour answer is wrong, please correct it: ";
		return false;
	}
}

bool Player::returnCheck()
{
	return check;
}
