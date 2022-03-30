#pragma once

template <class T>
class Node {
public:
	Node(T data);
	~Node();

	void setNext(Node<T>* next);
	Node<T>* getNext();

	T getData();
private:
	T mData;
	Node<T>* pNext;
};

template <class T>
Node<T>::Node(T data) {
	mData = data;
	pNext = NULL;
}

template <class T>
Node<T>::~Node() {
	delete pNext;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
	pNext = next;
}

template <class T>
Node<T>* Node<T>::getNext() {
	return pNext;
}

template <class T>
T Node<T>::getData() {
	return mData;
}