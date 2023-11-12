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

	bool return_check();
};

