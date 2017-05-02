//
// Created by kamil on 31.03.17.
//
#include "String.h"
#include "Exception.h"
String::String() : capacity(1), length(0), array(nullptr) {}
String::String(const char * cstring) : capacity(1) {
	length = getCStringLength(cstring);
	capacity = length;
	//while (length > capacity) resize();
	array = new char[capacity];
	copy(cstring, array, length);
}

String::operator const char*() const
{
	char *result = new char[length + 1];
	copy(array, result, length);
	*(result + length) = '\0';
	return result;
}


String::String(const String& newString)
{
	//if (array) delete[]array;
	length = newString.length;
	capacity = newString.capacity;
	//while (length > capacity) resize();
	array = new char[capacity];
	copy(newString.array, array, length);
}

String String::parseInt(const long long& number)
{
	char * tmp = new char[128];
	int n = sprintf_s(tmp, 128, "%d", number);
	String result;
	result.array = new char[n];
	copy(tmp, result.array, n);
	delete[] tmp;
	result.capacity = result.length = n;
	return result;
}

String String::parseUInt(const unsigned long long& number)
{
	char * tmp = new char[128];
	int n = sprintf_s(tmp, 128, "%d", number);
	String result;
	result.array = new char[n];
	copy(tmp, result.array, n);
	delete[] tmp;
	result.capacity = result.length = n;
	return result;
}

String String::parseCString(const char*cstring)
{
	size_t size = getCStringLength(cstring);
	String result;
	result.array = new char[size];
	result.capacity = result.length = size;
	copy(cstring, result.array, size);
	return result;
}


String String::parseDouble(const long double& number, const char *const format)
{
	char * tmp = new char[128];
	int n;
	if (format)
		n = sprintf_s(tmp, 128, format, number);
	else
		n = sprintf_s(tmp, 128, "%f", number);
	String result;
	result.array = new char[n];
	copy(tmp, result.array, n);
	delete[] tmp;
	result.capacity = result.length = n;
	return result;
}

String String::parseChar(const char& character)
{
	String result;
	result.array = new char[1];
	result.length = result.capacity = 1;
	result.array[0] = character;
	return result;
}


String::~String()
{
	delete[] array;
}

//String& String::operator+(const String& appendedString)
//{
//	String * result = new String(*this);
//	*result += appendedString;
//	return *result;
//}

size_t String::getCStringLength(const char * cstring) {
	size_t length = 0;
	const char * ptr = cstring;
	while (*(ptr++)) length++;
	return length;
}

String::String(const int&number)
{
	*this = parseInt(number);
}

String::String(const long long&number)
{
	*this = parseInt(number);
}

String::String(const unsigned long long&number)
{
	*this = parseUInt(number);
}

String::String(const float&number)
{
	*this = parseDouble(number);
}

String::String(const double&number)
{
	*this = parseDouble(number);
}

String::String(const char&character)
{
	*this = parseChar(character);
}


void String::resize() {
	capacity = 2 * capacity;
	if (array) {
		char * newArray = new char[capacity];
		char*newPtr = newArray, *oldPtr = array;
		copy(array, newArray, length);
		delete[] array;
		array = newArray;
	}
}

String& String::operator+=(const String& appendedString)
{
	return append(appendedString);
}

String& String::operator=(const String&other)
{
	//delete[]array;
	capacity = other.length;
	length = other.length;
	array = new char[capacity];
	copy(other.array, array, length);
	return *this;
}

String& String::append(const String& appendedString)
{
	while (length + appendedString.length > capacity) resize();
	char * newString = new char[capacity];
	copy(array, newString, length);
	copy(appendedString, newString + length, appendedString.length);
	delete[] array;
	array = newString;
	length += appendedString.length;
	return *this;
}

String& String::prepend(const String&prependedString)
{
	while (length + prependedString.length > capacity) resize();
	char * newString = new char[capacity];
	copy(prependedString, newString, getCStringLength(prependedString));
	copy(array, newString + getCStringLength(prependedString), length);
	delete[]array;
	array = newString;
	length = getCStringLength(prependedString) + length;
	return *this;
}

String String::substring(size_t beginIndex, size_t endIndex) const throw(OutOfRangeException)
{
	if (beginIndex >= length) throw OutOfRangeException();
	if (endIndex >= length)throw OutOfRangeException();
	if (beginIndex > endIndex) throw InvalidArgumentException();
	String result;
	result.capacity = result.length = endIndex - beginIndex + 1;
	result.array = new char[capacity];
	copy(array + beginIndex, result.array, result.length);
	return result;
}

String String::substring(size_t beginIndex) const throw(OutOfRangeException)
{
	if (beginIndex >= length)throw OutOfRangeException();
	String result;
	result.capacity = result.length = length - beginIndex;
	result.array = new char[capacity];
	copy(array + beginIndex, result.array, result.length);
	return result;
}

const char* String::c_str() const
{
	return *this;
}

size_t String::getLength() const
{
	return length;
}

size_t String::getCapacity() const
{
	return capacity;
}

void String::copy(const char * src, char * dst, size_t length)
{
	const char * srcPtr = src;
	char * dstPtr = dst;
	for (size_t i = 0; i < length; ++i)
		*(dstPtr++) = *(srcPtr++);
}

std::ostream& operator<<(std::ostream& ostr, const String& string)
{
	const char * tmp = string.c_str();
	ostr << tmp;
	delete[] tmp;
	return ostr;

}

String& operator+(const String& left, const String& right)
{
	String result = left;
	return result.append(right);

}

String operator+(String& left, String& right)
{
	String result = left;
	return result.append(right);
}

//String operator+(String& string, const long long& number)
//{
//	return string.append(number);
//}
//
//String operator+(String& string, const unsigned long long& number)
//{
//	return string.append(number);
//}
//
//String operator+(String& string, const double& number)
//{
//	return string.append(number);
//}
//
//String operator+(String& string, const char& character)
//{
//	return string.append(character);
//}
//
//String operator+(String& string, const char* cstring)
//{
//	return string.append(cstring);
//}
//
//String operator+(String& string, const int& number)
//{
//	return string.append(number);
//}
//
//String operator+(const long long& number, String& string)
//{
//	return string.prepend(number);
//}
//
//String operator+(const unsigned long long& number, String& string)
//{
//	return string.prepend(number);
//}
//
//String operator+(const double& number, String& string)
//{
//	return string.prepend(number);
//}
//
//String operator+(const char& character, String& string)
//{
//	return string.prepend(character);
//}
//
//String operator+(const char* cstring, String& string)
//{
//	return string.prepend(cstring);
//}


