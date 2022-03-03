#pragma once

#include "groceryItem.h"
#include <ctime>
#include <cstdlib>

using std::rand;
using std::ostream;
using std::endl;

class GroceryList {
private:
	GroceryItem* pHead;
public:
	GroceryList();
	~GroceryList();

	bool isEmpty(void);
	void append(string info);

	GroceryItem* getHead(void) const;

	int getLength(void) const;
};

GroceryList* generateRandomList(void);
ostream& operator<< (ostream& lhs, const GroceryList& rhs);
