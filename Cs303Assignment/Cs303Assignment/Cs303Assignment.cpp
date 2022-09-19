#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;



int main()
{
	// Have an int array to change file into an array and string to ask for file name
	string filename;
	int dataArray[100];
	string x = "true";
	cout << "Enter a file name" << endl;
	cin >> filename;
	// Open up the file with the users filename, if incorrect ask again
	ifstream myFile(filename);
	while (myFile.fail()) {
		myFile.clear();
		cout << "Incorrect filename, please enter again" << endl;
		cin >> filename;
		myFile.open(filename.c_str());
	}
	// open up the file using the file name the user inputted and itterate through each line into an array
	if (myFile.is_open()) {
		for (int i = 0; i < 100; i++) {
			myFile >> dataArray[i];
			cout << dataArray[i] << endl;
				
				
			}
		}

	
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	// Menu system for user to choose what they want to do to the array
	cout << "Please enter the input to edit the array" << endl;
	cout << "Enter A to see if an integer exist in the array" << endl;
	cout << "enter B to modifed a integer at an index" << endl;
	cout << "Enter C to add a integer at the end of the array " << endl;
	cout << "Enter D to remove integer at an index" << endl;
	cout << "Enter Q To quit" << endl;
	char choice;
	
	bool loopback = true;
	do 
	{
		cin >> choice;
		switch (choice) {
		case 'A':
		case 'a':
			// Choice A checks for the integer in the Array
			cout << "Enter integer to see if it exists in the array: " << endl;
			cin >> a;
			indexarray(dataArray, 100, a);
			loopback = true;
			break;
		case 'B':
		case'b':
			// Choice b modifys a integer at a certain index
			cout << "Enter index to be modified: ";
			cin >> b;
			modify(dataArray, b);
			loopback = true;
			break;
		case 'C':
		case'c':
			// Case C appends an integer to the array
			cout << "Enter new integer to add to the end of the array:  " << endl;
			cin >> c;
			add(dataArray, c);
			loopback = true;
			break;
		case 'D':
		case'd':
			// Case D removes a integer at certain index
			cout << "Enter index to remove integer: " << endl;
			cin >> d;
			remove(dataArray, d);
			loopback = true;
			break;
		case 'Q':
		case'q':
			// Quit 
			loopback = false;
			break;
		default:
			// Default answer for anything that does not match cases
			cout << "That was a invalid response" << endl;
			loopback = true;

		}
	} while (loopback);
}

