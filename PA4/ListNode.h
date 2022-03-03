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

 /*
 * helped significantly by the following post:
 * https://stackoverflow.com/questions/2079296/c-templates-linkedlist
 * post did not include many methods but was helpful for general structure
 */

template <class T> class ListNode {
private:
	T mData;
	ListNode* pNext;
public:
	// constructors
	ListNode();
	ListNode(T info);

	T getData(void);
	T* getDataPtr(void);
	void setData(T info);
	ListNode* getNext(void) const;
	void setNext(ListNode* next);
};

/*************************************************************
 * Function: ListNode ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: constructor for ListNode class               *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
ListNode<T>::ListNode() {
	pNext = NULL;
}

/*************************************************************
 * Function: ListNode ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: constructor for ListNode class with init data*
 * Input parameters: T info                                  *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
ListNode<T>::ListNode(T info) {
	mData = info;
	pNext = NULL;
}

/*************************************************************
 * Function: getData ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: exposes mData member attribute                *
 * Input parameters: void                                    *
 * Returns: T                                                *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
T ListNode<T>::getData(void) {
	return mData;
}

/*************************************************************
 * Function: getDataPtr ()                                   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: exposes pointer to data member attribute     *
 * Input parameters: void                                    *
 * Returns: T*                                               *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
T* ListNode<T>::getDataPtr(void) {
	return &mData;
}

/*************************************************************
 * Function: setData ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: sets data member attribute                   *
 * Input parameters: T info                                  *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void ListNode<T>::setData(T info) {
	mData = info;
}

/*************************************************************
 * Function: getNext ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: exposes pointer to next element in list      *
 * Input parameters: void                                    *
 * Returns: ListNode<T>*                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
ListNode<T>* ListNode<T>::getNext(void) const {
	return pNext;
}

/*************************************************************
 * Function: getNext ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: sets pointer to next element in list         *
 * Input parameters: ListNode* next                          *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void ListNode<T>::setNext(ListNode* next) {
	pNext = next;
}