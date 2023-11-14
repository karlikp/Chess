#pragma once

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Background
{
	vector <string> intro;
	vector <string> rules;
	vector <string> board;
	
public:

	Background();
	void show_board();
	void show_rules();
	bool access_to_coordinates(pair<char, int> coordinates);
	
};

