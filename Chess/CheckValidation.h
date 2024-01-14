#pragma once

#include <set>
#include <vector>
#include <utility>
#include <unordered_map>

#include "Piece.h"
#include "Background.h"


struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);

		if (hash1 != hash2) {
			return hash1 ^ hash2;
		}

		return hash1;
	}
};

class CheckValidation
{
	Piece* currentPiece;
	Background* chessGround;

	unordered_map <pair<char, int>, set<pair<char, int>>, hash_pair>
		positionWhitePiecesWithScope, positionBlackPiecesWithScope;

	set<pair<char, int>> whitePiecesScope, blackPiecesScope;
	vector<string> board;
	pair<char, int> blackKing, whiteKing;

	bool check, checkMate;
	int turnGuard;

public:

	CheckValidation(Background* chessGround);
	~CheckValidation();
	bool getCheckMate();
	bool getCheck();
	void updateBoard();
	void updateTurnGuard();
	void initialValidationScope();
	bool checkControl(); 
	void changeKingPosition(pair<char, int> newPosition);
	void changePiecePosition
			(pair<char, int> startPosition, pair<char, int> newPosition);
	void completePiecesScope(); //
	void createScopeSetForAll();
	void showSets();
	void checkMateValidation(pair<char, int> offensivePiece);
	bool checkKillOffensivePiece(pair<char, int> offensivePiece, int turnGuard);
	bool shelterKing(pair<char, int> offensivePiece, int turnGuard);
	bool kingEscape(pair<char, int> offensivePiece, int turnGuard);
	void movePieceForScope
					(pair<char, int> startPosition, pair<char, int> newPosition);
};

