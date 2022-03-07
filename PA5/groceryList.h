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

#pragma once

#include "GroceryItem.h"
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
	GroceryList(const GroceryList& copyList);
	~GroceryList();

	bool isEmpty(void);
	bool insertAtFront(string info);
	bool insertAtEnd(string info);

	GroceryItem* getHead(void) const;

	int getLength(void) const;
};

GroceryList* generateRandomList(void);
ostream& operator<< (ostream& lhs, const GroceryList& rhs);
