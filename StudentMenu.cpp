#include "StudentMenu.h"
#include <iostream>
using namespace std;

int StudentMenu::showMenu() {
	system("cls");
	cout << "Please choose a operation by entering the starting serial number;\n"
		<< "1.Show GPA info;\n"
		<< "2.Register a class;\n"
		<< "3.Withdraw a class;\n"
		<< "0.Exit system;\n";
	int chc;
	cin >> chc;
	while (chc != 1 && chc != 2 && chc != 3 && chc != 0) {
		cout << "Please enter the serial number of the operation, such as 1 for 'Show GPA info'.\n";
		cout << "No other input will be seen as valid.\n";
		cin >> chc;
	}
	return  chc;
}

int StudentMenu::show1stMenu() {
	system("cls");
	cout << "Please choose a operation by entering the starting serial number;\n"
		<< "1.Show grades of all class;\n"
		<< "2.Show grade of one specific class;\n"
		<< "3.Calculate general GPA;\n"
		<< "0.Return to previous menu;\n";
	int chc;
	cin >> chc;
	while (chc != 1 && chc != 2 && chc != 3 && chc != 0) {
		cout << "Please enter the serial number of the operation, such as 1 for 'Show GPA info'.\n";
		cout << "No other input will be seen as valid.\n";
		cin >> chc;
	}
	return  chc;
}
