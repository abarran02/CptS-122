#pragma once

#include <iostream>
#include <string>

using std::string;

class GroceryItem {
private:
	string mData;
	GroceryItem* pNext;
public:
	GroceryItem(string info);

	GroceryItem* getNext(void) const;
	void setNext(GroceryItem* next);

	string getData(void) const;
};