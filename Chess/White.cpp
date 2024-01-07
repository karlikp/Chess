#include "White.h"

White::White()
{
	int nextTurnBlack = 1;
	correctSign = ' ';
	setTurnCounter(nextTurnBlack);
}

White::~White()
{
}

//bool White::validation(pair<char, int> content)
//{
//	bool validResult = true;
//
//	if (correctSign != content.first)
//		validResult = false;
//
//	if (not (content.second >= 1 and content.second <= 6))
//		validResult = false;
//
//	return validResult;
//}

void White::finish()
{
	cout << "Player of black piece is winner, congratulation! \n";
}
