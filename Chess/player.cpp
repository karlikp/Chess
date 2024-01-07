#include "Player.h"


int Player::turnCounter = 0;

Player::Player()
{
}

Player::~Player()
{
}

int Player::getTurnCounter()
{
	return turnCounter;
}

bool Player::returnCheck()
{
	return check;
}

void Player::setTurnCounter(int turnNumber)
{
	turnCounter = turnNumber;
}
