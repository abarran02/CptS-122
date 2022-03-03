#include "Queue.h"

Queue::Queue() {
	pHead = NULL;
	pTail = NULL;
	totalServed = 1;
	mExpress = false;
	lane = "Normal";
}

Queue::Queue(bool express) {
	pHead = NULL;
	pTail = NULL;
	totalServed = 1;
	mExpress = express;

	if (mExpress) {
		lane = "Express";
	}
	else {
		lane = "Normal";
	}
}

Queue::~Queue() {
	QueueNode* pCurrent = pHead, * pDel;

	while (pCurrent != NULL) {
		pDel = pCurrent;

		pCurrent = pCurrent->getNext();
		delete pDel;
	}
}

QueueNode* Queue::getHead(void) const {
	return pHead;
}

QueueNode* Queue::getTail(void) const {
	return pTail;
}

bool Queue::isEmpty(void) {
	return (pHead == NULL);
}

bool Queue::enqueue(GroceryList* groceries) {
	bool success = false;
	int customerNumber = totalServed,
		serviceTime = calculateServiceTime(groceries, mExpress),
		totalTime = serviceTime + calculateTotalTime();
	QueueNode* newNode = new QueueNode(customerNumber, serviceTime, totalTime, groceries),
		* pCurrent;

	// check that newNode allocated memory successfully
	if (newNode != 0) {
		if (this->isEmpty()) {
			pHead = newNode;
			pTail = newNode;
		}
		else {
			pCurrent = pHead;
			while (pCurrent->getNext() != NULL) {
				pCurrent = pCurrent->getNext();
			}

			pCurrent->setNext(newNode);
			pTail = newNode;
		}

		totalServed++;
		success = true;
	}

	return success;
}

bool Queue::enqueue(GroceryList* groceries, int currentTime) {
	bool success = false;
	int customerNumber = totalServed, 
		serviceTime = calculateServiceTime(groceries, mExpress),
		totalTime = serviceTime + calculateTotalTime();
	QueueNode* newNode = new QueueNode(customerNumber, serviceTime, totalTime, groceries), 
		* pCurrent;

	// check that newNode allocated memory successfully
	if (newNode != 0) {
		if (this->isEmpty()) {
			pHead = newNode;
			pTail = newNode;
		}
		else {
			pCurrent = pHead;
			while (pCurrent->getNext() != NULL) {
				pCurrent = pCurrent->getNext();
			}

			pCurrent->setNext(newNode);
			pTail = newNode;
		}

		totalServed++;
		success = true;
		printEntrance(currentTime);
	}
	
	return success;
}

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

int Queue::getLength(void) {
	int length = 0;
	QueueNode* pCurrent = pHead;

	while (pCurrent != NULL) {
		length++;
		pCurrent = pCurrent->getNext();
	}

	return length;
}

void Queue::printQueue(void) {
	QueueNode* pCurrent = pHead;

	while (pCurrent != NULL) {
		cout << *(pCurrent->getData());

		pCurrent = pCurrent->getNext();
	}

	cout << endl;
}

int Queue::calculateTotalTime(void) {
	int sum = 0;
	QueueNode* pCurrent = pHead;

	while (pCurrent != NULL) {
		sum += pCurrent->getData()->getServiceTime();

		pCurrent = pCurrent->getNext();
	}

	return sum;
}

void Queue::serviceLeader(void) {
	pHead->getData()->decrementServiceTime();
}

bool Queue::leaderIsDone(void) const {
	return (pHead->getData()->getServiceTime() == 0);
}

void Queue::printEntrance(int currentTime) {
	cout << "Customer number " << pTail->getData()->getCustomerNumber() << " entered the " << lane << " Lane at " << currentTime << " minutes with " << *(pTail->getGroceries()) << endl;
}

void Queue::resetServed(void) {
	totalServed = 1;
}

int calculateServiceTime(GroceryList* groceries, bool express) {
	int length = groceries->getLength(), service;
	
	if (express) {
		service = 1 + length;
	}
	else {
		service = 2 + 1.5 * length;
	}

	return service;
}