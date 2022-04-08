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