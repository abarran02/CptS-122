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

    void serviceLeader(void);
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