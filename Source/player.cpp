#include "Headers/Player.h"
#include "Headers/functions.h"
#include "Headers/Background.h"

char Player::currentSign = ' ';
int Player::turnGuard = 0;

Player::Player()
{
	white = 0;
	black = 1;
}

char Player::getCurrentSign()
{
	return currentSign;
}

void Player::setCurrentSign(char sign)
{
	currentSign = sign;
}

pair<char, int> Player::getStartPosition()
{
	cout << "\nWhich piece would you like to move with?"
			"\nType in coordinates the piece : ";
	pair<char, int> checkPosition;
	char pieceLetter;
	int counterAskAnswer = 0;
	do
	{
		counterAskAnswer++;
		if (counterAskAnswer > 1)
		{
			cout << "\nThe position which you selected doesn't contain your chess piece.";
			cout << "\nCorrect it: ";
		}
		checkPosition = getPosition();
		Background::setContainOfPosition(checkPosition);
		pieceLetter = Background::getPieceLetter();

	}while (not (pieceLetter != '0') or not validationSign(checkPosition));

	return checkPosition;
}

int Player::getTurnGuard()
{
	return turnGuard;
}

void Player::changeTurn()
{
	if (turnGuard == black or turnGuard == -1)
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

void Player::announcementTurn()
{
	if (turnGuard == 0)
		cout << "\n[White player turn]\n\n";
	else
		cout << "\n[Black player turn]\n\n";
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
		return false;
	}
}

void Player::end()
{
	if (turnGuard == 1)
		cout << "\n[Checkmate, congratulates the white player on his victory]";
	else
		cout << "\n[Checkmate, congratulates the black player on his victory]";
	cout << "\n\n";
}


