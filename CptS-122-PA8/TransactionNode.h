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

#include <fstream>
#include "Node.h"

using std::ostream;

class TransactionNode : public Node {
private:
	int mUnits;

public:
	TransactionNode(string data, int units) : Node(data) {
		mUnits = units;
	}

	void setUnits(int units);
	int getUnits() const;

	void printData();
};

ostream& operator<<(ostream& lhs, const TransactionNode& rhs);