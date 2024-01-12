#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Background.h"
#include "Player.h"

using namespace std;

vector<string>readStringsFromFile(string file_name); 

void coutStringVector(vector <string> array);

pair<char, int> getPosition();

bool boardValidation(char letter, int number);

bool positionIncludeInBoard(char letter, int number);

bool occupiedPosition(char letter, int number);

void showAccessPositions(vector<pair<char, int>>pieceScope);




