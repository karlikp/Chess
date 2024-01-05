#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Player
{
	bool check = false; //I needn't know which king is checking, so te variable should be in base class

public:

	Player();
	~Player();


	//virtual bool check_scope(int piece_number);

	virtual bool returnCheck();
	virtual bool validation(pair<char,int> current_piece) = 0;
	virtual void finish() = 0;

};

