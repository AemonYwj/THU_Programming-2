#include "TeacherMenu.h"
#include <iostream>
using namespace std;

int TeacherMenu::showMenu() {
	cout << "Please choose a operation by entering the starting serial number;\n"
		<< "1.Show GPA info;\n"
		<< "2.Register a class that you teach;\n"
		<< "3.Upload GPA info;\n"
		<< "4.Show class info;\n"
		<< "0.Exit system;\n";
	int chc;
	cin >> chc;
	while (chc != 0 && chc != 1 && chc != 2 && chc != 3 && chc != 4) {
		cout << "Please enter the serial number of the operation, such as 1 for 'Show GPA info'.\n";
		cout << "No other input will be seen as valid.\n";
		cin >> chc;
	}
	return chc;
}

int TeacherMenu::show1stMenu() {
	system("cls");
	cout << "Please choose a operation by entering the starting serial number;\n"
		<< "1.Show the student's average grade of all the class you teach;\n"
		<< "2.Show detailed GPA info of one specific class\n"
		<< "3.Show raw data of one specific class\n"
		<< "0.Return to previous menu;\n";
	int chc;
	cin >> chc;
	while (chc != 0 && chc != 1 && chc != 2 && chc != 3 && chc != 4) {
		cout << "Please enter the serial number of the operation, such as 1 for 'Show GPA info'.\n";
		cout << "No other input will be seen as valid.\n";
		cin >> chc;
	}
	return  chc;
}

int TeacherMenu::show4thMenu() {
	system("cls");
	cout << "Please choose a operation by entering the starting serial number;\n"
		<< "1.Show all class info;\n"
		<< "2.Show one specific class info\n"
		<< "0.Return to previous menu;\n";
	int chc;
	cin >> chc;
	while (chc != 0 && chc != 1 && chc != 2) {
		cout << "Please enter the serial number of the operation, such as 1 for 'Show GPA info'.\n";
		cout << "No other input will be seen as valid.\n";
		cin >> chc;
	}
	return  chc;
}