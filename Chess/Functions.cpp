#include "Functions.h"

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

void single_move(player name)
{

	if (player::name.check)
}



