//
// Created by kamil on 3/30/17.
//

#ifndef KROLIB_ARRAY_H
#define KROLIB_ARRAY_H

enum SizeManagement {
	Static, Dynamic
};

class OutOfRangeException {
};

class NegativeArraySizeException {
};

template<class Type>
class Array {
	class wrapper {
	public:
		wrapper(Array<Type> *arr, size_t index) : index(index), arr(arr) {}

		operator Type() const {
			if (index < arr->size && index >= 0)
				return *(this->arr->array + index);
			throw OutOfRangeException();
		}

		wrapper &operator=(const Type &newObject) {
			if (index < arr->size && index >= 0) {
				*(arr->array + index) = newObject;
				return *this;
			}
			if (arr->sizeManagement == Static || arr->size < 0)
				throw OutOfRangeException();
			while (index >= arr->size) arr->resizeArray();
			arr->array[index] = newObject;
			return *this;
		}

	private:
		size_t index;
		Array<Type> *arr;
	};

public:
	Array();

	explicit Array(size_t, SizeManagement = Static);

	~Array();

	wrapper operator[](size_t index);

	const Type &operator[](size_t index) const;

	size_t Size() const;

private:
	void resizeArray();

	SizeManagement sizeManagement;
	Type *array;
	size_t size;
	Type *lastPtr;
};

template<class Type>
Array<Type>::Array(size_t size, SizeManagement sizeManagement) {
	if (size < 0) throw NegativeArraySizeException();
	array = new Type[size]();
	this->size = size;
	lastPtr = array + size - 1;
	this->sizeManagement = sizeManagement;
}

template<class Type>
Array<Type>::Array() : Array(1, Dynamic) {}

template<class Type>
Array<Type>::~Array() {
	if (array) delete[] array;
}

template<class Type>
typename Array<Type>::wrapper Array<Type>::operator[](size_t index) {
	return wrapper(this, index);
}

template<class Type>
const Type &Array<Type>::operator[](size_t index) const {
	if (index < size && index >= 0)
		return *(array + index);
	throw OutOfRangeException();
}


template<class Type>
size_t Array<Type>::Size() const {
	return size;
}

template<class Type>
void Array<Type>::resizeArray() {
	size_t newSize;
	if (size > 0)
		newSize = size * 2;
	else
		newSize = 1;
	Type *newArray = new Type[newSize]();
	Type *oldPtr = array;
	Type *newPtr = newArray;
	for (int i = 0; i < size; ++i)
		*(newPtr++) = *(oldPtr++);
	delete[] array;
	array = newArray;
	size = newSize;
	lastPtr = array + size - 1;

}


#endif //KROLIB_ARRAY_H