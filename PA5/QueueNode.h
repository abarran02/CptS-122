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

#include "Data.h"
#include "GroceryList.h"

class QueueNode {
public:
    QueueNode(int customerNumber, int serviceTime, int totalTime, GroceryList* groceries);
    ~QueueNode();

    Data* getData(void) const;

    GroceryList* getGroceries(void) const;

    QueueNode* getNext(void) const;
    void setNext(QueueNode* next);
private:
    Data* pData;
    QueueNode* pNext;
    GroceryList* pGroceries;
};

ostream& operator<< (ostream& lhs, const Data& rhs);