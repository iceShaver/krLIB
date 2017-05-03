//
// Created by kamil on 31.03.17.
//

#ifndef KROLIB_STRING_H
#define KROLIB_STRING_H


#include <cstring>
#include <iostream>
#include "Exception.h"

class String {
public:
	class Iterator;
	String();
	~String();
	String(const String&);
	//____________________________________Useful static functions__________________________________________
	static bool isLetter(const char&character);
	static bool isCapitalLetter(const char&character);
	static bool isLowerCaseLetter(const char&character);
	static char toLower(const char&character);
	static char toUpper(const char&character);


	//________________________________Static conversion functions to String________________________________
	static String parseInt(const long long& number);
	static String parseUInt(const unsigned long long& number);
	static String parseCString(const char *);
	static String parseDouble(const long double&number, const char*const format = nullptr);
	static String parseChar(const char & character);

	//_____________________________________Converting constructors_________________________________________
	String(const int&);
	String(const long long int&);
	String(const unsigned long long int&);
	String(const float&);
	String(const double&);
	String(const char&);
	String(const char *);


	//________________________________________Converting operators_________________________________________

	/**
	 * \brief returns new const char * with content of a string
	 * terminated with '\0'
	 * CAUSE MEM LEAK IF UNCATCHED
	 */
	explicit operator const char *() const;


	/**
	 * \brief NOT IMPLEMENTED
	 */
	explicit operator long long int()const;



	/**
	 * \brief NOT IMPLEMENTED
	 */
	explicit operator unsigned long long int()const;

	/**
	 * \brief NOT IMPLEMENTED
	 */
	explicit operator double()const;


	//___________________________________________Operators_________________________________________________
	String &operator+=(const String &);
	String &operator=(const String&);
	char& operator[](size_t index) const throw(OutOfRangeException);
	bool operator==(const String&other) const;
	bool operator>(const String&other)const;
	bool operator<(const String&other)const;
	bool operator<=(const String&other)const;
	bool operator>=(const String&other)const;

	//____________________________________String manipulation methods______________________________________
	String&append(const String&);
	String&prepend(const String&);
	String substring(size_t beginIndex, size_t endIndex)const throw(OutOfRangeException);
	String substring(size_t beginIndex)const throw(OutOfRangeException);
	String&toLower();
	String&toUpper();
	String&trim();


	//________________________________________Others_______________________________________________________
	const char*c_str()const;
	size_t getLength() const;
	size_t getCapacity() const;
	static size_t getCStringLength(const char*);

	//______________________________________Iterators______________________________________________________
	Iterator begin()const;
	Iterator end()const;
protected:
private:
	char *array;
	size_t capacity;
	size_t length;
	void resize();
	static void copy(const char *src, char *dest, size_t size);
	static bool areEqual(const char*left, const char*right, size_t length);
	static int compare(const String&left, const String&right);
	friend std::ostream& operator<<(std::ostream&ostr, const String&string);
};

std::ostream& operator<<(std::ostream&ostr, const String&string);
String operator+(const String&left, const String&right);
String operator+(String&left, String&right);
template <typename T> String operator+(String&string, const T& other)
{
	String result = string;
	return result.append(other);
}

template <typename T> String operator+(const T& other, String& string)
{
	String result = string;
	return result.prepend(other);
}

//________________________________________Iterator class_____________________________________
class String::Iterator
{
	//TODO: care lastPtr &firstPtr bounds
	//TODO: make String.begin(), end() return lastPtr, firstPtr
	//TODO: care uninitialized pointer
	typedef char Type;
	typedef int OffsetType;
public:
	Iterator();
	Iterator(const Iterator&other);
	~Iterator();

	Type& operator*()const throw(NullReferenceException);
	//Type* operator->()const;
	Iterator& operator++();
	Iterator operator++(int);
	Iterator& operator--();
	Iterator operator--(int);
	Iterator& operator+=(OffsetType offset);
	Iterator operator+(OffsetType offset)const;
	Iterator& operator-=(OffsetType offset);
	Iterator operator-(OffsetType offset)const;
	bool operator==(const Iterator&other)const;
	bool operator!=(const Iterator&other)const;
	bool operator>(const Iterator&other)const;
	bool operator>=(const Iterator&other)const;
	bool operator<(const Iterator&other)const;
	bool operator<=(const Iterator&other)const;
private:
	explicit Iterator(Type*ptr);
	Type*ptr;
	friend String;
};

#endif //KROLIB_STRING_H
