#include <cstdlib>

#include "CheckValidation.h"

CheckValidation::CheckValidation(Background* CHESSGROUND)
{
	chessGround = CHESSGROUND;
	board = Background::getBoard();
	whiteKing = { 'E', 1 };
	blackKing = { 'E', 8 };
	check = false;
	checkMate = false;
}

CheckValidation::~CheckValidation()
{

}

bool CheckValidation::getCheckMate()
{
	return checkMate;
}

bool CheckValidation::getCheck()
{
	return check;
}

void CheckValidation::updateBoard()
{
	board = Background::getBoard();
}

void CheckValidation::updateTurnGuard()
{
	turnGuard = Player::getTurnGuard();
}

void CheckValidation::initialValidationScope()
{
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			positionWhitePiecesWithScope[{char(i + 'A'), j}] = { {'0',0} };
			
		}
		positionWhitePiecesWithScope.erase(whiteKing);
		for (int j = 7; j < 9; j++)
		{
			positionBlackPiecesWithScope[{char(i + 'A'), j}] = { {'0',0} };
		}
		positionWhitePiecesWithScope.erase(blackKing);
	}
}

void CheckValidation::completePiecesScope()
{
	unordered_map <pair<char, int>, set<pair<char, int>>, hash_pair>*
		currentScope;
	for (int i = 0; i < 2; i++) {

		if (i == 0)
		{
			Player::setCurrentSign(' ');
			currentScope = &positionWhitePiecesWithScope;
		}
		else
		{	
			Player::setCurrentSign('-');
			currentScope = &positionBlackPiecesWithScope;
		}
		cout << "\n\n";
		for (auto it : *currentScope)
		{
			cout << "[" << it.first.first << it.first.second << "]";
		}
		cout << "\n";

		for (auto position : *currentScope)
		{
			pair<char, int> currentPosition = position.first;

			chessGround->setContainOfPosition(currentPosition);

			currentPiece = chessGround->getPiece(chessGround->getPieceValue());

			currentPiece->getScope(currentPosition);

			(*currentScope)[currentPosition] = Piece::currentMoveScope;

			delete currentPiece;
		}
		if(i == 0)
			Player::setCurrentSign('-');
		else
			Player::setCurrentSign(' ');
	}
}

void CheckValidation::createScopeSetForAll()
{
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			whitePiecesScope.clear();
			for (auto it : positionWhitePiecesWithScope)
				whitePiecesScope.merge(it.second);
		}
		else
		{
			blackPiecesScope.clear();
			for (auto it : positionBlackPiecesWithScope)
				blackPiecesScope.merge(it.second);
		}
	}

}

void CheckValidation::showSets()
{
	cout << "\n\n White Pieces scope: ";
		for (auto it : whitePiecesScope)
		{
			cout << "[" << it.first << it.second << "]";
		}
	cout << "\n\n Black Pieces scope: ";

	for (auto it : blackPiecesScope)
	{
		cout << "[" << it.first << it.second << "]";
	}
}

void CheckValidation::checkMateValidation(pair<char, int> offensivePiece)
{
	turnGuard = Player::getTurnGuard();

	if (checkKillOffensivePiece(offensivePiece, turnGuard) or
		shelterKing(offensivePiece, turnGuard) or
		kingEscape(offensivePiece, turnGuard))
	{
		checkMate = false;
		cout << "\n[The check has emerged, you must keep your king safe]";
	}
	else
		checkMate = true;

	
}

bool CheckValidation::checkKillOffensivePiece
						(pair<char, int> offensivePiece, int turnGuard)
{
	if (turnGuard == 0)
	{
		for (auto it : blackPiecesScope)
		{
			if (it == offensivePiece)
				return true;
		}
	}
	else
	{
		for (auto it : whitePiecesScope)
		{
			if (it == offensivePiece)
				return true;
		}
	}
	return false;
}

bool CheckValidation::shelterKing
						(pair<char, int> offensivePiece, int turnGuard)
{
	set<pair<char, int>> blockPosition;

	int offensiveValue = Background::getPieceValue();
	if (offensiveValue == 3 or offensiveValue == 4 or offensiveValue == 5)
	{

		pair<char, int> *currentKing;

		if (turnGuard == 0)
			currentKing = &blackKing;
		else
			currentKing = &whiteKing;

		char kingLetter = (*currentKing).first;
		int kingNumber = (*currentKing).second;

		char offensiveLetter = offensivePiece.first;
		int offensiveNumber = offensivePiece.second;

		if (kingLetter == offensiveLetter)		//common letter
		{
			for (int i = 0; i < abs(kingNumber - offensiveNumber - 1); i++)
			{
				if(kingNumber > offensiveNumber)
					blockPosition.insert({ kingLetter, kingNumber - i - 1 });
				else
					blockPosition.insert({ kingLetter, kingNumber + i + 1 });
			}
		}
		else if (kingNumber == offensiveNumber)
		{
			for (int i = 0; i < abs(kingLetter - offensiveLetter - 1); i++)
			{
				if (int(kingLetter) > int(offensiveLetter))
					blockPosition.insert({ char( int(kingLetter) - i - 1), kingNumber});
				else
					blockPosition.insert({ char(int(kingLetter) + i + 1), kingNumber });
			}
		}
		else
		{
			if (kingLetter > offensiveLetter and kingNumber > offensiveNumber)
			{
				for (int i = 0; i < abs(kingNumber - offensiveNumber - 1); i++)
				{
					blockPosition.insert({char(int(kingLetter) - i - 1), kingNumber - i - 1});
				}
			}
			else if ((kingLetter > offensiveLetter and kingNumber < offensiveNumber))
			{
				for (int i = 0; i < abs(kingNumber - offensiveNumber - 1); i++)
				{
					blockPosition.insert({ char(int(kingLetter) - i - 1), kingNumber + i + 1 });
				}
			}
			else if ((kingLetter < offensiveLetter and kingNumber < offensiveNumber))
			{
				for (int i = 0; i < abs(kingNumber - offensiveNumber - 1); i++)
				{
					blockPosition.insert({ char(int(kingLetter) + i + 1), kingNumber + i + 1 });
				}
			}
			else if ((kingLetter < offensiveLetter and kingNumber > offensiveNumber))
			{
				for (int i = 0; i < abs(kingNumber - offensiveNumber - 1); i++)
				{
					blockPosition.insert({ char(int(kingLetter) + i + 1), kingNumber - i - 1 });
				}
			}
		}
		set<pair<char, int>> *defenceScope;
		if (turnGuard == 0)
			defenceScope = &blackPiecesScope;
		else
			defenceScope = &whitePiecesScope;
		for (auto defenceField : *defenceScope)
		{
			for (auto blockField : blockPosition)
			{
				if (blockField == defenceField)
					return true;
			}
		}
	}
	return false;
}

bool CheckValidation::kingEscape(pair<char, int> offensivePiece, int turnGuard)
{
	set<pair<char, int>> *kingScope;
	set<pair<char, int>> *offensiveScope;
	if (turnGuard == 0)
	{
		kingScope = &positionBlackPiecesWithScope[{blackKing}];
		offensiveScope = &whitePiecesScope;
	}
	else
	{
		kingScope = &positionWhitePiecesWithScope[{blackKing}];
		offensiveScope = &blackPiecesScope;
	}

	for (auto kingMove : *kingScope)
	{
		bool accessField = true;
		for (auto offensiveMove : *offensiveScope)
		{
			if (offensiveMove == kingMove)
			{
				accessField = false;
				break;
			}
		}
		if (accessField)
			return true;
	}
	return false;
}

void CheckValidation::movePieceForScope
					(pair<char, int> startPosition, pair<char, int> newPosition)
{
	int pieceValue = Background::getPieceValue();

	if(pieceValue == 6)
		changeKingPosition(newPosition);
	else
		changePiecePosition(startPosition, newPosition);
}

bool CheckValidation::checkControl()
{
	if (turnGuard == 0)
	{
		for (auto it : whitePiecesScope)
			if (blackKing == it)
			{
				check = true;
				break;
			}
	}
	else
	{
		for (auto it : blackPiecesScope)
			if (whiteKing == it)
			{
				check = true;
				break;
			}
	}
	return check;
}

void CheckValidation::changeKingPosition(pair<char, int> newPosition)
{
	if (Background::getPieceValue() == 6)
	{
		if (turnGuard == 0)
			blackKing = newPosition;
		else
			whiteKing = newPosition;
	}
}

void CheckValidation::changePiecePosition
						(pair<char, int> startPosition, pair<char, int> newPosition)
{
	unordered_map <pair<char, int>, set<pair<char, int>>, hash_pair>*
		positionPiecesWithScope;

	if (turnGuard == 0)
		positionPiecesWithScope = & positionWhitePiecesWithScope;
	else
		positionPiecesWithScope = & positionBlackPiecesWithScope;

	(*positionPiecesWithScope).erase(startPosition);
	(*positionPiecesWithScope)[newPosition] = { newPosition };

	for (auto it : *positionPiecesWithScope)
	{
		cout << "[" << it.first.first << it.first.second << "]";
	}
}
