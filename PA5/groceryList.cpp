#include "groceryList.h"

GroceryList::GroceryList() {
	pHead = NULL;
}

GroceryList::~GroceryList() {
	GroceryItem* pCurrent = pHead, * pDel;

	while (pCurrent != NULL) {
		pDel = pCurrent;

		pCurrent = pCurrent->getNext();
		delete pDel;
	}
}

bool GroceryList::isEmpty(void) {
	return (pHead == NULL);
}

void GroceryList::append(string info) {
	GroceryItem* newItem = new GroceryItem(info);

	// if list is empty, set pHead to the new item
	if (this->isEmpty()) {
		pHead = newItem;
	}
	// otherwise insert new item at front
	else {
		newItem->setNext(pHead);
		pHead = newItem;
	}
}

GroceryItem* GroceryList::getHead(void) const{
	return pHead;
}

int GroceryList::getLength(void) const {
	int length = 0;
	GroceryItem* pCurrent = pHead;

	while (pCurrent != NULL) {
		length++;
		pCurrent = pCurrent->getNext();
	}

	return length;
}

GroceryList* generateRandomList(void) {
	int randInt;
	string foodStuffs[5] = { "banana", "cereal", "milk", "tomato", "chocolate" };
	GroceryList* randList = new GroceryList();

	for (int i = 0; i < 5; i++) {
		randInt = rand() % 2;

		if (randInt) {
			randList->append(foodStuffs[i]);
		}
	}

	// if nothing was added to the list
	if (randList->isEmpty()) {
		randList->append("cigarettes");
	}

	return randList;
}

ostream& operator<< (ostream& lhs, const GroceryList& rhs) {
	GroceryItem* pCurrent = rhs.getHead();

	while (pCurrent != NULL) {
		lhs << pCurrent->getData();

		if (pCurrent->getNext() != NULL) {
			lhs << ", ";
		}

		pCurrent = pCurrent->getNext();
	}

	return lhs;
}