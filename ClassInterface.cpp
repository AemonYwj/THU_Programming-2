#include "ClassInterface.h"

#include <iostream>
#include <fstream>
#include <conio.h> 
#define ClassFile "ClassInfo.txt"
using namespace std;


ClassInterface::ClassInterface(Interface& intf) {
	fstream file;
	file.open(ClassFile, ios::in);
	// detect if the file exist, if not, end the program
	if (!file.is_open()) {
		cout << "No Classfile! Please CHECK! " << endl
			<< "System will SHUT DOWN." << endl;
		cNum = 0;
		classes = NULL;
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
		cNum = 0;
		classes = NULL;
	}
	// else, the file exists and got content.
	init(intf);
}

void ClassInterface::init(Interface &intf) {
	ifstream file;
	file.open(ClassFile, ios::in);
	char clsname[20];	// class name
	int cid = 0;	// class id
	User** users = intf.getUsers();
	User* tmpStu = new User;	
	User* tmpTch = new User;
	int tchid, stdid, gd;	// teacher id; student id; grade
	char tmpCh[20];
	int index = 0;
	while (file >> cid >> clsname >> tchid) {
		ListOfStdts* newStdts;
		while (file >> tmpCh >> stdid >> gd ){}
		index++;
	}
	file.close();
	file.open(ClassFile, ios::in);
	cNum = index;
	classes = new Class*[cNum];
	while (file >> cid >> clsname >> tchid) {
		ListOfStdts* newStdts;
		int tchIndex = intf.locOfId(tchid);
		while (file >> tmpCh >> stdid >> gd)
		{
			int stdIndex = intf.locOfId(stdid);
			newStdts = new ListOfStdts(users[stdIndex], gd, newStdts);
		}
		index++;
		classes[index] = new Class(cid, users[tchIndex], clsname, newStdts);
	}
	file.close();
}


ClassInterface::~ClassInterface() {
	delete[] classes;
}

void ClassInterface::addClass() {
	cNum++;
	
	
	save();
}

int ClassInterface::locOfcId(int id) {
	int index = -1;
	for (int i = 0; i < this->cNum; i++)
	{
		if (this->classes[i]->cId == id) { // to find the User
			index = i;
			break;
		}
	}
	return index;
}

void ClassInterface::save() {
	ofstream file;
	file.open(ClassFile, ios::out);
	for (int i = 0; i < cNum; i++) {
		file << classes[i];
	}
	file.close();
}
