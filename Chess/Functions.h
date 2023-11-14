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

vector<string>read_strings_from_file(string file_name); 

void cout_string_vector(vector <string> array);

void single_move(Player);

pair<string,string> move_decision();

pair<char, int> read_start_position();

void current_piece(pair<char, int> coordinates);



