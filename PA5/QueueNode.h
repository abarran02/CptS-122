#pragma once

#include "Data.h"
#include "groceryList.h"

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
    GroceryList* mGroceries;
};

ostream& operator<< (ostream& lhs, const Data& rhs);