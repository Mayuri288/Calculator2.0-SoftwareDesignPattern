// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>
using namespace std;
//
// Array
//

template <typename T>
Array <T>::Array (void):
	Base_Array<T>()

{

}


 /*Array (size_t)*/

template <typename T>
Array <T>::Array (size_t length):
	Base_Array<T>(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill):
	Base_Array<T>(length,fill)
{
	
}


// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):
	Base_Array<T>(array)
{

}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	Base_Array<T>::operator=(rhs);
	return *this;
}
//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	T* data_temp = Base_Array<T>::data_;
	if (new_size < Base_Array<T>::cur_size_) {
		Base_Array<T>::cur_size_ = new_size;
		data_temp = new T[Base_Array<T>::cur_size_];
		for (size_t i = 0;i < Base_Array<T>::cur_size_;i++) {
			data_temp[i] = Base_Array<T>::data_[i];
		}
	}
	else if (new_size > Base_Array<T>::cur_size_) {
		data_temp = new T[new_size];
		for (size_t i = 0;i < Base_Array<T>::cur_size_;i++) {
			data_temp[i] = Base_Array<T>::data_[i];
		}
		Base_Array<T>::cur_size_ = new_size;
	}
	Base_Array<T>::data_ = data_temp;
}
