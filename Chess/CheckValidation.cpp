#include "CheckValidation.h"

CheckValidation::CheckValidation(Background* CHESSGROUND)
{
	chessGround = CHESSGROUND;
	board = Background::getBoard();
	whiteKing = { 'E', 1 };
	blackKing = { 'E', 8 };
	white = 0;
	black = 1;
}

CheckValidation::~CheckValidation()
{

}

void CheckValidation::updateBoard()
{
	board = Background::getBoard();
}

void CheckValidation::updateTurnGuard()
{
	turnGuard = Player::getTurnGuard();
}

void CheckValidation::InitialValidationScope(pair<char,int> currentPosition)
{


	chessGround->setPiece(currentPosition);

	Piece* current = chessGround->getPiece(chessGround->getPieceValue());

	currentPiece->getScope(currentPosition);
}

void CheckValidation::checkControl()
{
	vector<pair<char, int>> scope = Piece::currentMoveScope;
	if (turnGuard == white)
	{
		for (int i = 0; i < scope.size(); i++)
			if (blackKing == scope[i])
			{
				check = true;
				break;
			}
	}
}

void CheckValidation::changeKingPosition(pair<char, int> newPosition)
{
	if (turnGuard == white)
		blackKing = newPosition;
	else
		whiteKing = newPosition;
}