//
// Created by Kamil Królikowski on 3/19/17.
// kamil-krolikowski@outlook.com
// 
#include "cstring.h"

const char *strrev(const char *text) {
	size_t size = 0;
	const char *srcPtr = text;
	while (*(srcPtr++)) size++;
	srcPtr -= 2;
	char *result = new char[size];
	char *resultPtr = result;
	for (size_t i = size; i > 0; --i)
		*(resultPtr++) = *(srcPtr--);
	*resultPtr = '\0';
	return result;
}