#include <iostream>
#include <vector>
#include <string>

#include "functions.h"
#include "Background.h"
#include "Piece.h"

using namespace std;

int main()
{

	Background chessGround;


	bool finish = false;
	do
	{

		Player* person = chessGround.getPlayer();
	
		chessGround.checkPiece(setStartPosition());

		Piece* currentPiece = chessGround.getPiece(chessGround.getBoardContent().second);

		chessGround.checkPiece(setFinishPosition());


	if (finish)
		person -> finish();


	delete person;
	delete currentPiece;
	} while (!finish);
}
	