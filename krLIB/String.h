//
// Created by kamil on 31.03.17.
//

#ifndef KROLIB_STRING_H
#define KROLIB_STRING_H


#include <cstring>
#include <iostream>
#include "Exception.h"

//class Exception;
class String {
public:
	class OutOfRangeException : Exception {};
	class InvalidArgumentException : Exception {};
	String();
	~String();
	//copy constructor
	String(const String&);



	//Static conversions
	static String parseInt(const long long& number);
	static String parseUInt(const unsigned long long& number);
	static String parseCString(const char *);
	static String parseDouble(const long double&number, const char*const format = nullptr);
	static String parseChar(const char & character);
	static size_t getCStringLength(const char*);

	//conversions to String
	String(const int&);
	String(const long long int&);
	String(const unsigned long long int&);
	String(const float&);
	String(const double&);
	String(const char&);
	String(const char *);


	//conversions from string to other types
	operator const char *() const;
	operator long long int()const;
	operator unsigned long long int()const;
	operator double()const;


	//implementations of arithmetic operators
	//String &operator+(const String &);
	String &operator+=(const String &);
	String &operator=(const String&);

	//String manipulation methods
	String&append(const String&);
	String&prepend(const String&);
	String substring(size_t beginIndex, size_t endIndex)const throw(OutOfRangeException);
	String substring(size_t beginIndex)const throw(OutOfRangeException);
	String&toLower();
	String&toUpper();
	String&trim();
	char operator[](size_t index)throw(OutOfRangeException);
	const char*c_str()const;
	size_t getLength() const;
	size_t getCapacity() const;
protected:
private:
	char *array;
	size_t capacity;
	size_t length;
	void resize();
	static void copy(const char *src, char *dest, size_t size);
	friend std::ostream& operator<<(std::ostream&ostr, const String&string);
};

std::ostream& operator<<(std::ostream&ostr, const String&string);
//String operator+( String& string, const long long& number);
//String operator+( String& string,const unsigned long long& number);
//String operator+( String& string, const double& number);
//String operator+( String& string, const char& character);
//String operator+( String& string, const char* cstring);
//String operator+(String& string, const int & number);
//String operator+(const long long& number, String& string);
//String operator+(const unsigned long long& number, String& string);
//String operator+(const double& number, String& string);
//String operator+(const char& character, String& string);
//String operator+(const char* cstring, String& string);

String&operator+(const String&left, const String&right);
String operator+(String&left, String&right);
template <typename T> String operator+(String&string, const T& other)
{
	String result = string;
	return result.append(other);
}

template <typename  T> String operator+(const T& other, String& string)
{
	String result = string;
	return result.prepend(other);
}

#endif //KROLIB_STRING_H
