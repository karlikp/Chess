#include <iostream>
#include <vector>
#include <string>

#include "Background.h"
#include "functions.h"

Background::Background()
{
	vector <string> intro = read_strings_from_file("introduction.txt");
	cout_string_vector(intro);
	board = read_strings_from_file("Chess_board.txt");
	cout_string_vector(board);
	rules = read_strings_from_file("rules.txt");
	cout_string_vector(rules);
}

void Background::show_board()
{
	cout_string_vector(board);
}

void Background::show_rules()
{
	cout_string_vector(rules);
}

bool Background::access_to_coordinates(pair<char, int> coordinates)
{
	int vector_index = 10 - coordinates.second;
	int string_index = 4 + (coordinates.first - 65) * 3;
	int sign_string_index = string_index - 1;

	cout << board[vector_index][string_index];

	return false;
}

