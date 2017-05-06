#pragma once
#include "String.h"

class Console
{
public:
	Console();
	~Console();
	static String readLine()throw(EndOfStreamException);
};

