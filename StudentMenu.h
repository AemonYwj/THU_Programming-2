#pragma once
#include "Menu.h"
#include <iostream>
using namespace std;


class StudentMenu:public Menu{
public:
	virtual int showMenu();
	virtual int show1stMenu();
	virtual int show1stMenu();
	virtual int show2ndMenu();
	virtual int show3thMenu();
	virtual int show4thMenu();
private:

};

int StudentMenu::showMenu() {
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
	system("clc");
	cout << "Please choose a operation by entering the starting serial number;\n"
		<< "1.Show grades of all class;\n"
		<< "2.Show grade of one specific class;\n"
		<< "3.Calculate "
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
