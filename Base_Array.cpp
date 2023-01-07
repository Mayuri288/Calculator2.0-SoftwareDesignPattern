// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Base_Array.h"
#include <iostream>
using namespace std;
#include <stdexcept>         // for std::out_of_bounds exception
//
// Array
//

template <typename T>
Base_Array <T>::Base_Array(void) :
	data_(nullptr),
	cur_size_(0),
	max_size_(0)

{
	cur_size_ = 0;
	max_size_ = 10;
	data_ = new T[cur_size_];
}


/*Array (size_t)*/

template <typename T>
Base_Array <T>::Base_Array(size_t length) :
	data_(nullptr),
	cur_size_(0),
	max_size_(0)
{
	cur_size_ = length;
	max_size_ = length;
	data_ = new T[cur_size_];
}

//
// Array (size_t, char)
//
template <typename T>
Base_Array <T>::Base_Array(size_t length, T fill) :
	data_(nullptr),
	cur_size_(0),
	max_size_(0)
{
	cur_size_ = length;
	max_size_ = length;
	data_ = new T[cur_size_];
	for (size_t i = 0;i < length;i++) {
		data_[i] = fill;
	}
}


// Array (const Array &)
//
template <typename T>
Base_Array <T>::Base_Array(const Base_Array& array)
{
	cur_size_ = array.cur_size_;
	max_size_ = array.max_size_;
	data_ = new T[cur_size_];
	for (size_t i = 0; i < cur_size_; i++) {
		data_[i] = array.data_[i];
	}
}

//
// ~Array
//
template <typename T>
Base_Array <T>::~Base_Array(void)
{
	delete[] data_;
}

//
// operator =
//
template <typename T>
const Base_Array <T>& Base_Array <T>::operator = (const Base_Array& rhs)
{
	if (this != &rhs) {
		if (cur_size_ != rhs.cur_size_) {
			delete[] data_;
			cur_size_ = rhs.cur_size_;
			data_ = new T[cur_size_];
		}
		for (size_t i = 0; i < cur_size_; ++i)
			data_[i] = rhs.data_[i];
	}
	return *this;
}

//
// operator []
//
template <typename T>
T& Base_Array <T>::operator [] (size_t index)
{
	if (index > cur_size_) {
		throw std::out_of_range("Exception");

	}
	return data_[index];
}

//
// operator [] 
//
template <typename T>
const T& Base_Array <T>::operator [] (size_t index) const
{
	return data_[index];
}

//
// get
//
template <typename T>
T Base_Array <T>::get(size_t index) const
{
	if (index >= cur_size_) {
		throw std::out_of_range("Exception");

	}
	return data_[index];
}

//
// set
//
template <typename T>
void Base_Array <T>::set(size_t index, T value)
{
	if (index < 0 || index >= cur_size_) {
		throw std::out_of_range("Exception");

	}
	data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Base_Array <T>::find(T value) const
{
	for (size_t i = 0;i < cur_size_;i++) {
		if (data_[i] == value) {
			cout << "Found\n";
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Base_Array <T>::find(T val, size_t start) const
{
	if (start < 0 || start >= cur_size_) {
		throw std::out_of_range("Exception");
	}
	else {
		for (size_t i = start;i < cur_size_;i++) {
			if (data_[i] == val) {
				cout << "Found";
				return i;

			}
		}
	}
	return -1;
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array& rhs) const
{
	if (cur_size_ == rhs.cur_size_) {
		for (size_t i = 0; i < cur_size_; i++) {
			if (data_[i] != rhs.data_[i])
				return false;
		}
		return true;
	}
	return false;
}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array& rhs) const
{
	if (cur_size_ == rhs.cur_size_) {
		for (size_t i = 0; i < cur_size_; i++) {
			if (data_[i] != rhs.data_[i])
				return true;
		}
		return false;
	}
	return true;
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill(T value)
{
	for (size_t i = 0;i < cur_size_;i++) {
		data_[i] = value;
	}
}
