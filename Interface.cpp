#include "Interface.h"
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>
#include <conio.h> 
#define UserFile "UserInfo.txt"
#define ClassFile "ClassInfo.txt"
using namespace std;

Interface::Interface() {
	fstream file;
	file.open(UserFile, ios::in);
	// detect if the file exist, if not, end the program
	if (!file.is_open()) {
		cout << "No Userfile! Please CHECK! " << endl
			<< "System will SHUT DOWN." << endl;
		Unum = 0;
		users = NULL;
		file.close();
		system("pause");
		exit(-1);
		return;
	}
	// detect if the file contains any info by check if it's the end of file
	char ch;
	file >> ch;
	if (file.eof())
	{
		cout << "No info in user file.\n";
		Unum = 0;
		users = NULL;
	}
	// else, the file exists and got content.
	init();
}

void Interface::init() {
	fstream file;
	file.open(UserFile, ios::in);
	char temp[20], temp2[20];
	int id, authority;
	char name[20], pswd[20];
	int index = 0;
	while (file >> id >> authority >> temp >> name >> temp2 >> pswd) {
		index++;
	}	// get the total amount of users in the file
	this->Unum = index;
	index = 0;
	users = new User*[Unum];
	while (file >> id >> authority >> temp >> name >> temp2 >> pswd) {
		User* usr = NULL;
		if (id == 0)
			usr = new Student(id, name, pswd);
		else if (id == 1)
			usr = new Teacher(id, name, pswd);
		users[index] = usr;
		index++;
	}
	file.close();
}

int Interface::login(User* &usr) {
	bool flag = true;
	while (flag) {
		switch (this->Unum)
		{
		case 0:	// no any Users
			cout << "Please initiate the system by signing up: \n";
			addUser();
			break;
		default:
			int Id;
			bool flag1 = true;
			int index;
			while (true){
				cout << "Please put down your ID: \n";
				cin >> Id;
				index = locOfId(Id);
				if (index == -1)
					cout << "No user with match id exist, please retry! \n";
				else
					break;
			}
			while (true){
				char password[20];
				cout << "Please continue by typing your password: \n";
				cin >> password;
				int isPswdCrct = strcmp(password, users[index]->getPswd());
				if (isPswdCrct == 0) {
					flag = false;
					/*return 0;*/
					usr = users[index];
					system("clc");
					cout << "Welcome to the GPA management system " << usr->getName() << endl;
					return users[index]->getAuthority();
					break;
				}
				else {
					cout << "Wrong Password, Please try again. \n";
				}
			}
			break;
		}
	}
	return 0;
}


Interface::~Interface() {
	delete[] users;
}

void Interface::addUser() {
	Unum++;
	User** newUsrs = new User * [Unum];	// creating a temperary array to store the data.
	if (this->users != NULL) { // copying original space into the new array
		for (int i = 0; i < this->Unum-1; i++) {
			newUsrs[i] = this->users[i];
		}
	}
	int chc;
	cout << "Please choose the new User's identity (enter number 1 or 2): " << endl
		<< "1. Students" << endl	
		<< "2.Teachers" << endl;
	cin >> chc;
	while (chc!=1 && chc!=2)
	{
		cout << "Please enter either number 1 or 2, nothing else is taken as valid input.\n";
		cin >> chc;
	}
	int id;
	char name[20],pswd[20];
	switch (chc)
	{
	case 1:
		cout << "Please enter your id\n";
		cin >> id;
		cout << "Please enter your name\n";
		cin >> name;
		cout << "Please enter your password\n";
		cin >> pswd;
		newUsrs[Unum] = new Student(id, name, pswd);
		delete[] users;	// release the original space
		users = newUsrs;	// relocating the ptr
		break;
	case 2:
		cout << "Please enter your id\n";
		cin >> id;
		cout << "Please enter your name\n";
		cin >> name;
		cout << "Please enter your password\n";
		cin >> pswd;
		newUsrs[Unum] = new Teacher(id, name, pswd);
		delete[] users;	
		users = newUsrs;
		break;
	}
	cout << "Successfully added one user\n";
	save();
}

int Interface::locOfId(int id) {
	int index = -1;
	for (int i = 0; i < this->Unum; i++)
	{
		if (this->users[i]->getId() == id) { // to find the User
			index = i;
			break;
		}
	}
	return index;
}

void Interface::save() {
	ofstream file;
	file.open(UserFile, ios::out);
	for (int i = 0; i < Unum; i++) {
		file << users[i];
	}
	file.close();
}