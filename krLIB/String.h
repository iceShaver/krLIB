//
// Created by kamil on 31.03.17.
//

#ifndef KROLIB_STRING_H
#define KROLIB_STRING_H


#include <cstring>
#include <iostream>

class String {
public:
	String();
	String(const char *);
	String(const String&);
	String &operator+(const String &);
	String &operator+=(const String &);
	operator const char *() const;
	size_t Length() const;
	size_t Size() const;
	void Optimize();
	void Copy(const char *, char *, size_t size) const;
	const char *CString();

protected:
private:
	char *array;
	size_t size;
	size_t length;
	void resize();
	size_t calcCstringLength(const char*);
	// friend std::ostream &operator<<(std::ostream &, String &);
};


#endif //KROLIB_STRING_H