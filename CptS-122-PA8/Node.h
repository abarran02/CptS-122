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

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Node {
protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;

public:
	Node(string data);
	virtual ~Node();

	void setData(string data);
	string getData() const;

	void setLeft(Node* pLeft);
	Node*& getLeft();

	void setRight(Node* pRight);
	Node*& getRight();

	virtual void printData() = 0;
};