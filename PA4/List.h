/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA4                                                 *
 * Date: 03/02/2022                                                            *
 *                                                                             *
 * Description: Read and write diet and exercise plans to text files, and edit *
 *		their and display their contents in C++ using classes                  *
 * 		and class templates.                                                   *
 *                                                                             *
 * Format of record in input file (dietPlans.txt):                             *
 *                                                Bulking      (string name)   *
 *                                                3400         (int goal)      *
 *                                                03/04/2021   (string date)   *
 *                                                                             *
 * Format of output file (dietPlans.txt): Same as input.                       *
 ******************************************************************************/

#pragma once

#include <iostream>
#include "ListNode.h"

/*
* helped significantly by the following post:
* https://stackoverflow.com/questions/2079296/c-templates-linkedlist
* post did not include many methods but was helpful for general structure
*/

template <class T> class List {
private:
	ListNode<T>* pHead, * pTail;
public:
	// constructor
	List();
	// destructor
	~List();
	// copy constructor
	List(const List& info);

	void append(T info);
	ListNode<T>* getHead(void) const;
	ListNode<T>* getTail(void) const;
	ListNode<T>* getNthItem(int n);
};

/*************************************************************
 * Function: List ()                                         *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: constructor for List class                   *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
List<T>::List() {
	pHead = NULL;
	pTail = NULL;
}

/*************************************************************
 * Function: ~List ()                                        *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: destructor for List class that deletes all   *
 *		elements of the list                                 *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
List<T>::~List() {
	ListNode<T>* pCurrent = pHead, * pDel;

	// loop through list and delete each element
	while (pCurrent != NULL) {
		pDel = pCurrent;
		pCurrent = pCurrent->getNext();

		delete pDel;
	}
}

/*************************************************************
 * Function: List ()                                         *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: copy constructor for list class              *
 * Input parameters: const List& info                        *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
List<T>::List(const List& info) {
	pHead = info.pHead;
	pTail = info.pTail;
}

/*************************************************************
 * Function: append ()                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: appends a ListNode<T>* to the end of the list*
 *		and instantiates it with parameter data              *
 * Input parameters: T info                                  *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void List<T>::append(T info) {
	// if list is empty
	if (pHead == NULL) {
		pHead = new ListNode<T>;
		pHead->setData(info);
		pTail = pHead;
	}
	else {
		// create new Node and set as tail
		ListNode<T>* pNew = new ListNode<T>;
		pNew->setData(info);
		pTail->setNext(pNew);
		pTail = pNew;
	}
}

/*************************************************************
 * Function: getHead ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: returns List head pointer                    *
 * Input parameters: void                                    *
 * Returns: ListNode<T>*                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
ListNode<T>* List<T>::getHead(void) const {
	return pHead;
}

/*************************************************************
 * Function: getTail ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: returns List tail pointer                    *
 * Input parameters: void                                    *
 * Returns: ListNode<T>*                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
ListNode<T>* List<T>::getTail(void) const {
	return pTail;
}

/*************************************************************
 * Function: getNthItem ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: returns pointer to the nth item in the list  *
 * Input parameters: n                                       *
 * Returns: ListNode<T>*                                     *
 * Preconditions: 0 <= n <= list length - 1                  *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
ListNode<T>* List<T>::getNthItem(int n) {
	ListNode<T>* pCurrent = pHead;

	// loop through list until nth item
	for (int i = 0; i < n; i++) {
		// n is greater than the number of items in the list
		if (pCurrent == NULL) {
			break;
		}

		// increment list
		pCurrent = pCurrent->getNext();
	}

	return pCurrent;
}