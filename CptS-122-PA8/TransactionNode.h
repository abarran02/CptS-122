#pragma once

#include "Node.h"

using std::ostream;

class TransactionNode : public Node {
private:
	int mUnits;

public:
	TransactionNode(string data, int units) : Node(data) {
		mUnits = units;
	}
	~TransactionNode();

	void setUnits(int units);
	int getUnits() const;

	void printData();
};

ostream& operator<<(const ostream& lhs, const TransactionNode& rhs);