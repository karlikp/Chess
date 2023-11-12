#include "player.h"

Player::Player(string kolor)
{
	if (kolor == "white")
		scope = { 1, 2, 3, 4, 5, 6 };
	else
		scope = { -1, -2, -3, -4, -5, -6 };
}

bool Player::return_check()
{
	return check;
}
