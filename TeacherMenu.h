#pragma once
#include "Menu.h"
#include <iostream>
using namespace std;

class TeacherMenu:public Menu
{
public:
	virtual int showMenu();
	virtual int show1stMenu();
	virtual int show2ndMenu();
	virtual int show3thMenu();
	virtual int show4thMenu();
private:

};

int showMenu() {
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
	system("clc");
	cout << "Please choose a operation by entering the starting serial number;\n"
		<< "1.Show GPA info;\n"
		<< "2.Register a class that you teach;\n"
		<< "3.Upload GPA info;\n"
		<< "4.Add a user;\n"
		<< "0.Exit system;\n";
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
	system("clc");
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