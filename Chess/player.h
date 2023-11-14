#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Player
{
	vector <int> scope;
	bool check = false;

public:

	Player(string kolor);
	bool check_scope(int piece_number);
	bool return_check();
};

