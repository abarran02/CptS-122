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
  * Function: testEnqueueEmpty ()                             *
  * Date Created:                                             *
  * Date Last Modified:                                       *
  * Description: test function for Queue class enqueue ()     *
  *		starting with an empty queue                          *
  * Input parameters: void                                    *
  * Returns: void                                             *
  * Preconditions:                                            *
  * Postconditions:                                           *
  *************************************************************/
void testEnqueueEmpty(void) {
	bool success;
	Queue queue;
	// grocery list is empty, but doesn't matter unless simulating
	GroceryList* groceries = new GroceryList();

	// add a single customer to empty queue
	success = queue.enqueue(groceries);

	// successfully allocated memory
	if (success) {
		cout << "Successfully allocated memory for element" << endl;

		// check that pHead was updated, indicated added to queue
		if (queue.getHead() != NULL) {
			cout << "Successfully added element to queue" << endl;

			// check that pHead and pTail are equal
			if (queue.getHead() == queue.getTail()) {
				cout << "Successfully set pHead and pTail to same pointer" << endl;

				// check that element was initialized with correct data
				if (queue.getHead()->getData()->getCustomerNumber() == 1) {
					cout << "Successfully initialized element with correct data" << endl;
				}
				else {
					cout << "Unsuccessful at initializing element data" << endl;
				}
			}
			else {
				cout << "Unsuccessful at setting pHead and pTail to same pointer" << endl;
			}
		}
		else {
			cout << "Unsuccessful at adding element to queue" << endl;
		}
	}
	else {
		cout << "Unsuccessful at allocating memory for element" << endl;
	}

}

/*************************************************************
 * Function: testEnqueueOne ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: test function for Queue class enqueue ()     *
 *		starting with one item already in queue              *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void testEnqueueOne(void) {
	Queue queue;
	GroceryList* groceries = new GroceryList();

	// add two customers to the queue
	queue.enqueue(groceries);
	// need a new grocery list so items in queue are different
	groceries = new GroceryList();
	queue.enqueue(groceries);

	// check that two items were added to the queue
	if (queue.getLength()) {
		cout << "Successfully added two elements to queue" << endl;

		// check that pHead and pTail are two different pointers
		if (queue.getHead() != queue.getTail()) {
			cout << "Successfully pointed items to different memory" << endl;

			// check that data in pointers is different
			if (queue.getHead()->getData()->getCustomerNumber() != queue.getTail()->getData()->getCustomerNumber()) {
				cout << "Successfully set different data to queue elements" << endl;
			}
			else {
				cout << "Unsuccessful at setting different data to elements" << endl;
			}
		}
		else {
			cout << "Unsuccessful at pointing to different memory" << endl;
		}
	}
	else {
		cout << "Unsuccessful at adding two items to queue" << endl;
	}
}

/*************************************************************
 * Function: testDequeueOne ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: test function for Queue class dequeue ()     *
 *		with one item in the queue                           *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void testDequeueOne(void) {
	bool success;
	Queue queue;
	GroceryList* groceries = new GroceryList();

	// add one customer to the queue, to be dequeued later
	success = queue.enqueue(groceries);

	// check that memory successfully allocated
	if (success) {
		cout << "Successfully allocated memory for and added element to queue" << endl;

		// invoke dequeue
		queue.dequeue();

		// check that dequeue was successful
		if (queue.getHead() == NULL && queue.getTail() == NULL) {
			cout << "Successfully dequeued and reset pHead and pTail to NULL" << endl;
		}
		else {
			cout << "Unsuccessful at dequeue and resetting pHead and pTail" << endl;
		}
	}
	else {
		cout << "Unsuccessful at adding element to queue" << endl;
	}
}

/*************************************************************
 * Function: testDequeueTwo ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: test function for Queue class dequeue ()     *
 *		with two items in the queue                          *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void testDequeueTwo(void) {
	Queue queue;
	GroceryList* groceries = new GroceryList();

	// add two customers to the queue, one of which will be dequeued later
	queue.enqueue(groceries);
	groceries = new GroceryList();
	queue.enqueue(groceries);

	// check that two items were added to the queue
	if (queue.getLength()) {
		cout << "Successfully added two elements to queue" << endl;

		// dequeue first element
		queue.dequeue();

		// check that pHead and pTail are updated to same pointer
		if (queue.getHead() == queue.getTail()) {
			cout << "Successfully updated pHead and pTail to same pointer" << endl;

			// check that remaining data in queue is of the second element added
			if (queue.getHead()->getData()->getCustomerNumber() == 2) {
				cout << "Successfully set second element added to queue to pHead" << endl;
			}
			else {
				cout << "Unsuccessful at setting second element added to pHead" << endl;
			}
		}
		else {
			cout << "Unsuccessful at updating pHead and pTail to same pointer" << endl;
		}
	}
	else {
		cout << "Unsuccessful at adding two items to queue" << endl;
	}
}

/*************************************************************
 * Function: runSimulation ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: test function for all Queue functions by     *
 *		running a simulation of two queues, one express and  *
 *		one normal, for n minutes as provided by user        *
 * Input parameters: int n                                   *
 * Returns: void                                             *
 * Preconditions: n > 0                                      *
 * Postconditions:                                           *
 *************************************************************/
void runSimulation(int n) {
	Queue expressLane(true), normalLane(false);
	GroceryList* randGroceries;
	int currentTime = 0, nextExpress = 1 + rand() % 5 , 
		nextNormal = 3 + rand() % 6, randInt;

	while (currentTime <= n) {
		// customer IDs reset every 24hrs
		if (currentTime % 1440 == 0) {
			expressLane.resetServed();
			normalLane.resetServed();
		}

		// check if it is time to add new customers to the queue
		if (currentTime == nextExpress) {
			// generate a random grocery list
			randGroceries = generateRandomList();
			// add to queue
			expressLane.enqueue(randGroceries, currentTime);

			// random int between 1 and 5
			randInt = 1 + rand() % 5;
			nextExpress = currentTime + randInt;
		}
		// see above
		if (currentTime == nextNormal) {
			randGroceries = generateRandomList();
			normalLane.enqueue(randGroceries, currentTime);

			// randon int between 3 and 8
			randInt = 3 + rand() % 6;
			nextNormal = currentTime + randInt;
		}

		// as long as queues aren't empty
		// check if current queue leaders are done
		if (!expressLane.isEmpty() && expressLane.leaderIsDone()) {
			expressLane.dequeue();
		}
		if (!normalLane.isEmpty() && normalLane.leaderIsDone()) {
			normalLane.dequeue();
		}

		// print entire queue every ten minutes
		if (currentTime % 10 == 0) {
			cout << "Express lane queue after " << currentTime << " minutes: " << endl;
			expressLane.printQueue();

			cout << "Normal lane queue after " << currentTime << " minutes: " << endl;
			normalLane.printQueue();
		}

		// increment time and decrement leaders' service times
		if (!expressLane.isEmpty()) {;
			expressLane--;
		}
		if (!normalLane.isEmpty()) {
			normalLane--;
		}

		currentTime++;
	}
}

/*************************************************************
 * Function: promptIntInRange ()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prompts user with given message for an int   *
 *		within the range provided                            *
 * Input parameters: int min, int max, string message        *
 * Returns: int                                              *
 * Preconditions: min <= max                                 *
 * Postconditions: min <= int <= max                         *
 *************************************************************/
int promptIntInRange(int min, int max, string message) {
	int prompt;

	do {
		// requires cin to load an int, clears input stream if it is not
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// print message to user and get their option input
		cout << message;
		cin >> prompt;

		// check that input is an int and is between min and max
	} while (cin.fail() || (prompt < min || prompt > max));

	return prompt;
}