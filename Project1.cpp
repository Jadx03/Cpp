//-----------------------------------------------------------
// CS 215 – Spring 2020
// Project 1 - Bank Account Manager
// Author: Jainam Dhruva
// Section: 009
// 11 Feb 2020
// Desrpition: A short program that asks for user input and then displays Balance, Deposit or Withdrawl receipt according to the input
//----------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



int main() {

	cout << "-----------------------\n";
	cout << "|                     |\n";
	cout << "|    Bank of Jainam   |\n";
	cout << "|     CS 215 - 009    |\n";
	cout << "|                     |\n";
	cout << "-----------------------\n";


	string Acc_Num;
	float Bal;
	string usr_op;

	
	cout << "Enter account Number:   ";
	cin >> Acc_Num;

	cout << fixed << setprecision(2) ;
	// the part above ^^ will always execute when the program is run



	// code goes to while loop right after account number and skips while loop if account number == "shutdown"
	while (Acc_Num != "shutdown") {

		cout << "Enter account balance:  ";
		cin >> Bal;

		cout << "B - Balance Inquiry\n";
		cout << "D - Deposit        \n";
		cout << "W - Withdrawl      \n";


		cout << "Choose an option: ";
		cin >> usr_op;

		// starting with the excption "if" otherwise if kept the last if case the code will print the above statemnts starting the while loop
		if (usr_op != "B" && usr_op != "D" && usr_op != "W") {

			while (usr_op != "B" && usr_op != "D" && usr_op != "W") {

				cout << usr_op << " is invalid option. Enter B, D or W." << endl;
				cout << "Choose an option: ";
				cin >> usr_op;
			}

		}


		// straight forward case of if user input == B
		 if (usr_op == "B") {
			 cout << "-----------------------\n";
			 cout << "|                     |\n";
			 cout << "|    Bank of Jainam   |\n";
			 cout << "|     CS 215 - 009    |\n";
			 cout << "|                     |\n";
			 cout << "-----------------------\n";

			 cout << fixed << setprecision(2);
			 cout << "Account: " << left << Acc_Num << endl;
			 cout << "Balance: " << left << "$ " << right << Bal << endl;
			 cout << endl;


			 cout << "-----------------------\n";
			 cout << "|                     |\n";
			 cout << "|    Bank of Jainam   |\n";
			 cout << "|     CS 215 - 009    |\n";
			 cout << "|                     |\n";
			 cout << "-----------------------\n";


			 cout << "Enter account Number:   ";
			 cin >> Acc_Num;

		 }

		 //  Straight forward case of user input == D
		if (usr_op == "D") {

			 float dep_amount;

			 cout << "Enter Deposit Amount: ";
			 cin >> dep_amount;

			 cout << "-----------------------\n";
			 cout << "|                     |\n";
			 cout << "|    Bank of Jainam   |\n";
			 cout << "|     CS 215 - 009    |\n";
			 cout << "|                     |\n";
			 cout << "-----------------------\n";

			 cout << fixed << setprecision(2);
			 cout << "Account:  " << left << Acc_Num << endl;
			 cout << "Prev Bal: " << left << "$ " << Bal << endl;
			 cout << "Deposit:  " << left << "$ " << dep_amount << endl;
			 cout << "New Bal   " << left << "$ " << (Bal + dep_amount) << endl;
			 cout << endl;

			 cout << "-----------------------\n";
			 cout << "|                     |\n";
			 cout << "|    Bank of Jainam   |\n";
			 cout << "|     CS 215 - 009    |\n";
			 cout << "|                     |\n";
			 cout << "-----------------------\n";


			 cout << "Enter account Number:   ";
			 cin >> Acc_Num;

		}

		// Needs a nested while loop inside to verify withdraw amount < bank account
		if (usr_op == "W") {

			 float with_amount;

			 cout << "Enter withdrawl amount: ";
			 cin >> with_amount;

			 while (with_amount > Bal) {
				 cout << "Insufficient Funds. Current Balance is $ " << Bal << endl;
				 cout << "Enter withdrawl amount: ";
				 cin >> with_amount;
			 }

			 cout << "-----------------------\n";
			 cout << "|                     |\n";
			 cout << "|    Bank of Jainam   |\n";
			 cout << "|     CS 215 - 009    |\n";
			 cout << "|                     |\n";
			 cout << "-----------------------\n";

			 cout << fixed << setprecision(2);
			 cout << "Account:      " << left << Acc_Num << endl;
			 cout << "Prev Bal:     " << left << "$ " << Bal << endl;
			 cout << "Withdrawn:    " << left << "$ " << with_amount << endl;
			 cout << "New Balance:  " << left << "$ " << (Bal - with_amount) << endl;
			 cout << endl;

			 
			 cout << "-----------------------\n";
			 cout << "|                     |\n";
			 cout << "|    Bank of Jainam   |\n";
			 cout << "|     CS 215 - 009    |\n";
			 cout << "|                     |\n";
			 cout << "-----------------------\n";


			 cout << "Enter account Number:   ";
			 cin >> Acc_Num;

		}



	}
	//while loop ended here ^^^^^


	// executes the rest part after the while loop i.e at the end of program
	cout << endl;
	cout << "Shutting down...bye!" << endl;
	cout << "----------------------------------------------------------------";
	cout << endl;

	system("pause");


	
	return 0;

}