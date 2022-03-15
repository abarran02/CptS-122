/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: Example                                             *
 * Date:                                                                       *
 *                                                                             *
 * Description: Reads Morse code conversions from file and inputs to a binary  *
 *			search tree. Then reads a string to convert from file and prints   *
 *			the Morse code equivalent to screen                                *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (MorseTable.txt): A .- [int(space)string]    *
 ******************************************************************************/

#include "BST.h"
#include "Morse.h"

#include <fstream>
#include <sstream>

using std::getline;
using std::ifstream;
using std::stringstream;

int main(void) {
	ifstream table("MorseTable.txt"), convert("Convert.txt");
	string line, code;
	BST<Morse> bstMorse;

	// check that both MorseTable.txt and Convert.txt were opened successfully
	if (!table.is_open()) {
		cout << "Unable to open MorseTable.txt";
		return -1;
	}
	if (!convert.is_open()) {
		cout << "Unable to open Convert.txt";
		return -1;
	}

	// read MorseTable.txt line by line and parse character and corresponding Morse code
	while (getline(table, line)) {
		code = line.substr(2, line.length());
		bstMorse.insert(Morse(line[0], code));
	}

	// close MorseTable.txt
	table.close();

	// read entire Convert.txt to string
	// helped by https://stackoverflow.com/a/2602258
	stringstream strStream;
	strStream << convert.rdbuf();
	line = strStream.str();

	// iterate over characters of input string and print Morse code equivalent
	for (int i = 0; i < line.length(); i++) {
		// for printing, as no Morse equivalent for newline
		if (line[i] == '\n') {
			cout << endl;
			continue;
		}

		// search BST for code and print to screen
		cout << bstMorse.search((Morse)line[i])->getData();
	}

	// close Convert.txt
	convert.close();

	return 0;
}