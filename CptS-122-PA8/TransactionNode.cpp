/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA8                                                 *
 * Date:                                                                       *
 *                                                                             *
 * Description: Reads product buying and selling data from file, place data in *
 *			binary search trees. Then run data analysis on the input.          *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (data.csv): Units,Type,Transaction           *
 ******************************************************************************/

#include "TransactionNode.h"

/*************************************************************
 * Function: setUnits ()                                     *
 * Description: setter for mUnits                            *
 * Input parameters: int units                               *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void TransactionNode::setUnits(int units) {
	mUnits = units;
}

/*************************************************************
 * Function: getUnits ()                                     *
 * Description: getter for mUnits                            *
 * Input parameters:                                         *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int TransactionNode::getUnits() const {
	return mUnits;
}

/*************************************************************
 * Function: printData ()                                    *
 * Description: prints product and unit data to screen       *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void TransactionNode::printData() {
	cout << "Product: " << mData << endl;
	cout << "Units: " << mUnits << endl;
}

/*************************************************************
 * Function: operator<<                                      *
 * Description: << operator overload to print data to screen *
 * Input parameters: ostream& lhs, const TransactionNode& rhs*
 * Returns: ostream&                                         *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
ostream& operator<<(ostream& lhs, const TransactionNode& rhs) {
	lhs  << rhs.getData() << endl << rhs.getUnits() << endl;

	return lhs;
}