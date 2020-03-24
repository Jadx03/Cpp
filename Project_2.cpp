// ------------------------------------------
//			CS 215 - 002 - Project 2
//-------------------------------------------
// Date: 22 Mar 2020
// Name: Jainam Dhruva
// CS 215 - 009 ~ (Section 009)
// Description - A software to maintain student grades.
// Assistance: I recieved help from no one.

#include <iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

const int max_students = 5;
const int max_num_scores = 5;
const int not_found = -1;

struct score {
	int points_made;
	int max_possible_points;
};

struct student {
	int id;
	string Last;
	string First;
	int num_scores;
	score student_scores[max_num_scores];
};

void intit(student temp[]){
	for (int i = 0; i < max_students; i++) {
		temp[i].id = 0;
		temp[i].Last = "";
		temp[i].First = "";
		
		for (int j = 0; j < max_num_scores; j++) {
			temp[i].student_scores[j].points_made = 0;
			temp[i].student_scores[j].max_possible_points = 0;
		}
	}
}

int load(student temp[]) {
	int num_of_students;
	int num_of_scores;
	
	ifstream f;

	f.open("grades.txt");

	if (f.fail()) {
		cout << "No data file found...starting new class" << endl;
		num_of_students = 0;
	}
	else {

		f >> num_of_students;
;
		for (int i = 0; i < num_of_students; i++) {
			f >> temp[i].id >> temp[i].First >> temp[i].Last >> temp[i].num_scores;
			for (int j = 0; j < temp[i].num_scores; j++) {
				f >> temp[i].student_scores[j].points_made >> temp[i].student_scores[j].max_possible_points;
			}
		}
	}
	//cout << num_of_students<< endl;
	//cout << temp[0].id << temp[0].First << temp[0].Last << endl;
	//cout << num_of_students << " ...." << endl;

	f.close();
	
	return num_of_students;
}

void displayMenu() {
	cout << "+-----------------------------------------------------------------------+" << endl;
	cout << "|                How about a software for Grading                       |" << endl;
	cout << "|                 By Jainam Dhruvva a.k.a JADX03                        |" << endl;
	cout << "+-----------------------------------------------------------------------+" << endl;
	cout << "A - Add Student                              D - Drop Student            " << endl;
	cout << "V - View Student                             P - Print Class             " << endl;
	cout << "S - Sort by Avg                              N - Sort by Name            " << endl;
	cout << "E - Enter New Scores                         X - Exit                    " << endl;
	
}

char getOption() {
	string option;
	
	char opt;

	string validOptions = "ADNVEPSX"; 
	
	int return_val = -1;

	int found;
	 
	
	while (return_val == -1) {
		cout << "Enter option: ";
		if (cin.peek() == '\n') cin.ignore(); // discard any leading newline
		getline(cin, option); // get entire line of input, spaces & all
		opt = toupper(option[0]);

		int found = validOptions.find(opt);
		
		if (found != -1) {
			return_val = found;
		}
	}

	//cout << opt;
	return opt;
	
}

void write(student temp[], int arr_len) { // Executes at end
	ofstream g;

	g.open("gradesout.txt");

	if (g.fail()) {
		cout << "Unable to open output file.";
	}
	else {

	

		g << arr_len << endl;
		
		int num_scores;

		for (int i = 0; i < arr_len ; i++) {
			g << temp[i].id << " " << temp[i].First << " " << temp[i].Last << " " << temp[i].num_scores << " " ;

			for (int j = 0; j < temp[i].num_scores; j++) {
				g << temp[i].student_scores[j].points_made << " " << temp[i].student_scores[j].max_possible_points << " " ;
			}
			g << endl;
		}
	}
	//cout << num_of_students<< endl;
	//cout << temp[0].id << temp[0].First << temp[0].Last << endl;

	g.close();
} 


float getAvg(score temp[], int arr_len) { // Integer in score data to float conversation!!!! . Multiplied by 1.0

	float return_val = 100.0, sum = 0.00, avg;
	
	if (arr_len == 0) {
		return_val = 100.0;
	}
	else {
		for (int i = 0; i < arr_len; i++) {

			float tempsum = ((1.0 * temp[i].points_made) / (1.0 * temp[i].max_possible_points));

			sum += tempsum;
		}

		float dec_avg = ((1.0* sum) /(1.0* arr_len));
		
		avg = dec_avg * 100.0;

		return_val = avg;
	}

	return return_val;
}

char getGrade(float percent) {
	char grade;

	if (percent >= 90) {
		grade = 'A';
	}
	else if (percent >= 80) {
		grade = 'B';
	}
	else if (percent >= 70) {
		grade = 'C';
	}
	else if (percent >= 60) {
		grade = 'D';
	}
	else {
		grade = 'E';
	}

	return grade;
}

void printReport(student temp[], int student_len) { // do not touch. It works.
	cout << setw(4) << left << "ID" << " ";
	
	cout<< setw(20) << left << "Name" << " " ;
	cout << setw(5) << left << "Avg" << " ";
	cout << setw(3) << left << "Grd" << " ";
	cout << setw(40) << left << "Scores" << endl;

   cout << "----" << " " << "--------------------" << " " << "-----" << " " << "---" <<" " << "----------------------------------------" << endl;
   
   for (int i = 0; i < student_len; i++) {
	   
	   cout << setw(4) << temp[i].id << " ";
		
	   string name = temp[i].Last + ", " + temp[i].First;
	   cout << setw(20) << name << " " ;

	   //float avg = getAvg(temp[i].student_scores);
	   //cout << setw(5) << fixed << setprecision(1) << avg << " ";
	   //cout << setw(3) << getGrade(avg) << " ";

	   float avg = getAvg(temp[i].student_scores, temp[i].num_scores);
	   cout << setw(5) << setprecision(3) << left << avg << " ";

	   char grade = getGrade(avg);
	   cout << setw(3) << left << grade;
	   
	   cout << setw(40);
	   for (int j = 0; j < temp[i].num_scores; j++) {
		   
		   cout << setw(3) << right << temp[i].student_scores[j].points_made<< "/" << setw(3)<<left <<  temp[i].student_scores[j].max_possible_points<< " ";

	   }
	   cout << endl;
   }
   
}

int addStudent(student temp[], int arr_len) { // Remember to increment the array length after execution in the main function
	if (arr_len == (max_students)) {
		cout << "No more students may be added";
		return not_found;
	}
	else {
		int j = arr_len;
			cout << "Enter student id: ";
			cin >> temp[j].id;
			cout << "Enter first and Last Name: ";
			cin >> temp[j].First >> temp[j].Last;

			//cout << temp[j].First << temp[j].Last;

			cout << "Enter the number of scores: ";
			cin >> temp[j].num_scores;

			while (temp[j].num_scores > 5) {
				cout << "Invalid number of scores! " << endl;
				cout << "Enter the number of scores: ";
				cin >> temp[j].num_scores;
			}
			for (int i = 0; i < temp[j].num_scores; i++) {
				cout << "Enter score " << i+1 << " (made possible): ";
				cin >> temp[j].student_scores[i].points_made >> temp[j].student_scores[i].max_possible_points;
			}
		
		cout << "New Student Addded" << endl;
		 
		return 1;
	
	}

	cout << temp[arr_len].id << " " << temp[arr_len].First << " " << temp[arr_len].Last;
}

int search(student temp[], int arr_len, int studentid) {
	
	int return_val = -1;

	for (int i = 0; i < arr_len; i++) {
		if (temp[i].id == studentid) {
			return_val = i;
		}
	}

	return return_val;
}

int findStudent(student temp[], int arr_len) {
	
	int usr_in_id;

	cout << "Enter user ID: ";
	cin >> usr_in_id;

	int return_val = search(temp, arr_len, usr_in_id);

	if (return_val == not_found) {
		cout << "Student id " << usr_in_id << " not found." << endl;
	}

	return return_val;

}

student removeStudent(student temp[], int arr_len, int index_to_remove) {
	
	student rem;

	if (index_to_remove >= 0 && index_to_remove < arr_len) {
		
		rem = temp[index_to_remove];

		arr_len--;

		for (int i = index_to_remove; i < arr_len; i++) {
			temp[i] = temp[i + 1];
		}

		return rem;
	}

}

int dropStudent(student temp[], int arr_len) {// Remember to decrease the array length after execution in the main function

	int found_val = findStudent(temp, arr_len);

	if (found_val >= 0) {
		student stud_rem = removeStudent(temp, arr_len, found_val);
		
		cout << stud_rem.First << " " << stud_rem.Last << " removed" << endl;
		return 1;
	}


}

void viewStudent(student temp[], int arr_len) { // It works. Do not touch.


	int found = findStudent(temp, arr_len);

	if (found != -1) {
		float avg = getAvg(temp[found].student_scores, temp[found].num_scores);
		char grade = getGrade(avg);

		cout << "ID:  " << setw(5) << left << temp[found].id << " Name:  " << temp[found].First << ", " << temp[found].Last<< endl;
		cout << "Avg: " << setw(5) << left << avg            << " Grade: " << grade<<endl;
		cout << "Number of Scores: " << temp[found].num_scores<< endl;

		cout << "Scores:           ";

		for (int j = 0; j < temp[found].num_scores; j++) {
			cout << temp[found].student_scores[j].points_made <<"/" << temp[found].student_scores[j].max_possible_points << " " ;
		}

		cout << endl;
	}


}

void swap(student temp[], int ind1, int ind2) { // Can be used in the following sort function but didnt use it. The submission doc doesnt require so. 
	student local = temp[ind1];

	temp[ind1] = temp[ind2];

	temp[ind2] = local;

}

void sortByName(student temp[], int arr_len) {
	
	for (int i = 0; i < arr_len - 1; i++) {
		for (int j = i+1; j < arr_len ; j++) {
			
			if (temp[i].Last != temp[j].Last) {
				if (temp[j].Last < temp[i].Last) {
					student local = temp [i];
					temp[i] = temp[j];
					temp[j] = local;

				}
			}
			else {
				string last1 = temp[i].Last;
				string first1 = temp[i].First;
				string w1 = last1 + first1;

				string last2 = temp[j].Last;
				string first2 = temp[j].First;
				string w2 = last2 + first2;
				if (w2 < w1) {
					student local = temp[i];
					temp[i] = temp[j];
					temp[j] = local;
				}
			}
		}
	}
	
	cout << "Class sorted by name" << endl;
}

void sortByAvg(student temp[], int arr_len) {
	
	for (int i = 0; i < arr_len- 1; i++) {
		for (int j = i+1; j < arr_len; j++) {
			float avg1 = getAvg(temp[i].student_scores, temp[i].num_scores);
			float avg2 = getAvg(temp[j].student_scores, temp[j].num_scores);
			if (avg2 < avg1) {
				student local = temp[i];
				temp[i] = temp[j];
				temp[j] = local;
			}
		}
	}
	cout << "Class sorted by Average" << endl;
}

void enterScores(student temp[], int arr_len) {
	
	sortByName(temp, arr_len);

	int TotalScore;
	cout << "Enter points possible for this assignment: ";
	cin >> TotalScore;

	for (int i = 0; i < arr_len ; i++) {
		

			int local_score;
			string local = temp[i].Last + ", " + temp[i].First;
			cout << temp[i].id << " " << setw(20) << left << local;

			if (temp[i].num_scores < 5) {
				cin >> local_score;

				temp[i].student_scores[temp[i].num_scores].points_made = local_score;
				temp[i].student_scores[temp[i].num_scores].max_possible_points = TotalScore;

				temp[i].num_scores += 1;

				//cout << endl;
			}
			else {
				cout << "Max Scores Exceeded" << endl ;
			}

	}


}



void main() {
	
	student student_array[max_students];
	intit(student_array);
	
	int num_of_students;
	int score_length = max_num_scores;

	
	num_of_students = load(student_array);
	
	char usr_in;

	
		displayMenu();
		usr_in = getOption();

		while (usr_in != 'X') {


			if (usr_in == 'A') {
				//addStudent(student_array, num_of_students);
				
				int returnval = addStudent(student_array, num_of_students);

				if (returnval == 1) {
					num_of_students += 1;
				}
				system("pause");
				cout << endl;
			}
			else if (usr_in == 'D') {
				int rval = dropStudent(student_array, num_of_students);

				
				if (rval == 1) {
					num_of_students -= 1;
				}
				system("pause");
				cout << endl;
			}
			else if (usr_in == 'V') {
				viewStudent(student_array, num_of_students);
				system("pause");
				cout << endl;
			}
			else if (usr_in == 'P') {
				printReport(student_array, num_of_students);
				system("pause");
				cout << endl;
			}
			else if (usr_in == 'S') {
				sortByAvg(student_array, num_of_students);
				system("pause");
				cout << endl;
			}
			else if (usr_in == 'N') {
				sortByName(student_array, num_of_students);
				system("pause");
				cout << endl;
			}
			else if (usr_in == 'E') {
				enterScores(student_array, num_of_students);
				system("pause");
				cout << endl;
			}

			displayMenu();
			usr_in = getOption();
		}
	
	
	write(student_array, num_of_students);

	cout << "Class Data written to file" << endl;
	cout << "Thank you for Using \"How about a software for Grading\"! " << endl;

	system("pause");
}
//End.