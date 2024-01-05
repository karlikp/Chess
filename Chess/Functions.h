#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "player.h"

using namespace std;

/*read file like:
- chess board,
- rules,
- help.*/

vector<string>readStringsFromFile(string file_name); 

void coutStringVector(vector <string> array);

void singleMove(Player);

pair<string,string> moveDecision();

pair<char, int> setPosition();

pair<char, int> setStartPosition();

pair<char, int> setFinishPosition();

bool boardValidation(char letter, int number);



