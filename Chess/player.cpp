#include "player.h"

Player::Player(string kolor)
{
	if (kolor == "white piece")
		scope = { 1, 2, 3, 4, 5, 6 };
	else
		scope = { -1, -2, -3, -4, -5, -6 };
}

bool Player::return_check()
{
	return check;
}

bool Player::check_scope(int piece_number)
{
	for (int i : scope)
	{
		if (piece_number == i)
			return true;
	}
	return false;
}

