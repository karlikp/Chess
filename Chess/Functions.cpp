#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <cctype>

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

pair<char, int> read_start_position()
{
	bool correct;
	char upper_letter{};
	int number;
	do
	{
		char letter;
		string coordinates;
		correct = true;

		cout << "\nType in coordinate of your piece, which you're going to do a move"
			<< " (for example: D2) ";


		getline(cin, coordinates);
		letter = coordinates[0];
		number = int(coordinates[1] - '0');

		coordinates.clear();

		upper_letter = toupper(letter);
		if (not (upper_letter <= int('H') and upper_letter >= int('A')))
		{
			cout << "\nYour first sign is wrong";
			correct = false;
		}
		if (not (number <= 8 and number >= 1))
		{
			cout << "\nYour second sign is wrong";
			correct = false;
		}
		if (not correct)
			cout << "\nCorrect your answer, please.";
	} while (not correct);

	pair<char, int> checked_coordinates(upper_letter, number);
	return checked_coordinates;

}

//pair<char, int> piece_destination()
//{
//
//}

pair<string, string> move_decision()
{
	string start, destination;

	
	getline(cin, start);
	//function check correctness
	cout << "\nType in the coordinate where you're going to shift the chosen piece (e.q. D4): ";
	getline(cin, destination);
	//function check correctness
	pair <string, string> move;
	move.first = start;
	move.second = destination;

	return move;
}





