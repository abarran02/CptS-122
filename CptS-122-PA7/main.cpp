/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA7                                                 *
 * Date: 04/06/2022                                                            *
 *                                                                             *
 * Description: Read class list from .csv and modify absences for each student *
 *		and re-store the data in a relevent .txt format. Used data structures  *
 *		include stacks and linked lists.                                       *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (classList.csv): see csv header              *
 ******************************************************************************/

#include "Wrapper.h"

int main(void) {
	string classfile = "classList.csv", masterfile = "master.txt";
	Wrapper app(classfile, masterfile);
	app.run();

	return 0;
}