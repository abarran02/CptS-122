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

	BSTNode<T>* getRight() const;
	void setRight(BSTNode<T>* const newRight);
	
	BSTNode<T>* getLeft() const;
	void setLeft(BSTNode<T>* const newLeft);
	
	T getData() const;
	void setData(const T& newData);

private:
	T mData;
	BSTNode<T>* pLeft;
	BSTNode<T>* pRight;
};

template <class T>
BSTNode<T>::BSTNode(const T& newData) {
	pLeft = pRight = NULL;
	mData = newData;
}

template <class T>
BSTNode<T>::~BSTNode() {
	delete pLeft;
	delete pRight;
}

template <class T>
BSTNode<T>* BSTNode<T>::getRight() const {
	return pRight;
}

template <class T>
void BSTNode<T>::setRight(BSTNode<T>* const newRight) {
	pRight = newRight;
}

template <class T>
BSTNode<T>* BSTNode<T>::getLeft() const {
	return pLeft;
}

template <class T>
void BSTNode<T>::setLeft(BSTNode<T>* const newLeft) {
	pLeft = newLeft;
}

template <class T>
T BSTNode<T>::getData() const {
	return mData;
}

template <class T>
void BSTNode<T>::setData(const T& newData) {
	mData = newData;
}