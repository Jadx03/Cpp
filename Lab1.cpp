//----------------------------------------------------------------
//						CS 215 - 009  - Lab 1 
//----------------------------------------------------------------
// Author: Jainam Dhruva
// Date: 24 Jan 2020
// Description: Lab 1 
//----------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std; 

int main() {
	cout << "-------------------\n";
	cout << "|                 |\n";
	cout << "|  Jainam Dhruva  |\n";
	cout << "|                 |\n";
	cout << "-------------------\n";
	
	int num1, num2;
	cout << ""<<endl;
	cout <<"Enter a Number: ";
	cin >> num1;
	cout <<"Enter another:  ";
	cin >> num2;
	float quo = ((float) num1)/ num2;
	cout << "" << endl;
	cout << "Sum :           " << num1 + num2<<endl;
	cout << "Difference:     " << num1 - num2<<endl;
	cout << "Product:        " << num1 * num2<<endl;
	cout << "Int quotient:   "  << num1 / num2<<endl;
	cout << "Float quotient: " << quo<< endl;
	system("pause");
	return 0;

}