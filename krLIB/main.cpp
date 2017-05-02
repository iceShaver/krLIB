#include "List.h"
#include <iostream>
#include "Array.h"
#include "String.h"
#include <string>
#include <sstream>
#include <ctime>
#include "Stack.h"
#include <string>
using namespace std;
const size_t ILE = 10000000;


void wbudowane() {
	stringstream ss;
	int *arr = new int[ILE];
	for (int i = 0; i < ILE; ++i) {
		arr[i] = i;
	}
	for (int i = 0; i < ILE; ++i) {
		ss << arr[i] << " ";
	}
	//cout << ss.str();
	delete[] arr;
}

void moje() {
	//stringstream ss;
	//Array<int> arr;
	//for (int i = 0; i < ILE; ++i) {
	//	arr[i] = new int(i);
	//}
	//for (int i = 0; i < ILE; ++i) {
	//	//ss << arr[i] << " ";
	//}
	//delete arr;
	//cout << ss.str();
}

void testArray() {
	//clock_t start, stop;
	//start = clock();
	//wbudowane();
	//stop = clock();
	//cout << "Zwykla tablica:" << endl;
	//cout << (double(stop - start) / CLOCKS_PER_SEC) * 1000 << " ms" << endl;
	//start = clock();
	//moje();
	//stop = clock();
	//cout << "Array" << endl;
	//cout << (double(stop - start) / CLOCKS_PER_SEC) * 1000 << " ms" << endl;

}


void testString() {
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
	auto arr = new Array<List<int>>();
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

int main(int argc, char *argv[]) {
	//    Array<int> arr(10, Dynamic);
	//
	//        for (int i = 0; i < 11; ++i) {
	//            try {
	//            arr[i] = i;
	//            cout << arr[i] << endl;
	//            }catch(OutOfRangeException){
	//                cout << i <<" - Brak takiego elementu w tablicy"<<endl;
	//            }
	//        }
	//testArray();


	//testStack();

	for (int i = 0; i < 100000000; ++i)
	{
		String str = "kukli";
		String str1 = "wincyj ";

		//TODO:FIX MEM LEAK!!!!!
		str.append(str1);
		//cout << str << endl;
	}


	
	getchar();

	return 0;
}