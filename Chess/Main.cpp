#include <iostream>
#include <vector>
#include <string>

#include "functions.h"
#include "Background.h"
#include "CheckValidation.h"
#include "Piece.h"

using namespace std;

int main()
{

	Background* chessGround = new Background;
	
	CheckValidation validation(chessGround);
	Player person;

	bool finish = false;
	do
	{
		person.announcementTurn();
		chessGround->showBoard();
		pair<char, int> startPosition;
		Piece* currentPiece;
		do
		{
			startPosition = person.getStartPosition();

			chessGround->setPiece(startPosition);

			currentPiece = chessGround->getPiece(chessGround->getPieceValue());

			currentPiece->getScope(startPosition);

		} while (currentPiece->checkEmptinessScope());

		pair<char, int> finalPosition = currentPiece->getFinalPosition();

		if (currentPiece->moveValidation())
			validation.changeKingPosition(finalPosition);
			chessGround->move(finalPosition);

		validation.checkControl();



		
	delete currentPiece;

	person.changeTurn();

	} while (!finish);

	delete chessGround;

}
	