#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "Piece.h"
#include "BishopPiece.h"
#include "GueenPiece.h"
#include "KingPiece.h"
#include "KnightPiece.h"
#include "PawnPiece.h"
#include "RookPiece.h"
#include "player.h"

using namespace std;
/*read file like:
- chess board,
- rules,
- help.*/
vector<string>read_string_from_file(string file_name); 
void single_move(player);


