#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Header.h"
#include <iostream>
using namespace std;


//Takes array and its length and searchs for desired number, returning its index
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


// modify a int at a certain index 
void modify(int da[], int n) {
	int old = da[n];
	int c = 0;
	cout << "Enter new integer to replace: " << endl;
	cin >> c;
	da[n] = c;
	cout << "The new value is " << c << endl;
	cout << "The old value is " << old << endl;
}

// append a number to the end of the array
int* add(int da[], int len, int n) {
	int* newArray = new int[len + 1];
	for (int i = 0; i < len; i++) {
		newArray[i] = da[i];
	}
	newArray[len] = n;

	return newArray;
}

// remove a number from an array
void remove(int da[], int n) {
	da[n] = NULL;
	cout << da[n];
}