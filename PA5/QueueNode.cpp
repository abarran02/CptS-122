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

#include "QueueNode.h"

 /*************************************************************
  * Function: QueueNode ()                                    *
  * Date Created:                                             *
  * Date Last Modified:                                       *
  * Description: constructor for QueueNode class with         *
  * Input parameters: int customerNumber, int serviceTime,    *
  *			int totalTime, GroceryList* groceries             *
  * Returns: void                                             *
  * Preconditions:                                            *
  * Postconditions:                                           *
  *************************************************************/
QueueNode::QueueNode(int customerNumber, int serviceTime, int totalTime, GroceryList* groceries) {
	pData = new Data(customerNumber, serviceTime, totalTime);
	pNext = NULL;
	pGroceries = groceries;
}

/*************************************************************
 * Function: QueueNode ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: destructor for QueueNode class               *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
QueueNode::~QueueNode() {
	delete pGroceries;
	delete pData;
}

/*************************************************************
 * Function: getData ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pData                             *
 * Input parameters: void                                    *
 * Returns: Data*                                            *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
Data* QueueNode::getData(void) const {
	return pData;
}

/*************************************************************
 * Function: getGroceries ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pGroceries                        *
 * Input parameters: void                                    *
 * Returns: GroceryList*                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
GroceryList* QueueNode::getGroceries(void) const {
	return pGroceries;
}

/*************************************************************
 * Function: getNext ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pNext                             *
 * Input parameters: void                                    *
 * Returns: QueueNode*                                       *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
QueueNode* QueueNode::getNext(void) const {
	return pNext;
}

/*************************************************************
 * Function: setNext ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for pNext                             *
 * Input parameters: QueueNode*                              *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void QueueNode::setNext(QueueNode* next) {
	pNext = next;
}
