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