// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
#include "Stack.h"
using namespace std;
#include <iostream>

template <typename T>
Stack<T>::Stack(void)
	:topOfStack(-1),
	stackSize(0)
{
	topOfStack = -1;
	stackSize = 10;
	stack_data_ =new Array<T>(stackSize);
}

//
// Stack
//
template <typename T>
Stack <T>::Stack(const Stack& stack)
{
	cout << "copy constructor called";
	stackSize = stack.stackSize;
	topOfStack = stack.topOfStack;
	stack_data_ = new Array<T>(stackSize);
	for (size_t i = 0; i < stackSize; i++) {
		stack_data_->data_[i] = stack.stack_data_->data_[i];
	}
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack(void)
{
	delete[] stack_data_->data_;
}

//
// push
//
template <typename T>
void Stack <T>::push(T element)
{
	// COMMENT There is no max size to the stack. The stack will fail if we
	// push more items than the size of the underlying array.
	

	if (topOfStack != stackSize) { // new implementation : keeping track of underlying array
		topOfStack++;
		stack_data_->data_[topOfStack] = element;
		//cout << "item pushed";
	}
	// old implementation
	/*topOfStack++;
	stack_data_[topOfStack] = element;
	cout << "item pushed";*/
}

//
// pop
//
template <typename T>
void Stack <T>::pop(void)
{
	// Empty Stack Exception
	if (topOfStack == -1) {
		throw empty_exception ();
	}
	topOfStack--;
}

//
// operator =
//
template <typename T>
const Stack <T>& Stack <T>::operator = (const Stack& rhs)
{
	if (this != &rhs) {
		delete[] stack_data_->data_;
		stackSize = rhs.stackSize;
		topOfStack = rhs.topOfStack;
		stack_data_ = new Array<T>(stackSize);
		for (size_t i = 0; i < stackSize; ++i)
			stack_data_->data_[i] = rhs.stack_data_->data_[i];
	}
	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear(void)
{
	// COMMENT Just reset the variables instead popping each element, which
	// is expensive.

	//old implementation
	//Pop out all the elements until stack isn't empty
	/*while (!is_empty()) {
		this->pop();
	}*/
	////new implementation : reseting the state 
	delete[] stack_data_->data_;
	stack_data_->data_ = {}; //default constructed stack
	topOfStack = -1;
}
