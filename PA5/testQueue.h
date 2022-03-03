#pragma once

#include "Queue.h"

using std::cin;
using std::rand;

/*
- One test case that executes your enqueue() operation on an empty queue
- One test case that executes your enqueue() operation with one node in the queue
- One test case that executes your dequeue() operation on a queue with one node
- One test case that executes your dequeue() operation on a queue with two nodes
*/

void testEnqueueEmpty(void);
void testEnqueueOne(void);
void testDequeueOne(void);
void testDequeueTwo(void);

void runSimulation(int n);

int promptIntInRange(int min, int max, string message);