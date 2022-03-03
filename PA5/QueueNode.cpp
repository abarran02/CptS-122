#include "QueueNode.h"

QueueNode::QueueNode(int customerNumber, int serviceTime, int totalTime, GroceryList* groceries) {
	pData = new Data(customerNumber, serviceTime, totalTime);
	pNext = NULL;
	mGroceries = groceries;
}

QueueNode::~QueueNode() {
	delete mGroceries;
	delete pData;
}

Data* QueueNode::getData(void) const {
	return pData;
}

GroceryList* QueueNode::getGroceries(void) const {
	return mGroceries;
}

QueueNode* QueueNode::getNext(void) const {
	return pNext;
}

void QueueNode::setNext(QueueNode* next) {
	pNext = next;
}
