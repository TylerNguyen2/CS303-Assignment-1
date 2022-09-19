#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Header.h"
#include <iostream>
using namespace std;



void indexarray(int da[], int len, int n) {
	for (int i = 0; i < len; i++)
	{
		if (da[i] == n) {
			cout << n << " exists in the array at index " << i << "." << endl;
			break;
		}
		if (i == len - 1) {
			cout << n << " does not exist in the array." << endl;
		}

	}
}

void modify(int da[], int n) {
	int old = da[n];
	int c = 0;
	cout << "Enter new integer to replace: " << endl;
	cin >> c;
	da[n] = c;
	cout << "The new value is " << c << endl;
	cout << "The old value is " << old << endl;
}

void add(int da[], int n) {
	const int getArrayLength = sizeof(da) / sizeof(int);
	int newArray[getArrayLength + 1];
	copy(da, da, newArray);
	newArray[getArrayLength - 1] = n;
	cout << newArray[getArrayLength - 1] << endl;
}

void remove(int da[], int n) {
	da[n] = NULL;
	cout << da[n];
}