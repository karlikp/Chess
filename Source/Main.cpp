#include <iostream>
#include <vector>
#include <string>

#include "Headers/functions.h"
#include "Headers/Background.h"
#include "Headers/CheckValidation.h"
#include "Headers/Piece.h"

using namespace std;

int main()
{

	Background* chessGround = new Background;
	Player person;
	CheckValidation validation(chessGround);
	validation.initialValidationScope();
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

			chessGround->setContainOfPosition(startPosition);

			currentPiece = chessGround->getPiece(chessGround->getPieceLetter());

			currentPiece->getScope(startPosition);

			showAccessPositions();
			
		} while (currentPiece->checkEmptinessScope());
		
		pair<char, int> finalPosition = currentPiece->getFinalPosition();
		
		delete currentPiece;
		chessGround->move(finalPosition);

		chessGround->setContainOfPosition(finalPosition);
		validation.updateTurnGuard();
		validation.movePieceForScope(startPosition, finalPosition);

		validation.completePiecesScope();
		validation.createScopeSetForAll();

		chessGround->setContainOfPosition(finalPosition);
		validation.checkControl();

		if (validation.getCheck())
		{
			validation.checkMateValidation(finalPosition);
		}

	person.changeTurn();

	} while (not validation.getCheckMate());

	person.end();

	delete chessGround;
}
	