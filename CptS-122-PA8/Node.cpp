#include "Node.h"

Node::Node(string data) {
	mData = data;
	mpLeft = NULL;
	mpRight = NULL;
}

Node::~Node() {
	delete mpLeft;
	delete mpRight;
}

void Node::setData(string data) {
	mData = data;
}

string Node::getData() const {
	return mData;
}

void Node::setLeft(Node* pLeft) {
	mpLeft = pLeft;
}

Node*& Node::getLeft() {
	return mpLeft;
}

void Node::setRight(Node* pRight) {
	mpRight = pRight;
}

Node*& Node::getRight() {
	return mpRight;
}