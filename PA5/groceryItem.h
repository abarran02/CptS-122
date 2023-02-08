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