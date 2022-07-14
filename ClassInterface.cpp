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
	itfPtr = &intf;
	init(intf);
}

void ClassInterface::init(Interface& intf) {
	ifstream file;
	file.open(ClassFile, ios::in);
	char clsname[20];	// class name
	int cid = 0, credit = 1;	// class id and credit 
	User** users = intf.getUsers();
	User* tmpStu = new User;	
	User* tmpTch = new User;
	int tchid, stdid, gd;	// teacher id; student id; grade
	char tmpCh[20];
	int index = 0;
	while (file >> cid >> credit >> clsname >> tchid) {
		ListOfStdts* newStdts;
		while (file >> tmpCh >> stdid >> gd ){}
		index++;
	}
	file.close();
	file.open(ClassFile, ios::in);
	cNum = index;
	classes = new Class*[cNum];
	while (file >> cid >> clsname >> tchid) {
		ListOfStdts* newStdts = NULL;
		int tchIndex = intf.locOfId(tchid);
		while (file >> tmpCh >> stdid >> gd)
		{
			int stdIndex = intf.locOfId(stdid);
			newStdts = new ListOfStdts(users[stdIndex], gd, newStdts);
		}
		index++;
		classes[index] = new Class(cid, credit, users[tchIndex], clsname, newStdts);
	}
	delete[] tmpCh, tmpStu, tmpTch;
	file.close();
}


ClassInterface::~ClassInterface() {
	delete[] classes;
}

void ClassInterface::addClass() {
	Class** newClass = new Class * [cNum + 1];
	if (this->classes != NULL) {
		for (int i = 0; i < cNum; i++) {	// copying oreiginal space
			newClass[i] = classes[i];
		}
	}
	int cid, tchId, credit;
	char clsName[20];
	cout << "Please enter the name of the class you wish to add.\n";
	cin >> clsName;
	cout << "Please enter the id of the class you wish to add.\n";
	cin >> cid;
	cout << "Please enter the credit of the class you wish to add.\n";
	cin >> credit;
	cout << "Please enter the id of the teacher you wish to add.\n";
	User* tmpTch;
	while (true)
	{
		cin >> tchId;
		int tchIndex = itfPtr->locOfId(tchId);
		if (tchIndex == -1)
		{
			cout << "NO teacher with this id EXSIST, please retry.\n";
		}
		tmpTch = itfPtr->getUsers()[tchIndex];
		if (tmpTch->getAuthority() != 1) {
			cout << "This id DOES NOT belong to a teacher, please retry\n";
		}
		else
		{
			break;
		}
	}
	
	newClass[cNum + 1] = new Class(cid, credit,tmpTch, clsName);
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

void ClassInterface::showAllGPAInfo(User* usr) {
	clsls* cids = usr->getcIds();
	int id = usr->getId();
	while (cids != NULL)	// goint through all classes of this user
	{
		int index = locOfcId(cids->cid);
		Class* cls = classes[index];
		ListOfStdts* stdts = cls->stdts;
		while (stdts != NULL)	// going through all student of this specific class
		{
			int stdId = stdts->stdt->getId();
			if (stdId == id)
			{
				if (stdts->grade != -1)
				{
					cout << "The grade of class "
						<< "'" << cls->clsName << "'"
						<< " is " << stdts->grade << endl;
				}
				else
				{
					cout << "The grade of class "
						<< "'" << cls->clsName << "'"
						<< " has not yet been uploaded." << endl;
				}
			}
			stdts = stdts->nxstdt;
		}
		cids = cids->next;
	}
	system("pause");
}

void ClassInterface::showOneSpecGPAInfo(User* usr) {
	int cid;
	int id = usr->getId();
	cout << "Please enter the id of the class you wish to query.\n";
	cin >> cid;
	int index = locOfcId(cid);
	Class* cls = classes[index];
	ListOfStdts* stdts = cls->stdts;
	while (stdts != NULL)
	{
		int stdId = stdts->stdt->getId();
		if (stdId == id)
		{
			if (stdts->grade != -1)
			{
				cout << "The grade of class "
					<< "'" << cls->clsName << "'"
					<< " is " << stdts->grade << endl;
			}
			else
			{
				cout << "The grade of class "
					<< "'" << cls->clsName << "'"
					<< " has not yet been uploaded." << endl;
			}
		}
		stdts = stdts->nxstdt;
	}
	system("pause");
}

void ClassInterface::calGPA(User* usr) {
	clsls* cids = usr->getcIds();
	int id = usr->getId();
	double totalGpa = 0;
	int totalCrd = 0;
	while (cids != NULL)
	{
		int index = locOfcId(cids->cid);
		Class* cls = classes[index];
		ListOfStdts* stdts = cls->stdts;
		while (stdts != NULL)
		{
			int stdId = stdts->stdt->getId();
			if (stdId == id && stdts->grade != -1)
			{
				totalCrd += cls->credit;
				totalGpa += stdts->grade;
			}
			stdts = stdts->nxstdt;
		}
		cids = cids->next;
	}
	if (totalCrd != 0) {
		double GPA = totalGpa / totalCrd;
		cout << "Your GPA is " << GPA << " (only calculating class where your grade has been uploaded)." << endl;
	}
	else
	{
		cout << "None of your class has uploaded your grade, please try again later.\n";
	}
	system("pause");
}

void ClassInterface::registerClass(User* usr) {
	int cid;
	cout << "Please enter the id of the class you'd like to attend\n";
	cin >> cid;
	usr->registerClass(cid);
	int index = locOfcId(cid);
	Class* cls = classes[index];
	if (cls->addStudent(usr)) {
		cout << "Successfully sign up for class " << "'" << cls->clsName << "'!\n";
	}
	system("pause");
}

void ClassInterface::withdrawClass(User* usr) {
	int cid;
	cout << "Please enter the id of the class from which you'd like to withdraw.\n";
	cin >> cid;

}