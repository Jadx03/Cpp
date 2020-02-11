//-----------------------------------------------------------
// CS 215 – Spring 2020
// Lab 3
// Author: Jainam Dhruva
// Section: 009
//----------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// Constants for part 2
const int A_Pep = 30000;
const int B_Pep = 1000;
const int C_Pep = 40000;
const int D_Pep = 2480000;

int main() {

	//PART 1------------------------------------------------------------------------------------------

	int num_1, num_2, num_3;

	cout << "Enter Number 1: ";
	cin >> num_1;
	cout << "Enter Number 2: ";
	cin >> num_2;
	cout << "Enter Number 3: ";
	cin >> num_3;

	if (num_1 >= num_2 && num_1 >= num_3) {
		if (num_2 >= num_3) {
			cout << "Sorted they are " << num_3 << " " << num_2 << " " << num_1;
		}
		if (num_3 >= num_2) {
			cout << "Sorted they are " << num_2 << " " << num_3 << " " << num_1;
		}
	}

	else if (num_2 >= num_1 && num_2 >= num_3) {
		if (num_1 >= num_3) {
			cout << "Sorted they are " << num_3 << " " << num_1 << " " << num_2;
		}
		if (num_3 >= num_1) {
			cout << "Sorted they are " << num_1 << " " << num_3 << " " << num_2;
		}
	}

	else if (num_3 >= num_1 && num_3 >= num_2) {
		if (num_2 >= num_1) {
			cout << "Sorted they are " << num_1 << " " << num_2 << " " << num_3;
		}
		if (num_1 >= num_2) {
			cout << "Sorted they are " << num_2 << " " << num_1 << " " << num_3;
		}
	}


	//PART2--------------------------------------------------------------------------------------------

	cout << endl;

	cout << "\n A. Aleppo Pepper";
	cout << "\n B. Banana Pepper";
	cout << "\n C. Cayenne Pepper";
	cout << "\n D. Dragons Breath";

	char user_input;

	cout << "\n Enter a letter to choose a pepper: ";
	cin >> user_input;


	switch (user_input) {
	case'A': cout << "\n That's " << A_Pep << " SU of heat!"; break;
	case'a': cout << "\n That's " << A_Pep << " SU of heat!"; break;

	case'B': cout << "\n That's " << B_Pep << " SU of heat!"; break;
	case'b': cout << "\n That's " << B_Pep << " SU of heat!"; break;

	case'C': cout << "\n That's " << C_Pep << " SU of heat!"; break;
	case'c': cout << "\n That's " << C_Pep << " SU of heat!"; break;

	case'D':
	case'd': cout << "\n That's " << D_Pep << " SU of heat!"; break;

	default: cout << " That pepper is not on the list. ";
	}

	cout << "\n\nEnd of Program \n ----------------------------------------------------------------------";

	return 0;

}