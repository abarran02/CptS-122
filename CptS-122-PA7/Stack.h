/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA7                                                 *
 * Date: 04/06/2022                                                            *
 *                                                                             *
 * Description: Read class list from .csv and modify absences for each student *
 *		and re-store the data in a relevent .txt format. Used data structures  *
 *		include stacks and linked lists.                                       *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (classList.csv): see csv header              *
 ******************************************************************************/

#pragma once

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	Stack(const Stack& copy);

	bool push(T data);
	bool pop(T &data);
	bool peek(T& data) const;
	bool isEmpty() const;

private:
	T mStack[100];
	int mLength;
};

/*************************************************************
 * Function: Stack ()                                        *
 * Description: default constructor for Stack class          *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
Stack<T>::Stack() {
	mLength = 0;
}

/*************************************************************
 * Function: ~Stack ()                                       *
 * Description: destructor for Stack class                   *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
Stack<T>::~Stack() {
	//delete [] mStack;
}

/*************************************************************
 * Function: Stack ()                                        *
 * Description: copy constructor for Stack class             *
 * Input parameters: const Stack& copy                       *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
Stack<T>::Stack(const Stack& copy) {
	mLength = copy.mLength;

	for (int i = 0; i < copy.mLength; i++) {
		mStack[i] = copy.mStack[i];
	}
}

/*************************************************************
 * Function: push ()                                         *
 * Description: push new data to top of Stack                *
 * Input parameters: T data                                  *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions: returns false if Stack full, else true    *
 *************************************************************/
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

/*************************************************************
 * Function: pop ()                                          *
 * Description: get and delete data from top of Stack        *
 * Input parameters: T& data                                 *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions: true if popped successfully, else false   *
 *************************************************************/
template <class T>
bool Stack<T>::pop(T& data) {
	// get data from first element and check if stack is empty
	if (!peek(data)) {
		return false;
	}

	mLength--;
	return true;
}

/*************************************************************
 * Function: peek ()                                         *
 * Description: get data from top of Stack                   *
 * Input parameters: T& data                                 *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions: true if peeked successfully, else false   *
 *************************************************************/
template <class T>
bool Stack<T>::peek(T& data) const {
	if (this->isEmpty()) {
		return false;
	}

	data = mStack[mLength - 1];
	return true;
}

/*************************************************************
 * Function: isEmpty ()                                      *
 * Description: determines whether Stack is empty            *
 * Input parameters:                                         *
 * Returns: bool                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
template <class T>
bool Stack<T>::isEmpty() const {
	return (mLength == 0);
}