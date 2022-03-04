/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA5                                                 *
 * Date: 03/11/2022                                                            *
 *                                                                             *
 * Description: Simulates two grocery checkout lanes, represented by Queues,   *
 *		to determine which is more efficient. The Queues contain Nodes         *
 *		representing customers with grocery Lists, and track their time        *
 *		in line                                                                *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * No input or output files required for this program.                         *
 ******************************************************************************/

#include "Data.h"

 /*************************************************************
  * Function: Data ()                                         *
  * Date Created:                                             *
  * Date Last Modified:                                       *
  * Description: constructor for Data class                   *
  * Input parameters: int customerNumber, int serviceTime,    *
  *			int totalTime                                     *
  * Returns: void                                             *
  * Preconditions:                                            *
  * Postconditions:                                           *
  *************************************************************/
Data::Data(int customerNumber, int serviceTime, int totalTime) {
	mCustomerNumber = customerNumber;
	mServiceTime = serviceTime;
	mTotalTime = totalTime;
}

/*************************************************************
 * Function: getCustomerNumber ()                            *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mCustomerNumber                   *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int Data::getCustomerNumber(void) const {
	return mCustomerNumber;
}

/*************************************************************
 * Function: setCustomerNumber ()                            *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mCustomerNumber                   *
 * Input parameters: int number                              *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Data::setCustomerNumber(int number) {
	mCustomerNumber = number;
}

/*************************************************************
 * Function: getServiceTime ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mServiceTime                      *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int Data::getServiceTime(void) const {
	return mServiceTime;
}

/*************************************************************
 * Function: setServiceTime ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mServiceTime                      *
 * Input parameters: int time                                *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Data::setServiceTime(int time) {
	mServiceTime = time;
}

/*************************************************************
 * Function: decrementServiceTime ()                         *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: decrements mServiceTime by 1                 *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Data::decrementServiceTime(void) {
	mServiceTime--;
}

/*************************************************************
 * Function: getTotalTime ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mTotalTime                        *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int Data::getTotalTime(void) const {
	return mTotalTime;
}

/*************************************************************
 * Function: setTotalTime ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mTotalTime                        *
 * Input parameters: int time                                *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Data::setTotalTime(int time) {
	mTotalTime = time;
}

/*************************************************************
 * Function: operator<<                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for << operator to print Data class *
 *		member fields to the screen                          *
 * Input parameters: ostream& lhs, const Data& rhs           *
 * Returns: ostream&                                         *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
ostream& operator<< (ostream& lhs, const Data& rhs) {
	lhs << "Customer number: " << rhs.getCustomerNumber() << endl;
	lhs << "Service time: " << rhs.getServiceTime() << endl;
	lhs << "Total time: " << rhs.getTotalTime() << endl;

	return lhs;
}