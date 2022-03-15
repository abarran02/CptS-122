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

#include "BSTNode.h"
#include <iostream>

using std::cout;
using std::endl;

template <class T>
class BST {
public:
	BST();
	BST(BSTNode<T>* newRoot);
	~BST();

	void insert(const T& newData);
	BSTNode<T>* search(T query);
	void print(void);

private:
	BSTNode<T>* pRoot;

	void insert(BSTNode<T>* pTree, const T& newData);
	BSTNode<T>* search(BSTNode<T>* pTree, T query);
	void inOrderTraversal(BSTNode<T>* pTree);
};

template <class T>
BST<T>::BST() {
	pRoot = NULL;
}

template <class T>
BST<T>::BST(BSTNode<T>* newRoot) {
	pRoot = newRoot;
}

template <class T>
BST<T>::~BST() {
	delete pRoot;
}

template <class T>
void BST<T>::insert(const T& newData) {
	insert(pRoot, newData);
}

template <class T>
void BST<T>::insert(BSTNode<T>* pTree, const T& newData) {
	// base case if tree is empty
	if (pTree == NULL) {
		pRoot = new BSTNode<T>(newData);
	}
	else {
		// right side of tree
		if (pTree->mData < newData) {
			// right side empty
			if (pTree->pRight == NULL) {
				pTree->setRight(new BSTNode<T>(newData));
			}
			else {
				// recursive step
				insert(pTree->pRight, newData);
			}
		}
		// left side of tree
		else if (newData < pTree->mData) {
			// left side empty
			if (pTree->pLeft == NULL) {
				pTree->setLeft(new BSTNode<T>(newData));
			}
			else {
				// recursive step
				insert(pTree->pLeft, newData);
			}
		}
		// duplicate
		else {
			cout << "duplicate: " << newData << endl;
		}
	}
}

template<class T>
BSTNode<T>* BST<T>::search(T query) {
	return search(pRoot, query);
}

template<class T>
BSTNode<T>* BST<T>::search(BSTNode<T>* pTree, T query) {
	// check that pTree is not NULL
	if (pTree != NULL) {
		// if match found
		if (pTree->getData() == query) {
			return pTree;
		}
		// not found, must traverse pTree
		else {
			// traverse left subtree
			BSTNode<T>* foundNode = search(pTree->getLeft(), query);
			// not found in left subtree, must traverse right subtree
			if (foundNode == NULL) {
				foundNode = search(pTree->getRight(), query);
			}

			// will either return a matching BSTNode or NULL
			return foundNode;
		}
	}
	else {
		return NULL;
	}
}

template<class T>
void BST<T>::print(void) {
	inOrderTraversal(pRoot);
}

template<class T>
void BST<T>::inOrderTraversal(BSTNode<T>* pTree) {
	// left, current, right
	if (pTree != NULL) {
		inOrderTraversal(pTree->getLeft());
		cout << pTree->getData() << endl;
		inOrderTraversal(pTree->getRight());
	}
}