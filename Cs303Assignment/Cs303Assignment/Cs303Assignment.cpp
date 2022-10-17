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
			cout << dataArray[i] << " ";


		}
		cout << endl;
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
	// Do loop while the choice is not to quit out of the loop
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
			try {
				if (0 <= b && b <= 100) {
					modify(dataArray, b);
				}
				else
				{
					throw(b);
				}
			}
			catch (...) {
				cout << "The index does not exist in the range of the array " << endl;
			}



			loopback = true;
			break;
		case 'C':
		case'c':
			// Case C appends an integer to the array
			cout << "Enter new integer to add to the end of the array:  " << endl;
			cin >> c;
			try {
				if (c > 0) {
					add(dataArray, 100, c);
				}
				else {
					throw(c);
				}
			}
			catch (...) {
				cout << "Please try again with a integer above 0" << endl;

			}


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

	//Print out the final array at the end.
	for (int i = 0; i < 100; i++) {
		if (i % 10 == 0) {
			cout << endl << dataArray[i] << " ";
		}
		else {
			cout << dataArray[i] << " ";
		}
	}
	cout << c << endl;



	Professional p(20, 500);
	Nonprofessional n(36, 11.6);
	cout << "\nProfessional salary = " << p.getSalary();
	cout << "\nProfessional vacation = " << p.getVacation();
	cout << "\nNonprofessional salary = " << n.getSalary();
	cout << "\nNonprofessional vacation = " << n.getVacation();
	cout << "\nNonprofessional insurance = " << n.getInsurance();
	return 0;
}

