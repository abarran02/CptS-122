#include "groceryItem.h"

GroceryItem::GroceryItem(string info) {
	mData = info;
	pNext = NULL;
}

GroceryItem* GroceryItem::getNext(void) const {
	return pNext;
}

void GroceryItem::setNext(GroceryItem* next) {
	pNext = next;
}

string GroceryItem::getData(void) const {
	return mData;
}