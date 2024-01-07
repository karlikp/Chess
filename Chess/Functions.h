#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "player.h"
#include "Background.h"

using namespace std;

vector<string>readStringsFromFile(string file_name); 

void coutStringVector(vector <string> array);

void singleMove(Player);

pair<string,string> moveDecision();

pair<char, int> getPosition();

pair<char, int> getStartPosition();

pair<char, int> getFinishPosition();

bool boardValidation(char letter, int number);





