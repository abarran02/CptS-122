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
	~BST();

	void insert(const T& newData);
	BSTNode<T>* search(T query);
	void print(void);

private:
	BSTNode<T>* pRoot;

	BST(BSTNode<T>* newRoot);

	void insert(BSTNode<T>* pTree, const T& newData);
	BSTNode<T>* search(BSTNode<T>* pTree, T query);
	void inOrderTraversal(BSTNode<T>* pTree);
};

/*************************************************************
 * Function: BST ()                                          *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: default constructor for BST class            *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
BST<T>::BST() {
	pRoot = NULL;
}

/*************************************************************
 * Function: BST ()                                          *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: private helper constructor for BST class     *
 * Input parameters: BSTNode<T>* newRoot                     *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
BST<T>::BST(BSTNode<T>* newRoot) {
	pRoot = newRoot;
}

/*************************************************************
 * Function: ~BST ()                                         *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: destructor for BST class                     *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
BST<T>::~BST() {
	delete pRoot;
}

/*************************************************************
 * Function: insert ()                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: helper function to insert new data into      *
 *		binary tree                                          *
 * Input parameters: const T& newData                        *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
void BST<T>::insert(const T& newData) {
	insert(pRoot, newData);
}

/*************************************************************
 * Function: insert ()                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: insert new data into binary tree             *
 * Input parameters: BSTNode<T>* pTree, const T& newData     *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
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

/*************************************************************
 * Function: search ()                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: helper function to search for data in tree   *
 * Input parameters: T query                                 *
 * Returns: BSTNode<T>*                                      *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template<class T>
BSTNode<T>* BST<T>::search(T query) {
	return search(pRoot, query);
}

/*************************************************************
 * Function: search ()                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: search for data in tree                      *
 * Input parameters: BSTNode<T>* pTree, T query              *
 * Returns: BSTNode<T>*                                      *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
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

/*************************************************************
 * Function: print ()                                        *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: helper function to print tree to screen      *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template<class T>
void BST<T>::print(void) {
	inOrderTraversal(pRoot);
}

/*************************************************************
 * Function: inOrderTraversal ()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: traverses binary tree in order to print      *
 *		contents to screen                                   *
 * Input parameters: BSTNode<T>* pTree                       *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template<class T>
void BST<T>::inOrderTraversal(BSTNode<T>* pTree) {
	// left, current, right
	if (pTree != NULL) {
		inOrderTraversal(pTree->getLeft());
		cout << pTree->getData() << endl;
		inOrderTraversal(pTree->getRight());
	}
}