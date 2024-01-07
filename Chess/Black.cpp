#include "Black.h"

Black::Black()
{
	int nextTurnWhite = 0;
	correctSign = '-';
	setTurnCounter(nextTurnWhite);
}

Black::~Black()
{
}

bool Black::validation(pair<char, int> content)
{
	bool validResult = true;

	if (correctSign != content.first)
		validResult = false;

	if (not (content.second >= 1 and content.second <= 6))
		validResult = false;

	return validResult;
}

void Black::finish()
{
	cout << "Player of black piece is winner, congratulation! \n";
}
