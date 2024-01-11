#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility>
#include <cctype>

#include "functions.h"
#include "Player.h"

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
//
//pair<string, string> moveDecision()
//{
//	string start, destination;
//
//	
//	getline(cin, start);
//	//function check correctness
//	cout << "\nType in the coordinate where you're going to shift the chosen piece (e.q. D4): ";
//	getline(cin, destination);
//	//function check correctness
//	pair <string, string> move;
//	move.first = start;
//	move.second = destination;
//
//	return move;
//}

bool boardValidation(char letter, int number)
{
	bool correct = positionIncludeInBoard(letter,number);
	
	if (not correct)
	{
		cout << "\nYour answer is wrong, please correct it: ";
	}
	return correct;
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



//pair<char, int> getStartPosition()
//{
//	cout << "\nType in coordinate of your piece, which you're going to do a move"
//		<< " (for example: D2) ";
//	pair<char, int> coords;
//	char sign;
//	do
//	{
//		coords = getPosition();
//		sign = getSign(coords)
//	}while(coords.second != 0 and sign    )
//}


Player* getPlayer()
{
	Player* person = nullptr;
	int turnCounter = Player::getTurnCounter();
	if (turnCounter == 0)
	{
		person = new White;
		turnCounter++;
	}
	else
	{
		person = new Black;
		turnCounter--;
	}
	return person;
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

void showAccessPositions(vector<pair<char, int>> pieceScope)
{
	cout << "\nAccess move position for your piece: ";

	for (auto i : pieceScope)
	{
		cout << "[" << i.first << "," << i.second << "]";
	}
}

