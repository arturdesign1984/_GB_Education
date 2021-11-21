#include <iostream>

using namespace std;

int main()
{
/////////////////////////////////////////////// Exercise 1:

	cout << "\n\tExercise 1:\n\n" << endl;

	int number11 = 0, number12 = 0, result1 = 0;

	cout << "Enter number 1: ";
	cin >> number11;
	cout << endl << "Enter number 2: ";
	cin >> number12;

	result1 = number11 + number12;

	if (result1 >= 10 && result1 <= 20) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
////////////////////////////////////////////// Exercise 2:

	cout << "\n\tExercise 2:\n\n" << endl;

	int number21 = 10, number22 = 10, result2 = 0;

	result2 = number21 + number22;

	if (number21 == 10 && number22 == 10 || result2 == 10) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
////////////////////////////////////////////// Exercise 3:

	cout << "\n\tExercise 3:\n\n" << endl;

	cout << "Your numbers: ";
	for (int i = 1; i < 50; i += 2) {
		cout << i << ' ';
	}
	cout << endl;

////////////////////////////////////////////// Exercise 4:

	cout << "\n\tExercise 4:\n\n" << endl;

	int prime = 0, flag = 0;

	cout << "Enter number: ";
	cin >> prime;

	if (prime == 1) {
		cout << "number is prime" << endl;
	}
	else {
		flag = 0;
		for (int i = 2; i < prime; i++) {
			if (prime%i == 0) {
				cout << "number is not prime" << endl;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "number is prime" << endl;
		}
	}
////////////////////////////////////////////// Exercise 5:

	cout << "\n\tExercise 5:\n\n" << endl;

	int year = 0;

	cout << "Enter year (1-3000): ";
	cin >> year;
	if (year >= 1 && year <= 3000) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			cout << "Year is leap" << endl;
		}
		else {
			cout << "Year is not leap" << endl;

		}
	}
	else {
		cout << "Error! Out of range."<< endl;
	}

	return 0;
}
