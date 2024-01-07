#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <cctype>

#include "functions.h"

using namespace std;


// First letters then numbers
vector<string>readStringsFromFile(string file_name)
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


pair<char, int> getPosition()
{
	bool correct;
	char upperLetter{};
	int number;
	do
	{
		char letter;
		string coordinates;

		getline(cin, coordinates);
		letter = coordinates[0];
		number = int(coordinates[1] - '0');

		coordinates.clear();

		upperLetter = toupper(letter);

		correct = boardValidation(upperLetter, number);
		
	} while (not correct);

	pair<char, int> coordinates(upperLetter, number);
	return coordinates;

}

pair<string, string> moveDecision()
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

void coutStringVector(vector <string> array)
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << "\n";
	cout << '\n';
}

bool boardValidation(char letter, int number)
{
	bool correct = true;

	if (not (letter <= int('H') and letter >= int('A')))
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

	return correct;
}

pair<char, int> getStartPosition()
{
	cout << "\nType in coordinate of your piece, which you're going to do a move"
		<< " (for example: D2) ";

	return getPosition();
}

pair<char, int> getFinishPosition()
{
	cout << "\nType in coordinate where you're going to do a move";
		
	return getPosition();
}