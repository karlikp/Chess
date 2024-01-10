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
		chessGround.showBoard();

		Player* person = getPlayer();

		pair<char, int> startPosition = getStartPosition();

		chessGround.setPiece(startPosition);

		Piece* currentPiece = chessGround.getPiece(chessGround.getBoardContent().second);

		currentPiece -> insertMoveScope( currentPiece->getScope(startPosition));

		
		pair<char, int> finalPosition = currentPiece->getFinalPosition();

		if (currentPiece->checkMoveAccess())
			chessGround.move(finalPosition);



		

		


	if (finish)
		person -> finish();


	delete person;
	delete currentPiece;

	} while (!finish);
}
	