/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA7                                                 *
 * Date: 04/06/2022                                                            *
 *                                                                             *
 * Description: Read class list from .csv and modify absences for each student *
 *		and re-store the data in a relevent .txt format. Used data structures  *
 *		include stacks and linked lists.                                       *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (classList.csv): see csv header              *
 ******************************************************************************/

#pragma once

#include "Node.h"
#include "Data.h"

template <class T>
class List {
public:
	List();
	~List();

	bool isEmpty();
	void clearList();
	Node<T>* getHead();

	bool insertAtFront(T& data);

private:
	Node<T>* pHead;
};

/*************************************************************
 * Function: List ()                                         *
 * Description: default constructor for List class           *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
List<T>::List() {
	pHead = NULL;
}

/*************************************************************
 * Function: ~List ()                                        *
 * Description: destructor for List class                    *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
List<T>::~List() {
	delete pHead;
}

/*************************************************************
 * Function: isEmpty ()                                      *
 * Description: determines whether list is empty             *
 * Input parameters:                                         *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
bool List<T>::isEmpty() {
	return (pHead == NULL);
}

/*************************************************************
 * Function: clearList ()                                    *
 * Description: deletes all Nodes in list and resets pHead   *
 *		to NULL                                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void List<T>::clearList() {
	if (!isEmpty()) {
		delete pHead;
		pHead = NULL;
	}
}

/*************************************************************
 * Function: getHead ()                                      *
 * Description: get head pointer of list                     *
 * Input parameters:                                         *
 * Returns: Node<T>*                                         *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
Node<T>* List<T>::getHead() {
	return pHead;
}

/*************************************************************
 * Function: insertAtFront ()                                *
 * Description: inserts new data at front of List            *
 * Input parameters: T& data                                 *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions: returns true if allocated successfully,   *
 *		false otherwise                                      *
 *************************************************************/
template <class T>
bool List<T>::insertAtFront(T& data) {
	Node<T>* pNew = new Node<T>(data);

	// check memory successfully allocated
	if (pNew != 0) {
		if (isEmpty()) {
			pHead = pNew;
		}
		else {
			pNew->setNext(pHead);
			pHead = pNew;
		}

		return true;
	}

	return false;
}