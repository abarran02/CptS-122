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

#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::toupper;

class Morse {
public:
	Morse(char letter = NULL, string code = "");
	
	void setLetter(char letter);
	char getLetter(void) const;

	void setCode(string code);
	string getCode(void) const;

private:
	char mLetter;
	string mCode;
};

ostream& operator<<(ostream& lhs, const Morse rhs);

bool operator==(const Morse lhs, const Morse rhs);
bool operator<(const Morse lhs, const Morse rhs);
bool operator>(const Morse lhs, const Morse rhs);