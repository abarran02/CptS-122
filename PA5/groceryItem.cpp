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

#include "GroceryItem.h"

 /*************************************************************
  * Function: GroceryItem ()                                  *
  * Date Created:                                             *
  * Date Last Modified:                                       *
  * Description: constructor for GroceryItem class            *
  * Input parameters: string info                             *
  * Returns: void                                             *
  * Preconditions:                                            *
  * Postconditions:                                           *
  *************************************************************/
GroceryItem::GroceryItem(string info) {
	mData = info;
	pNext = NULL;
}

/*************************************************************
 * Function: getNext ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pNext, pointer to next item in    *
 *		the GroceryList                                      *
 * Input parameters: void                                    *
 * Returns: GroceryItem*                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
GroceryItem* GroceryItem::getNext(void) const {
	return pNext;
}

/*************************************************************
 * Function: setNext ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for pNext, pointer to next item in    *
 *		the GroceryList                                      *
 * Input parameters: GroceryItem*                            *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void GroceryItem::setNext(GroceryItem* next) {
	pNext = next;
}

/*************************************************************
 * Function: getData ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mData                             *
 * Input parameters: void                                    *
 * Returns: string                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
string GroceryItem::getData(void) const {
	return mData;
}