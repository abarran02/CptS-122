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

#pragma once

#include "TransactionNode.h"

class BST {
public:
	BST();
	~BST();

	void setRoot(Node*& pRoot);
	Node*& getRoot();

	void insert(const string& data, const int& units);

	void inOrderTraversal();

	TransactionNode& findSmallest();
	TransactionNode& findLargest();

private:
	Node* mpRoot;

	void destroyTree();

	void insert(Node*& pTree, const string& data, const int& units);
	void inOrderTraversal(Node* pTree);
};