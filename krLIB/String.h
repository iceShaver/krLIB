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
	String();
	~String();
	String(const String&);
	//______________________________________Useful static functions__________________________________________
	static bool isLetter(const char&character);
	static bool isCapitalLetter(const char&character);
	static bool isLowerCaseLetter(const char&character);
	static char toLower(const char&character);
	static char toUpper(const char&character);


	//__________________________________Static conversion functions to String_________________________________
	static String parseInt(const long long& number);
	static String parseUInt(const unsigned long long& number);
	static String parseCString(const char *);
	static String parseDouble(const long double&number, const char*const format = nullptr);
	static String parseChar(const char & character);

	//________________________________________Converting constructors___________________________________________
	String(const int&);
	String(const long long int&);
	String(const unsigned long long int&);
	String(const float&);
	String(const double&);
	String(const char&);
	String(const char *);


	//__________________________________________Converting operators___________________________________________

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


	//____________________________________________Operators____________________________________________________
	String &operator+=(const String &);
	String &operator=(const String&);
	char& operator[](size_t index)throw(OutOfRangeException);

	//______________________________________String manipulation methods________________________________________
	String&append(const String&);
	String&prepend(const String&);
	String substring(size_t beginIndex, size_t endIndex)const throw(OutOfRangeException);
	String substring(size_t beginIndex)const throw(OutOfRangeException);
	String&toLower();
	String&toUpper();
	String&trim();


	//________________________________________Others__________________________________________________________
	const char*c_str()const;
	size_t getLength() const;
	size_t getCapacity() const;
	static size_t getCStringLength(const char*);
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
String operator+(const String&left, const String&right);
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
