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

#include "QueueNode.h"

using std::cout;

class Queue {
public:
    Queue();
    Queue(bool express);
    ~Queue();

    QueueNode* getHead(void) const;
    QueueNode* getTail(void) const;

    bool isEmpty();

    bool enqueue(GroceryList* groceries);
    bool enqueue(GroceryList* groceries, int currentTime);
    void dequeue(void);

    int getLength(void);
    void printQueue(void);
    int calculateTotalTime(void);

    void decrementLeader(void);
    bool leaderIsDone(void) const;

    void resetServed(void);
    
private:
    QueueNode* pHead;
    QueueNode* pTail;
    int totalServed;
    bool mExpress;
    string lane;

    void printEntrance(int currentTime);
};

int calculateServiceTime(GroceryList* groceries, bool express);