#include "Player.h"

//redundant

#pragma once
class Black : public Player
{
	

public:

	Black();
	~Black();

	virtual bool validation(pair<char, int> content);
	virtual void finish();

};

