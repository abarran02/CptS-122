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

#include "GroceryList.h"

/*************************************************************
 * Function: GroceryList ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: constructor for GroceryList class            *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
GroceryList::GroceryList() {
	pHead = NULL;
}

/*************************************************************
 * Function: GroceryList ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: copy constructor for GroceryList class       *
 * Input parameters: const GroceryList& copyList             *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
GroceryList::GroceryList(const GroceryList& copyList) {
	GroceryItem* pCurrent = copyList.getHead();

	if (pCurrent == NULL) {
		pHead = NULL;
	}

	while (pCurrent != NULL) {
		insertAtEnd(pCurrent->getData());
		pCurrent = pCurrent->getNext();
	}
}

/*************************************************************
 * Function: ~GroceryList ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: destructor for GroceryList class             *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
GroceryList::~GroceryList() {
	GroceryItem* pCurrent = pHead, * pDel;

	// iterate over list and delete each item
	while (pCurrent != NULL) {
		pDel = pCurrent;

		pCurrent = pCurrent->getNext();
		delete pDel;
	}
}

/*************************************************************
 * Function: isEmpty ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: determines whether the list is empty         *
 * Input parameters: void                                    *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool GroceryList::isEmpty(void) {
	return (pHead == NULL);
}

/*************************************************************
 * Function: insertAtFront ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: creates a new GroceryItem object with the    *
 *		input data and inserts it at the front of the list   *
 * Input parameters: string info                             *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool GroceryList::insertAtFront(string info) {
	bool success = false;
	GroceryItem* newItem = new GroceryItem(info);

	// check that memory was allocated succesfully
	if (newItem != 0) {
		// if list is empty, set pHead to the new item
		if (this->isEmpty()) {
			pHead = newItem;
		}
		// otherwise insert new item at front
		else {
			newItem->setNext(pHead);
			pHead = newItem;
		}

		success = true;
	}

	return success;
}

/*************************************************************
 * Function: insertAtEnd ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: creates a new GroceryItem object with the    *
 *		input data and inserts it at the end of the list     *
 * Input parameters: string info                             *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool GroceryList::insertAtEnd(string info) {
	bool success = false;
	GroceryItem* newItem = new GroceryItem(info);
	GroceryItem* pCurrent;

	// check that memory was allocated succesfully
	if (newItem != 0) {
		// if list is empty, set pHead to the new item
		if (this->isEmpty()) {
			pHead = newItem;
		}
		// otherwise insert new item at end
		else {
			pCurrent = pHead;
			// seek to last item of list
			while (pCurrent->getNext() != NULL) {
				pCurrent = pCurrent->getNext();
			}

			// set newItem as new end of list
			pCurrent->setNext(newItem);
		}

		success = true;
	}

	return success;
}

/*************************************************************
 * Function: getHead ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pHead, head pointer to the list   *
 * Input parameters: void                                    *
 * Returns: GroceryItem*                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
GroceryItem* GroceryList::getHead(void) const{
	return pHead;
}

/*************************************************************
 * Function: getLength ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: calculates the length of the grocery list    *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int GroceryList::getLength(void) const {
	int length = 0;
	GroceryItem* pCurrent = pHead;

	// loop through list and count how many items are stepped over
	while (pCurrent != NULL) {
		length++;
		// increment list
		pCurrent = pCurrent->getNext();
	}

	return length;
}

/*************************************************************
 * Function: generateRandomList ()                           *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: generates a random grocery list of 1 to 5    *
 *		elements                                             *
 * Input parameters: void                                    *
 * Returns: GroceryList*                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
GroceryList* generateRandomList(void) {
	int randInt;
	// five random grocery items
	string foodStuffs[5] = { "banana", "cereal", "milk", "tomato", "chocolate" };
	GroceryList* randList = new GroceryList();

	// iterate over the foodStuffs list
	for (int i = 0; i < 5; i++) {
		// generate random int 0 or 1
		randInt = rand() % 2;

		// 50% chance to append to randList
		if (randInt) {
			randList->insertAtFront(foodStuffs[i]);
		}
	}

	// if nothing was added to the list
	if (randList->isEmpty()) {
		randList->insertAtFront("cigarettes");
	}

	return randList;
}

/*************************************************************
 * Function: operator<<                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for << operator to print            *
 *		GroceryList items to the screen                      *
 * Input parameters: ostream& lhs, const GroceryList& rhs    *
 * Returns: ostream&                                         *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
ostream& operator<< (ostream& lhs, const GroceryList& rhs) {
	GroceryItem* pCurrent = rhs.getHead();

	// iterate over grocery list
	while (pCurrent != NULL) {
		// output data of pCurrent, a string
		lhs << pCurrent->getData();

		// as long as pCurrent isn't the last item in the list, also output a comma
		if (pCurrent->getNext() != NULL) {
			lhs << ", ";
		}

		// increment list
		pCurrent = pCurrent->getNext();
	}

	return lhs;
}