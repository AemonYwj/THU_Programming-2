#include "Interface.h"
#include <iostream>
#include <fstream>
#include <conio.h> 
#define UserFile "UserInfo.txt"
using namespace std;

Interface::Interface() {
	fstream file;
	file.open(UserFile, ios::in);
	//detect if the file exist, if not, end the program
	if (!file.is_open()) {
		cout << "No Userfile! Please CHECK! " << endl
			<< "System will SHUT DOWN." << endl;
		uNum = 0;
		users = NULL;
		file.close();
		system("pause");
		exit(-1);
		return;
	}
	//detect if the file contains any info by check if it's the end of file
	char ch;
	file >> ch;
	if (file.eof())
	{
		cout << "No user info in user file.\n";
		uNum = 0;
		this->users = NULL;
		file.close();
		return;
	}
	//else, the file exists and got content.
	file.close();
	init();
}

void Interface::init() {
	ifstream file;
	file.open(UserFile, ios::in);
	char temp[20], temp2[20];
	int id, authority;
	char name[20], pswd[20];
	int index = 0;
	User* tempUsr = new User;
	char space = ' ';
	while (!file.eof()) {
		file >> *tempUsr;
		index ++;
	}	//get the total amount of users in the file
	file.close();
	file.open(UserFile, ios::in);
	this->uNum = index-1;
	index = 0;
	tempUsr = new User;
	users = new User*[uNum];
	for (index = 0; index < uNum; index++) {
		file >> *tempUsr;
		id = tempUsr->getId();
		authority = tempUsr->getAuthority();
		strcpy(name, tempUsr->getName());
		strcpy(pswd, tempUsr->getPswd());
		User* usr = NULL;
		if (authority == 0)
			usr = new Student(id, name, pswd, tempUsr->getcIds());
		else if (authority == 1)
			usr = new Teacher(id, name, pswd, tempUsr->getcIds());
		users[index] = usr;
		//there may be a problem of over using the memory space...
		//I am not sure anyway... will fix it someday, maybe, if I could catch the ddl...
	}
	file.close();
}

int Interface::login(User* &usr) {
	bool flag = true;
	while (flag) {
		switch (this->uNum)
		{
		case 0:	//no any Users
			cout << "Please initiate the system by signing up: \n";
			addUser();
			break;
		default:
			cout << "Do you wish to login by exsiting account or creating a new account?\n";
			cout << "1.I will login.\n"
				<< "2.I am new to the system, I'll sign up.\n";
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
				break;
			default:
				addUser();
				break;
			}
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
					this->lgUsr = users[index];
					system("cls");
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
	User** newUsrs = new User * [uNum+1];	//creating a temperary array to store the data.
	if (this->users != NULL) { //copying original space into the new array
		for (int i = 0; i < this->uNum; i++) {
			newUsrs[i] = this->users[i];
		}
	}
	int chc;
	cout << "Please choose the new User's identity (enter number 1 or 2): " << endl
		<< "1.Students" << endl	
		<< "2.Teachers" << endl;
	cin >> chc;
	while (chc!=1 && chc!=2)
	{
		cout << "Please enter either number 1 or 2, nothing else is taken as valid input.\n";
		cin >> chc;
	}
	int id;
	char name[20],pswd[20];
	int classid = 0;
	clsls* newCls = NULL;
	switch (chc)
	{
	case 1:
		cout << "Please enter your id\n";
		cin >> id;
		while (locOfId(id) != -1)
		{
			cout << "This id alread signed up for this system, please enter another.\n";
			cin >> id;
		}
		cout << "Please enter your name\n";
		cin >> name;
		cout << "Please enter your password\n";
		cin >> pswd;
		cout << "Please enter one by one the id of the classes you are attending, and enter '-1' to end your operation\n";
		cin >> classid;
		while (classid != -1)
		{
			newCls = new clsls(classid, newCls);
			cin >> classid;
		}
		newUsrs[uNum] = new Student(id, name, pswd,newCls);

		delete[] users;	//release the original space
		users = newUsrs;	//relocating the ptr
		break;
	case 2:
		cout << "Please enter your id\n";
		cin >> id;
		while (locOfId(id) != -1)
		{
			cout << "This id alread signed up for this system, please enter another.\n";
			cin >> id;
		}
		cout << "Please enter your name\n";
		cin >> name;
		cout << "Please enter your password\n";
		cin >> pswd;
		cout << "Please enter one by one the id of the classes you are lecturing, and put '-1' to end your operation\n";
		cin >> classid;
		while (classid != -1)
		{
			newCls = new clsls(classid, newCls);
			cin >> classid;
		}
		newUsrs[uNum] = new Teacher(id, name, pswd, newCls);
		delete[] users;	
		users = newUsrs;
		break;
	}
	cout << "Successfully added one user\n";
	uNum++;
	save();
}

int Interface::locOfId(int id) {
	int index = -1;
	for (int i = 0; i < this->uNum; i++)
	{
		if (users[i]->getId() == id) { //to find the User
			index = i;
			break;
		}
	}
	return index;
}

void Interface::save() {
	ofstream file;
	file.open(UserFile, ios::out);
	for (int i = 0; i < uNum; i++) {
		file << *users[i];
	}
	file.close();
}

void Interface::list_all_classes(Class**& clsptr, int& clsNum) {
	clsls* lgCls = lgUsr->getcIds();
	while (lgCls != NULL)
	{

	}
}

User** Interface::getUsers() {
	return users;
}

int Interface::getUserNum() {
	return uNum;
}