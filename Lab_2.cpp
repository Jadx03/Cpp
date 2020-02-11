
//-----------------------------------------------------------
// CS 215 – Spring 2020
// Lab 2 - Payroll Calculator
// Author: Jainam Dhruva
// Section: 009
//----------------------------------------------------------



#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const float ss_tax_rate = 0.03;
const float state_tax_rate = 0.06;
const float fed_tax_rate = 0.07;


int main() {

	//input vars
	string first_name;
	string last_name;
	float hours;
	float pay_rate;

	//inputs
	cout << "Enter First Name:   ";
	cin >> first_name;
	cout << "Enter Last Name:    ";
	cin >> last_name;
	cout << "Enter Hours Worked: ";
	cin >> hours;
	cout << "Enter Pay Rate:     ";
	cin >> pay_rate;

	//outputs
	float gross_pay;
	float ss_tax;
	float state_tax;
	float fed_tax;
	float net_pay;


	//calculations
	gross_pay = hours * pay_rate;
	ss_tax = ss_tax_rate * gross_pay;
	state_tax = state_tax_rate * gross_pay;
	fed_tax = fed_tax_rate * gross_pay;
	net_pay = ((gross_pay)-(ss_tax + state_tax + fed_tax));


	cout << endl;
	cout << fixed << setprecision(2);
	cout << "Name:" << right << setw(10) << first_name << ", " << last_name << endl;
	cout << "Gross Pay: $" << right << setw(10) << gross_pay << endl;
	cout << "State Tax: $" << right << setw(10) << state_tax << endl;
	cout << "Fed Tax:   $" << right << setw(10) << fed_tax << endl;
	cout << "SS Tax:    $" << right << setw(10) << ss_tax << endl;
	cout << "Net Pay:   $" << right << setw(10) << net_pay << endl;


	system("pause");
	return 0;
}