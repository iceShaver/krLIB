//
// Created by kamil on 3/30/17.
// Vector of POINTERS!!!!!
//

#ifndef KROLIB_VECTOR_H
#define KROLIB_VECTOR_H

#include <cstddef>
#include "Exception.h"

enum SizeManagement {
	Static, Dynamic
};

template<class Type>
class Vector {
	class wrapper {
	public:
		wrapper(Vector<Type> *arr, size_t index) : index(index), arr(arr) {}
		operator Type*() const;
		explicit operator Type() const;
		wrapper& operator=(Type* newObject);
	private:
		size_t index;
		Vector<Type> *arr;
	};

public:
	Vector();
	explicit Vector(size_t initSize, SizeManagement = Static);
	~Vector();
	wrapper operator[](size_t index);
	const Type*operator[](size_t index) const;
	Type * GetLast();
	size_t getSize() const;

private:
	void resizeArray();
	SizeManagement sizeManagement;
	Type **array;
	size_t size;
	Type **lastPtr;
};

template<class Type>
Vector<Type>::Vector() : Vector(1, Dynamic) {}

template<class Type>
Vector<Type>::Vector(size_t size, SizeManagement sizeManagement) {
	if (size < 0) throw NegativeArraySizeException();
	array = new Type*[size]();
	this->size = size;
	lastPtr = array + size - 1;
	this->sizeManagement = sizeManagement;
}
template<class Type>
Vector<Type>::~Vector() {
	for (int i = 0; i < size; ++i)
		delete array[i];
	delete[] array;
}
template <class Type>
Vector<Type>::wrapper::operator Type*() const
{
	if (index < arr->size && index >= 0)
		return *(this->arr->array + index);
	throw OutOfRangeException();
}

template <class Type>
Vector<Type>::wrapper::operator Type() const
{
	if (index < arr->size && index >= 0)
		return **(this->arr->array + index);
	throw OutOfRangeException();
}

template <class Type>
typename Vector<Type>::wrapper& Vector<Type>::wrapper::operator=(Type* newObject)
{
	if (index < arr->size && index >= 0)
	{
		*(arr->array + index) = newObject;
		return *this;
	}
	if (arr->sizeManagement == Static || arr->size < 0)
		throw OutOfRangeException();
	while (index >= arr->size) arr->resizeArray();
	arr->array[index] = newObject;
	return *this;
}



template<class Type>
typename Vector<Type>::wrapper Vector<Type>::operator[](size_t index) {
	return wrapper(this, index);
}

template<class Type>
const Type *Vector<Type>::operator[](size_t index) const {
	if (index < size && index >= 0)
		return *(array + index);
	throw OutOfRangeException();
}

template <class Type>
Type* Vector<Type>::GetLast()
{
	return *lastPtr;
}


template<class Type>
size_t Vector<Type>::getSize() const {
	return size;
}

template<class Type>
void Vector<Type>::resizeArray() {
	size_t newSize;
	if (size > 0)
		newSize = size * 2;
	else
		newSize = 1;
	Type **newArray = new Type*[newSize]();
	Type **oldPtr = array;
	Type **newPtr = newArray;
	for (int i = 0; i < size; ++i)
		*(newPtr++) = *(oldPtr++);
	delete[] array;
	array = newArray;
	size = newSize;
	lastPtr = array + size - 1;

}



#endif //KROLIB_VECTOR_H
