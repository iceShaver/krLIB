//
// Created by kamil on 31.03.17.
//
#include <string>
#include "String.h"

String::String() : size(1), length(0), array(nullptr) {}
String::String(const char * cstring) : String() {
	length = calcCstringLength(cstring);
	while (length > size) resize();
	array = new char[size];
	Copy(cstring, array, length);
}

String::String(const String& newString) : String()
{
	length = newString.length;
	while (length > size) resize();
	array = new char[size];
	Copy(newString.array, array, length);
}

String& String::operator+(const String& appendedString)
{
	String * result = new String(*this);
	*result += appendedString;
	return *result;
}

size_t String::calcCstringLength(const char * cstring) {
	size_t length = 0;
	const char * ptr = cstring;
	while (*(ptr++)) length++;
	return length;
}

void String::resize() {
	size = 2 * size;
	if (array) {
		char * newArray = new char[size];
		char*newPtr = newArray, *oldPtr = array;
		Copy(array, newArray, length);
		delete[] array;
		array = newArray;
	}

}

String& String::operator+=(const String& appendedString)
{
	while (length + appendedString.length > size) resize();
	char * newString = new char[size];
	Copy(array, newString, length);
	Copy(appendedString, newString + length, appendedString.length);
	delete[] array;
	array = newString;
	length += appendedString.length;
	return *this;
}

String::operator const char *() const {
	char *result = new char[length + 1];
	Copy(array, result, length);
	*(result + length) = '\0';
	return result;
}

size_t String::Length() const
{
	return length;
}

size_t String::Size() const
{
	return size;
}

void String::Copy(const char * src, char * dst, size_t length) const {
	const char * srcPtr = src;
	char * dstPtr = dst;
	for (size_t i = 0; i < length; ++i)
		*(dstPtr++) = *(srcPtr++);
}
