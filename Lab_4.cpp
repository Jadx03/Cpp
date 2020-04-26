// Name: Jainam Dhruva
//CS 215: Sec009
//Lab-4

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {



	char opt;
	string answer;

	do {
		cout << "S - Sum Between" << endl;
		cout << "B - Box" << endl;
		cout << "X - Exit" << endl;


		cout << "Enter Option: ";
		cin >> answer;
		opt = answer[0]; // only to take the first letter of the string as an input

		switch (opt) {

			int num_1; // used in case 'S' && case's' for sum
			int num_2; // used in case 'S' && case's' for sum
			int size_of_box; // used in case 'B' and 'b' for making the box

		case 'S': //sum of two numbers

			cout << "Enter start and stop numbers: ";
			cin >> num_1;
			cout << " ";
			cin >> num_2;

			if (num_2 >= num_1) {

				int sum = 0;

				for (int i = num_1; i <= num_2; i++) {
					sum = sum + i;
				}

				cout << "The Sum of Numbers between " << endl << num_1 << " and " << num_2 << " is: " << sum << endl;


			}

			if (num_1 > num_2) {
				cout << " Num_1 > Num_2";

			}

			break;

		case 's':// sum of two numbers



			cout << "Enter start and stop numbers: ";
			cin >> num_1;
			cout << " ";
			cin >> num_2;

			if (num_2 >= num_1) {

				int sum = 0;

				for (int i = num_1; i <= num_2; i++) {
					sum = sum + i;
				}

				cout << "The Sum of Numbers between " << num_1 << " and " << num_2 << " is: " << sum << endl;


			}

			if (num_1 > num_2) {
				cout << " Num_1 > Num_2";

			}

			break;





		case'b': // making a box

			cout << "Enter the size of box: ";
			cin >> size_of_box;

			for (int i = 1; i <= size_of_box; i++) {
				for (int j = 1; j <= size_of_box; j++) {
					cout << "* ";
					if (j == size_of_box) {
						cout << endl;
					}
				}
			}

			break;

		case'B': // making a box

			cout << "Enter the size of box: ";
			cin >> size_of_box;

			for (int i = 1; i <= size_of_box; i++) {
				for (int j = 1; j <= size_of_box; j++) {
					cout << "* ";
					if (j == size_of_box) {
						cout << endl;
					}
				}
			}

			break;


		case 'x':
			break;
		case 'X':
			break;

		default:
			cout << "Invalid Option! Try Again!" << endl;



		}

		cout << endl;

	} while (opt != 'X' && opt != 'x');













	return 0;

}
