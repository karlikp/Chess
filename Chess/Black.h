#include "Player.h"

#pragma once
class Black : public Player
{
	char correctSign;

public:

	Black();
	~Black();

	virtual bool validation(pair<char, int> content);
	virtual void finish();

};

