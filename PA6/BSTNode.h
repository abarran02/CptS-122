/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: Example                                             *
 * Date:                                                                       *
 *                                                                             *
 * Description: Reads Morse code conversions from file and inputs to a binary  *
 *			search tree. Then reads a string to convert from file and prints   *
 *			the Morse code equivalent to screen                                *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (MorseTable.txt): A .- [int(space)string]    *
 ******************************************************************************/

#pragma once

#include <iostream>

template <class T>
class BSTNode {
public:
	template <class T>
	friend class BST;

	BSTNode(const T& newData);
	~BSTNode();

	BSTNode<T>* getRight(void) const;
	void setRight(BSTNode<T>* const newRight);
	
	BSTNode<T>* getLeft(void) const;
	void setLeft(BSTNode<T>* const newLeft);
	
	T getData(void) const;
	void setData(const T& newData);

private:
	T mData;
	BSTNode<T>* pLeft;
	BSTNode<T>* pRight;
};

/*************************************************************
 * Function: BSTNode ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: default constructor for BSTNode class        *
 * Input parameters: const T& newData                        *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
BSTNode<T>::BSTNode(const T& newData) {
	pLeft = pRight = NULL;
	mData = newData;
}

/*************************************************************
 * Function: ~BSTNode ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: destructor for BSTNode class                 *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
BSTNode<T>::~BSTNode() {
	delete pLeft;
	delete pRight;
}

/*************************************************************
 * Function: getRight ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pRight member attribute           *
 * Input parameters: void                                    *
 * Returns: BSTNode<T>*                                      *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
BSTNode<T>* BSTNode<T>::getRight(void) const {
	return pRight;
}

/*************************************************************
 * Function: setRight ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for pRight member attribute           *
 * Input parameters: BSTNode<T>* const newRight              *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void BSTNode<T>::setRight(BSTNode<T>* const newRight) {
	pRight = newRight;
}

/*************************************************************
 * Function: getLeft ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for pLeft member attribute            *
 * Input parameters: void                                    *
 * Returns: BSTNode<T>*                                      *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
BSTNode<T>* BSTNode<T>::getLeft(void) const {
	return pLeft;
}

/*************************************************************
 * Function: setLeft ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for pLeft member attribute            *
 * Input parameters: BSTNode<T>* const newLeft               *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* const newLeft) {
	pLeft = newLeft;
}

/*************************************************************
 * Function: getData ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mData member attribute            *
 * Input parameters: void                                    *
 * Returns: T                                                *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
T BSTNode<T>::getData(void) const {
	return mData;
}

/*************************************************************
 * Function: setData ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mData member attribute            *
 * Input parameters: const T& newData                        *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void BSTNode<T>::setData(const T& newData) {
	mData = newData;
}