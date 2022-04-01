#pragma once

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	Stack(const Stack& copy);

	bool push(T data);
	bool pop(T &data);
	bool peek(T& data);
	bool isEmpty();

private:
	T mStack[100];
	int mLength;
};

template <class T>
Stack<T>::Stack() {
	mLength = 0;
}

template <class T>
Stack<T>::~Stack() {
	delete[] mStack;
}

template <class T>
Stack<T>::Stack(const Stack& copy) {
	mLength = copy.mLength;

	for (int i = 0; i < copy.mLength; i++) {
		mStack[i] = copy.mStack[i];
	}
}

template <class T>
bool Stack<T>::push(T data) {
	// check that data can still be pushed to array
	if (mLength == 100) {
		return false;
	}

	mStack[mLength] = data;

	mLength++;
	return true;
}

template <class T>
bool Stack<T>::pop(T& data) {
	// get data from first element and check if stack is empty
	if (!peek(data)) {
		return false;
	}

	mLength--;
	return true;
}

template <class T>
bool Stack<T>::peek(T& data) {
	if (isEmpty()) {
		return false;
	}

	data = mStack[mLength - 1];
	return true;
}

template <class T>
bool Stack<T>::isEmpty() {
	return (mLength == 0);
}