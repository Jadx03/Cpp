// Name - Jainam Dhruva
// CS 215 - 009
// Lab - 6 : Fraction Fun


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct frac {
	int numerator;
	int denominator;
};

void PrintLogo() {
	cout << "+--------------------------------------+" << endl;
	cout << "|           Fraction Fun               |" << endl;
	cout << "|         by Jainam Dhruva             |" << endl;
	cout << "+--------------------------------------+" << endl;
}

void AskFraction(frac &temp) {
	int usr_numer;
	int usr_denom;
	
	
	cout << "Enter Numerator:    ";
	cin >> usr_numer;
	
	cout << "Enter Denominator:  ";
	cin >> usr_denom;
	while (usr_denom == 0) {
		cout << "Enter Denominator:  ";
		cin >> usr_denom;
	}

	temp.numerator = usr_numer;
	temp.denominator = usr_denom;
}

double DecimalValue(frac temp) {
	double dec_val;

	dec_val = (1.00 * temp.numerator) / (1.00 * temp.denominator);

	return dec_val;
}

void PrintFraction(frac temp) {
	cout << temp.numerator << "/" << temp.denominator;
	
}

frac Add(frac temp1, frac temp2) {

	frac sum;

	if (temp1.denominator == temp2.denominator) {
		sum.numerator = temp1.numerator + temp2.numerator;
		sum.denominator = temp1.denominator;
	}
	else {
		sum.numerator = (temp1.numerator * temp2.denominator) + (temp2.numerator * temp1.denominator);
		sum.denominator = (temp1.denominator * temp2.denominator);
	}

	return sum;
}	

void main() {

	frac fraction1;
	fraction1.numerator = 0; fraction1.denominator = 0;
	frac fraction2;
	fraction2.numerator = 0; fraction2.denominator = 0;

	PrintLogo();

	AskFraction(fraction1);
	AskFraction(fraction2);

	DecimalValue(fraction1);

	frac sum_of_frac = Add(fraction1, fraction2);

	cout << "Decimal Value of ";
	PrintFraction(fraction1);
	cout << " is " << DecimalValue(fraction1)<< endl;
	

	
	PrintFraction(fraction1);
	cout << " + ";
	PrintFraction(fraction2);
	cout << " = ";
	PrintFraction(sum_of_frac); 
	cout << endl;


	system("pause");

}