#include "Player.h"

#pragma once
class White : public Player
{
	char correctSign;

public:

	White();
	~White();

	virtual bool validation(pair<char, int> content);
	virtual void finish();
};
