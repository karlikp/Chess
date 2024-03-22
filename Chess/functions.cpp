#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <cctype>

#include "functions.h"
#include "Background.h"


using namespace std;

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
			if (line.empty())                
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
		do
		{
			getline(cin, coordinates);
		} while (coordinates == "");
		letter = coordinates[0];
		number = int(coordinates[1] - '0');

		coordinates.clear();

		upperLetter = toupper(letter);

		correct = boardValidation(upperLetter, number);
		
	} while (not correct);

	pair<char, int> coordinates(upperLetter, number);
	return coordinates;

}

bool boardValidation(char letter, int number)
{
	if (not positionIncludeInBoard(letter, number))
	{
		cout << "\nYour answer is incorrect, please type in piece position "
			"according to the instructions: ";
		return false;
	}
	return true;
}

bool positionIncludeInBoard(char letter, int number)
{
	bool include = true;
	if ((number > 8 or number < 1) or
		(int(letter) > int('H') or int(letter) < int('A')))
		include = false;
	return include;

}
void coutStringVector(vector <string> array)
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << "\n";
	cout << '\n';
}

bool occupiedPosition(char letter, int number)
{
	bool occupied = false;

	int rowIndex = 10 - number;
	int columnIndex = 4 + (letter - 65) * 3;
	vector <string> board = Background::getBoard();
	if (board[rowIndex][columnIndex] != '0')
		occupied = true;

	return occupied;
}

void showAccessPositions()
{
	set<pair<char, int>>* pieceScope;
	pieceScope = &Piece::currentMoveScope;
	cout << "\nAccess move position for your piece: ";

	for (auto i : *pieceScope)
	{
		cout << "[" << i.first << "," << i.second << "]";
	}
}



