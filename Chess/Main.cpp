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
	Player person;

	bool finish = false;
	do
	{
		chessGround.showBoard();
		pair<char, int> startPosition;
		Piece* currentPiece;
		do
		{
			startPosition = person.getStartPosition();

			chessGround.setPiece(startPosition);

			currentPiece = chessGround.getPiece(chessGround.getPieceValue());

			currentPiece->getScope(startPosition);

		} while (currentPiece->checkEmptinessScope());


			

	//		currentPiece->insertMoveScope(currentPiece->getScope(startPosition));
		
		
		pair<char, int> finalPosition = currentPiece->getFinalPosition();

		if (currentPiece->moveValidation())
			chessGround.move(finalPosition);



		
	delete currentPiece;

	person.changeTurn();

	} while (!finish);
}
	