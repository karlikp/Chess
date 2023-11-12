#include <iostream>
#include <vector>
#include <string>

#include "functions.h"
using namespace std;

int main()
{
	vector<string> board;
	board = read_string_from_file("Chess_board.txt");

	for (int i = 0; i < board.size(); i++)
		cout << board[i] << "\n";
	cout << '\n';

	
	vector<string> rules;
	rules = read_string_from_file("rules.txt");

	for (int i = 0; i < rules.size(); i++)
		cout << rules[i] << "\n";
	cout << '\n';
}