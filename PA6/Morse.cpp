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

#include "Morse.h"

Morse::Morse(char letter, string code) {
	mLetter = toupper(letter);
	mCode = code;
}

void Morse::setLetter(char letter) {
	mLetter = letter;
}

char Morse::getLetter(void) const {
	return mLetter;
}

void Morse::setCode(string code) {
	mCode = code;
}

string Morse::getCode(void) const {
	return mCode;
}

ostream& operator<<(ostream& lhs, const Morse rhs) {
	lhs << rhs.getCode() << " ";

	return lhs;
}

bool operator==(const Morse lhs, const Morse rhs) {
	if (lhs.getLetter() == rhs.getLetter()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const Morse lhs, const Morse rhs) {
	if (lhs.getLetter() < rhs.getLetter()) {
		return true;
	}
	else {
		return false;
	}
}

bool operator>(const Morse lhs, const Morse rhs) {
	if (lhs.getLetter() > rhs.getLetter()) {
		return true;
	}
	else {
		return false;
	}
}