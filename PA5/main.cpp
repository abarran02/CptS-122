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

#include "TestQueue.h"

 /*************************************************************
  * Function: main ()                                         *
  * Date Created:                                             *
  * Date Last Modified:                                       *
  * Description: main driver for testQueue functions          *
  * Input parameters: void                                    *
  * Returns: int                                              *
  * Preconditions:                                            *
  * Postconditions:                                           *
  *************************************************************/
int main(void) {
	int n;
	std::srand(std::time(NULL));

	// test each function a print a newline after each for readability
	testEnqueueEmpty();
	cout << endl;
	testEnqueueOne();
	cout << endl;
	testDequeueOne();
	cout << endl;
	testDequeueTwo();
	cout << endl;

	// prompt user for how long to run the simulation, and pass to runSimulation() function
	n = promptIntInRange(0, std::numeric_limits<int>::max(), "How many minutes to run simulation? ");
	runSimulation(n);

	return 0;
}