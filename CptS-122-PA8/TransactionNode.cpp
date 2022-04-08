#include "TransactionNode.h"

TransactionNode::~TransactionNode() {
	delete mpLeft;
	delete mpRight;
}

void TransactionNode::setUnits(int units) {
	mUnits = units;
}

int TransactionNode::getUnits() const {
	return mUnits;
}

void TransactionNode::printData() {
	cout << "Product: " << mData << endl;
	cout << "Units: " << mUnits << endl;
}

ostream& operator<<(ostream& lhs, const TransactionNode& rhs) {
	lhs  << rhs.getData() << endl << rhs.getUnits() << endl;

	return lhs;
}