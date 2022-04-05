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

template <class T>
class Node {
public:
	Node(T& data);
	~Node();

	void setNext(Node<T>* next);
	Node<T>* getNext();

	T* getData();
private:
	T mData;
	Node<T>* pNext;
};

/*************************************************************
 * Function: Node ()                                         *
 * Description: default constructor for Node class           *
 * Input parameters: T& data                                 *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
Node<T>::Node(T& data) {
	mData = data;
	pNext = NULL;
}

/*************************************************************
 * Function: ~Node ()                                        *
 * Description: destructor for List class                    *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
Node<T>::~Node() {
	delete pNext;
}

/*************************************************************
 * Function: setNext ()                                      *
 * Description: setter for pNext                             *
 * Input parameters: Node<T>* next                           *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void Node<T>::setNext(Node<T>* next) {
	pNext = next;
}


/*************************************************************
 * Function: getNext ()                                      *
 * Description: getter for pNext                             *
 * Input parameters:                                         *
 * Returns: Node<T>* next                                    *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
Node<T>* Node<T>::getNext() {
	return pNext;
}

/*************************************************************
 * Function: getData ()                                      *
 * Description: getter for mData reference                   *
 * Input parameters:                                         *
 * Returns: T*                                               *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
T* Node<T>::getData() {
	return &mData;
}