#include "List.h"
#include <iostream>
#include "Array.h"
#include "String.h"
#include <string>
#include <sstream>
#include <ctime>

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
	stringstream ss;
	Array<int> arr;
	for (int i = 0; i < ILE; ++i) {
		arr[i] = i;
	}
	for (int i = 0; i < ILE; ++i) {
		ss << arr[i] << " ";
	}
	//delete arr;
	//cout << ss.str();
}

void testArray() {
	clock_t start, stop;
	start = clock();
	wbudowane();
	stop = clock();
	cout << "Zwykla tablica:" << endl;
	cout << (double(stop - start) / CLOCKS_PER_SEC) * 1000 << " ms" << endl;
	start = clock();
	moje();
	stop = clock();
	cout << "Array" << endl;
	cout << (double(stop - start) / CLOCKS_PER_SEC) * 1000 << " ms" << endl;

}


void testString() {
	cout << "_____________________________________________" << endl;
	cout << "String: " << endl;
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



	


	String str = "asd";
	String str1 = "123";
	String str3 = str1 + str;
	String str4;
	str4 = str3 + str1 + str;
	cout << str << " " << str.Length() << " " << str.Size() << endl;
	str += "111";
	cout << str << " " << str.Length() << " " << str.Size() << endl;
	cout << str3 << " " << str3.Length() << " " << str3.Size() << endl;
	cout << str4 << " " << str4.Length() << " " << str4.Size() << endl;
	int i = 0;

	return 0;
}