#include "List.h"
#include <iostream>
#include "String.h"
#include <string>
#include <sstream>
#include <ctime>
#include "Stack.h"
#include <string>
#include "Vector.h"
#include <future>
#include <ostream>
#include <cctype>
using namespace std;
const size_t ILE = 10000000;


void wbudowane()
{
	stringstream ss;
	int* arr = new int[ILE];
	for (int i = 0; i < ILE; ++i)
	{
		arr[i] = i;
	}
	for (int i = 0; i < ILE; ++i)
	{
		ss << arr[i] << " ";
	}
	//cout << ss.str();
	delete[] arr;
}

void moje()
{
	//stringstream ss;
	//Vector<int> arr;
	//for (int i = 0; i < ILE; ++i) {
	//	arr[i] = new int(i);
	//}
	//for (int i = 0; i < ILE; ++i) {
	//	//ss << arr[i] << " ";
	//}
	//delete arr;
	//cout << ss.str();
}

void testArray()
{
	//clock_t start, stop;
	//start = clock();
	//wbudowane();
	//stop = clock();
	//cout << "Zwykla tablica:" << endl;
	//cout << (double(stop - start) / CLOCKS_PER_SEC) * 1000 << " ms" << endl;
	//start = clock();
	//moje();
	//stop = clock();
	//cout << "Vector" << endl;
	//cout << (double(stop - start) / CLOCKS_PER_SEC) * 1000 << " ms" << endl;
}


void testString()
{
	//String str = "asd";
	//String str1 = "123";
	//String str3 = str1 + str;
	//String str4;
	//str4 = str3 + str1 + str;
	//cout << str << " " << str.getLength() << " " << str.getCapacity() << endl;
	//str += "111";
	//cout << str << " " << str.getLength() << " " << str.getCapacity() << endl;
	//cout << str3 << " " << str3.getLength() << " " << str3.getCapacity() << endl;
	//cout << str4 << " " << str4.getLength() << " " << str4.getCapacity() << endl;
}


void testStack()
{
	Stack<int> stack;
	stack.Push(new int(1324));
	stack.Push(new int(6546));
	stack.Push(new int(7864));
	cout << stack.GetSize() << " ";
	cout << *stack.Pop() << " ";
	cout << stack.GetSize() << endl;
	cout << stack.GetSize() << " ";
	cout << *stack.Pop() << " ";
	cout << stack.GetSize() << endl;
	cout << stack.GetSize() << " ";
	cout << *stack.Pop() << " ";
	cout << stack.GetSize() << endl;
}

void arrayMemLeakTest()
{
	auto arr = new Vector<List<int>>();
	//cout.sync_with_stdio(false);
	for (int i = 0; i < 10000000; ++i)
	{
		((*arr)[i]) = new List<int>;
		(*(*arr)[i]).PushLast(new int(i));
		auto tmo = (*(*arr)[i]).Pop(0);
		delete tmo;
	}
	arr[126].GetLast();
	delete arr;
}

class TestClass
{
public:
	TestClass(const String& name, int value)
		: name(name),
		  value(value)
	{
	}


	friend std::ostream& operator<<(std::ostream& os, const TestClass& obj)
	{
		return os
			<< "name: " << obj.name
			<< " value: " << obj.value;
	}

private:
	String name;
	int value;
};

int main(int argc, char* argv[])
{
	List<TestClass>list;
	list.PushFirst(new TestClass("Kamil", 123));
	list.PushLast(new TestClass("Kamil1", 234));
	list.PushLast(new TestClass("Kamil13", 4234));
	list.PushLast(new TestClass("Kamil513", 4234));
	list.PushLast(new TestClass("Kamil1/3", 4234));
	list.PushLast(new TestClass("Kamil1g3", 4234));
	list.PushLast(new TestClass("Kamil1b3", 4234));
	list.PushLast(new TestClass("Kamil133", 4234));
	list.PushLast(new TestClass("Kamil113", 4234));
	list.PushLast(new TestClass("Kamil1d3", 4234));
	list.PushLast(new TestClass("Kamil1x3", 54234));

	for (TestClass* testClass : list)
	{
		cout << *testClass << endl;
	}
	getchar();
	return 0;
}
