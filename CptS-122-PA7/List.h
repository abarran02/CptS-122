#pragma once

#include "Node.h"
#include "Data.h"

template <class T>
class List {
public:
	List();
	~List();

	bool isEmpty();
	void clearList();
	Node<T>* getHead();

	bool insertAtFront(T& data);

private:
	Node<T>* pHead;
};

template <class T>
List<T>::List() {
	pHead = NULL;
}

template <class T>
List<T>::~List() {
	delete pHead;
}

template <class T>
bool List<T>::isEmpty() {
	return (pHead == NULL);
}

template <class T>
void List<T>::clearList() {
	if (!isEmpty()) {
		delete pHead;
	}

	pHead = NULL;
}

template <class T>
Node<T>* List<T>::getHead() {
	return pHead;
}

template <class T>
bool List<T>::insertAtFront(T& data) {
	Node<T>* pNew = new Node<T>(data);

	// check memory successfully allocated
	if (pNew != 0) {
		if (isEmpty()) {
			pHead = pNew;
		}
		else {
			pNew->setNext(pHead);
			pHead = pNew;
		}

		return true;
	}

	return false;
}