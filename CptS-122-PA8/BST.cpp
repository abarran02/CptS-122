/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA8                                                 *
 * Date:                                                                       *
 *                                                                             *
 * Description: Reads product buying and selling data from file, place data in *
 *			binary search trees. Then run data analysis on the input.          *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (data.csv): Units,Type,Transaction           *
 ******************************************************************************/

#include "BST.h"

/*************************************************************
 * Function: BST ()                                          *
 * Description: default constructor for BST class            *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
BST::BST() {
	mpRoot = NULL;
}

/*************************************************************
 * Function: ~BST ()                                         *
 * Description: destructor for BST class                     *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
BST::~BST() {
	destroyTree();
}

/*************************************************************
 * Function: ~BST ()                                         *
 * Description: helper function to destroy for BST class     *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void BST::destroyTree() {
	delete mpRoot;
}

/*************************************************************
 * Function: setRoot ()                                      *
 * Description: setter for mpRoot                            *
 * Input parameters: Node*& pRoot                            *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void BST::setRoot(Node*& pRoot) {
	mpRoot = pRoot;
}

/*************************************************************
 * Function: getRoot ()                                      *
 * Description: getter for mpRoot                            *
 * Input parameters:                                         *
 * Returns: Node*& pRoot                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
Node*& BST::getRoot() {
	return mpRoot;
}

/*************************************************************
 * Function: insert ()                                       *
 * Description: helper function to insert new data into      *
 *		binary tree                                          *
 * Input parameters: const string& data, const int& units    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void BST::insert(const string& data, const int& units) {
	insert(mpRoot, data, units);
}

/*************************************************************
 * Function: insert ()                                       *
 * Description: insert new data into binary tree             *
 * Input parameters: Node*& pTree, const string& data,       *
 *		const int& units                                     *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void BST::insert(Node*& pTree, const string& data, const int& units) {
	TransactionNode* pMem = dynamic_cast<TransactionNode*> (pTree);

	// base case if tree is empty
	if (pTree == NULL) {
		mpRoot = new TransactionNode(data, units);
	}
	else {
		// right side of tree
		if (pMem->getUnits() < units) {
			// right side empty
			if (pTree->getRight() == NULL) {
				pTree->setRight(new TransactionNode(data, units));
			}
			else {
				// recursive step
				insert(pTree->getRight(), data, units);
			}
		}
		// left side of tree
		else if (units < pMem->getUnits()) {
			// left side empty
			if (pTree->getLeft() == NULL) {
				pTree->setLeft(new TransactionNode(data, units));
			}
			else {
				// recursive step
				insert(pTree->getLeft(), data, units);
			}
		}
	}
}

/*************************************************************
 * Function: print ()                                        *
 * Description: helper function to print tree to screen      *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void BST::inOrderTraversal() {
	inOrderTraversal(mpRoot);
}

/*************************************************************
 * Function: inOrderTraversal ()                             *
 * Description: traverses binary tree in order to print      *
 *		contents to screen                                   *
 * Input parameters: Node* pTree                             *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void BST::inOrderTraversal(Node* pTree) {
	// left, current, right
	if (pTree != NULL) {
		inOrderTraversal(pTree->getLeft());
		pTree->printData();
		inOrderTraversal(pTree->getRight());
	}
}

/*************************************************************
 * Function: findSmallest ()                                 *
 * Description: traverses binary tree to find smallest data  *
 * Input parameters:                                         *
 * Returns: TransactionNode&                                 *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
TransactionNode& BST::findSmallest() {
	TransactionNode* pCurrent = dynamic_cast<TransactionNode*> (mpRoot);
	while (pCurrent->getLeft() != NULL) {
		pCurrent = dynamic_cast<TransactionNode*> (pCurrent->getLeft());
	}

	return *pCurrent;
}

/*************************************************************
 * Function: findLargest ()                                  *
 * Description: traverses binary tree to find largest data   *
 * Input parameters:                                         *
 * Returns: TransactionNode&                                 *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
TransactionNode& BST::findLargest() {
	TransactionNode* pCurrent = dynamic_cast<TransactionNode*> (mpRoot);
	while (pCurrent->getRight() != NULL) {
		pCurrent = dynamic_cast<TransactionNode*> (pCurrent->getRight());
	}

	return *pCurrent;
}