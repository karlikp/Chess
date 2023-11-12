#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "functions.h"

using namespace std;


// First letters then numbers
vector<string>read_string_from_file(string file_name)
{
	vector<string> array;
	ifstream file;
	file.open(file_name);
	
	if (file.is_open())
	{
		string line;
		int counter = 0;
		while (getline(file, line))
		{
			array.push_back(line);
			counter++;
			if (line.empty())                  // be careful: an empty line might be read
				continue;
		}
	}
	return array;
}

void single_move(Player name)
{

	if (name.return_check() == false)
	{
		//move_decision();
	}
}

pair<string, string> move_decision()
{
	string start, destination;
	cout << "\nCheck your piece, which you' re going to do move (e.q. C3): ";
	getline(cin, start);
	cout << "\nCheck your piece, which you' re going to do move (e.q. C3): ";
}



