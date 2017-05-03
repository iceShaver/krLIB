#pragma once
class Exception
{
public:
	Exception();
	virtual ~Exception();
private:


};
class OutOfRangeException : Exception {};
class InvalidArgumentException : Exception {};
class NotImplementedException : Exception {};
class NegativeArraySizeException : Exception {};
class NullReferenceException : Exception {};
