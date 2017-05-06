#include "Console.h"
#include <cstdio>


Console::Console()
{
}


Console::~Console()
{
}

String Console::readLine()
{
	char tmp[1002];
	if (!fgets(tmp, 1001, stdin))
		throw EndOfStreamException();
	if (tmp[0] == '\n')
		throw EndOfStreamException();
	String result(tmp);
	return result.trim();
}
