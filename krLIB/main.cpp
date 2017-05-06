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
#include <map>
#include "RedBlackTree.h"
#include "Map.h"
#include "Console.h"
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


	friend bool operator==(const TestClass& lhs, const TestClass& rhs)
	{
		return lhs.name == rhs.name
			&& lhs.value == rhs.value;
	}

	friend bool operator!=(const TestClass& lhs, const TestClass& rhs)
	{
		return !(lhs == rhs);
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
	/*RedBlackTree<int, int> rbt;
	rbt.push(new int(1), new int(1));
	rbt.push(new int(2), new int(1));
	rbt.push(new int(3), new int(1));
	rbt.push(new int(4), new int(1));
	rbt.push(new int(8), new int(1));
	rbt.push(new int(6), new int(1));
	rbt.push(new int(9), new int(1));
	rbt.push(new int(4), new int(1));
	rbt.push(new int(3), new int(1));


	String cr, cl, cp;
	cr = cl = cp = "  ";
	cout << (cr[0] = 218) << " " << cr.getLength() << endl;
	cout << (cr[1] = 196) << " " << cr.getLength() << endl;
	cout << (cl[0] = 192) << " " << cl.getLength() << endl;
	cout << (cl[1] = 196) << " " << cl.getLength() << endl;
	cout << (cp[0] = 179) << " " << cp.getLength() << endl;
	cout << "___________________" << endl;

	string crs, cls, cps;
	crs = cls = cps = "  ";
	cout << (crs[0] = 218) << " " << crs.length() << endl;
	cout << (crs[1] = 196) << " " << crs.length() << endl;
	cout << (cls[0] = 192) << " " << cls.length() << endl;
	cout << (cls[1] = 196) << " " << cls.length() << endl;
	cout << (cps[0] = 179) << " " << cps.length() << endl;*/
	//srand(time(NULL));

	//Map<string, bool> rbt;
	//cout << "sortowanie..." << endl;
	//for (int i = 0; i < 21; ++i)
	//	rbt.push(new string("ncvuewoivbhgwfufdruhnoidewvbfghpwpuwoiwubvgouwnbuidjbvgrb;vpg"+i%20), new bool(true));

	//cout << "posortowano!" << endl;
	////rbt.print();
	//Map<String, String>map;
	//map.pull(new String());
	Vector<String> str;
	int i = 0;
	while (true) {
		String line;
		try {
			str.pushLast(new String(String("asd")+String(i)));
			cout << *str[i] << endl;
			i++;
		}
		catch (EndOfStreamException){
			break;
		}
	}
	
	getchar();
	return 0;
}
