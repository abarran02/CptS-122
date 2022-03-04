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

#include "Queue.h"

 /*************************************************************
  * Function: Queue ()                                        *
  * Date Created:                                             *
  * Date Last Modified:                                       *
  * Description: default constructor for Queue class          *
  * Input parameters: void                                    *
  * Returns: void                                             *
  * Preconditions:                                            *
  * Postconditions:                                           *
  *************************************************************/
Queue::Queue() {
	pHead = NULL;
	pTail = NULL;
	totalServed = 1;
	mExpress = false;
	lane = "Normal";
}

/*************************************************************
 * Function: Queue ()                                        *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: constructor for Queue class with explicit    *
 *		express lane status                                  *
 * Input parameters: bool express                            *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
Queue::Queue(bool express) {
	pHead = NULL;
	pTail = NULL;
	totalServed = 1;
	mExpress = express;

	// makes printing lane type easier
	if (mExpress) {
		lane = "Express";
	}
	else {
		lane = "Normal";
	}
}

/*************************************************************
 * Function: ~Queue ()                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: destructor for Queue class                   *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
Queue::~Queue() {
	QueueNode* pCurrent = pHead, * pDel;

	// iterate over queue and delete each node
	while (pCurrent != NULL) {
		pDel = pCurrent;

		pCurrent = pCurrent->getNext();
		delete pDel;
	}
}

/*************************************************************
 * Function: getHead ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pHead, head pointer to the list   *
 * Input parameters: void                                    *
 * Returns: QueueNode*                                       *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
QueueNode* Queue::getHead(void) const {
	return pHead;
}

/*************************************************************
 * Function: getTail ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pTail, tail pointer to the list   *
 * Input parameters: void                                    *
 * Returns: QueueNode*                                       *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
QueueNode* Queue::getTail(void) const {
	return pTail;
}

/*************************************************************
 * Function: isEmpty ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: determines whether the queue is empty        *
 * Input parameters: void                                    *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool Queue::isEmpty(void) {
	return (pHead == NULL);
}


/*************************************************************
 * Function: enqueue ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: creates a new QueueNode object with the      *
 *		input data and inserts it at the end of the queue    *
 * Input parameters: GroceryList* groceries                  *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool Queue::enqueue(GroceryList* groceries) {
	bool success = false;
	// see QueueNode.h for definitions of customerNumber, serviceTime, and totalTime
	int customerNumber = totalServed,
		serviceTime = calculateServiceTime(groceries, mExpress),
		totalTime = serviceTime + calculateTotalTime();
	// create a new QueueNode pointer with various data
	QueueNode* newNode = new QueueNode(customerNumber, serviceTime, totalTime, groceries),
		* pCurrent;

	// check that newNode allocated memory successfully
	if (newNode != 0) {
		// if the Queue is empty, new QueueNode should be both queue head and tail
		if (this->isEmpty()) {
			pHead = newNode;
			pTail = newNode;
		}
		else {
			// iterate pCurrent to the last customer of the queue
			pCurrent = pHead;
			while (pCurrent->getNext() != NULL) {
				pCurrent = pCurrent->getNext();
			}

			// update end of queue
			pCurrent->setNext(newNode);
			pTail = newNode;
		}

		// update totalServed and success
		totalServed++;
		success = true;
	}

	return success;
}

/*************************************************************
 * Function: enqueue ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: creates a new QueueNode object with the      *
 *		input data and inserts it at the end of the queue.   *
 *		Given currenTime, will print customer entrance to    *
 *		the screen                                           *
 * Input parameters: GroceryList* groceries, int currentTime *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool Queue::enqueue(GroceryList* groceries, int currentTime) {
	bool success = false;
	// see QueueNode.h for definitions of customerNumber, serviceTime, and totalTime
	int customerNumber = totalServed, 
		serviceTime = calculateServiceTime(groceries, mExpress),
		totalTime = serviceTime + calculateTotalTime();
	// create a new QueueNode pointer with various data
	QueueNode* newNode = new QueueNode(customerNumber, serviceTime, totalTime, groceries), 
		* pCurrent;

	// check that newNode allocated memory successfully
	if (newNode != 0) {
		// if the Queue is empty, new QueueNode should be both queue head and tail
		if (this->isEmpty()) {
			pHead = newNode;
			pTail = newNode;
		}
		else {
			// iterate pCurrent to the last customer of the queue
			pCurrent = pHead;
			while (pCurrent->getNext() != NULL) {
				pCurrent = pCurrent->getNext();
			}

			// update end of queue

			pCurrent->setNext(newNode);
			pTail = newNode;
		}

		// update totalServed and print new customer to the screen
		totalServed++;
		success = true;
		printEntrance(currentTime);
	}
	
	return success;
}

/*************************************************************
 * Function: dequeue ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: deletes the first item from the queue        *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Queue::dequeue(void) {
	QueueNode* pCurrent = pHead;

	// check that queue is not empty
	if (!this->isEmpty()) {
		// queue only has one item
		if (pCurrent->getNext() == NULL) {
			delete pCurrent;

			pHead = NULL;
			pTail = NULL;
		}
		// queue has two or more items
		else {
			pHead = pCurrent->getNext();
			delete pCurrent;
		}
	}
}

/*************************************************************
 * Function: getLength ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: calculates the length of the queue           *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int Queue::getLength(void) {
	int length = 0;
	QueueNode* pCurrent = pHead;

	// iterate over queue and count number of nodes stepped over
	while (pCurrent != NULL) {
		length++;
		// increment list
		pCurrent = pCurrent->getNext();
	}

	return length;
}

/*************************************************************
 * Function: printQueue ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: iterates over and prints the queue to screen *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Queue::printQueue(void) {
	QueueNode* pCurrent = pHead;

	// iterate over queue and print each item to the screen
	while (pCurrent != NULL) {
		cout << *(pCurrent->getData());

		// increment list
		pCurrent = pCurrent->getNext();
	}

	cout << endl;
}

/*************************************************************
 * Function: calculateTotalTime ()                           *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: calculates the sum of all service times in   *
 *		the queue                                            *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int Queue::calculateTotalTime(void) {
	int sum = 0;
	QueueNode* pCurrent = pHead;

	// iterate over queue and sum all service times
	while (pCurrent != NULL) {
		sum += pCurrent->getData()->getServiceTime();

		// iterate list
		pCurrent = pCurrent->getNext();
	}

	return sum;
}

/*************************************************************
 * Function: decrementLeader ()                              *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: decrememnts serviceTime for the queue leader *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Queue::decrementLeader(void) {
	pHead->getData()->decrementServiceTime();
}

/*************************************************************
 * Function: leaderIsDone ()                                 *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: determines whether the queue leader is       *
 *		finished checking out                                *
 * Input parameters: void                                    *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
bool Queue::leaderIsDone(void) const {
	return (pHead->getData()->getServiceTime() == 0);
}

/*************************************************************
 * Function: printEntrance ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prints data about pTail to the screen,       *
 *		indicating a new customer in the queue at some time  *
 * Input parameters: int currentTime                         *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Queue::printEntrance(int currentTime) {
	cout << "Customer number " << pTail->getData()->getCustomerNumber() << " entered the " << lane << " Lane at " << currentTime << " minutes with " << *(pTail->getGroceries()) << endl;
}

/*************************************************************
 * Function: resetServed ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: resets totalServed to 1                      *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Queue::resetServed(void) {
	totalServed = 1;
}

/*************************************************************
 * Function: calculateTServiceTime ()                        *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: calculates the service time of a given       *
 *		GroceryList and express lane status                  *
 * Input parameters: GroceryList* groceries, bool express    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int calculateServiceTime(GroceryList* groceries, bool express) {
	int length = groceries->getLength(), service;
	
	// calculate service time based on express lane status and grocery list length
	if (express) {
		// explicit cast to int
		service = (int)(1 + 0.5 * length);
	}
	else {
		service = (int)(2 + 1.5 * length);
	}

	return service;
}