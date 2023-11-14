#include <iostream>
#include <vector>
#include <string>

#include "functions.h"
#include "Background.h"

using namespace std;

int main()
{
	/*vector <string> board = read_strings_from_file("Chess_board.txt");

	cout_string_vector(board);

	vector<string> rules = read_strings_from_file("rules.txt");

	cout_string_vector(rules);*/

	Background chess_ground;

	chess_ground.access_to_coordinates(read_start_position());
	Player white("white piece");
	Player black("black piece");

}
	