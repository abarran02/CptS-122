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

 /*************************************************************
  * Function: Morse ()                                        *
  * Date Created:                                             *
  * Date Last Modified:                                       *
  * Description: constructor for Morse class                  *
  * Input parameters: char letter, string code                *
  * Returns:                                                  *
  * Preconditions:                                            *
  * Postconditions:                                           *
  *************************************************************/
Morse::Morse(char letter, string code) {
	mLetter = toupper(letter);
	mCode = code;
}

/*************************************************************
 * Function: setLetter ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mLetter member attribute          *
 * Input parameters: char letter                             *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Morse::setLetter(char letter) {
	mLetter = letter;
}

/*************************************************************
 * Function: getLetter ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mLetter member attribute          *
 * Input parameters: void                                    *
 * Returns: char                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
char Morse::getLetter(void) const {
	return mLetter;
}

/*************************************************************
 * Function: setCode ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mCode member attribute            *
 * Input parameters: string code                             *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Morse::setCode(string code) {
	mCode = code;
}

/*************************************************************
 * Function: getCode ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mCode member attribute            *
 * Input parameters: void                                    *
 * Returns: string                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
string Morse::getCode(void) const {
	return mCode;
}

/*************************************************************
 * Function: operator<<                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for << operator print to screen     *
 * Input parameters: ostream& lhs, const Morse rhs           *
 * Returns: ostream&                                         *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
ostream& operator<<(ostream& lhs, const Morse rhs) {
	lhs << rhs.getCode() << " ";

	return lhs;
}

/*************************************************************
 * Function: operator==                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for == operator to compare mLetters *
 * Input parameters: const Morse lhs, const Morse rhs        *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool operator==(const Morse lhs, const Morse rhs) {
	if (lhs.getLetter() == rhs.getLetter()) {
		return true;
	}
	else {
		return false;
	}
}

/*************************************************************
 * Function: operator<                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for < operator to compare mLetters  *
 * Input parameters: const Morse lhs, const Morse rhs        *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool operator<(const Morse lhs, const Morse rhs) {
	if (lhs.getLetter() < rhs.getLetter()) {
		return true;
	}
	else {
		return false;
	}
}

/*************************************************************
 * Function: operator>                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for > operator to compare mLetters  *
 * Input parameters: const Morse lhs, const Morse rhs        *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool operator>(const Morse lhs, const Morse rhs) {
	if (lhs.getLetter() > rhs.getLetter()) {
		return true;
	}
	else {
		return false;
	}
}