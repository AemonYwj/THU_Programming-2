#pragma once
#include "Class.h"
#include <fstream>
#include <iostream>
using namespace std;

struct GPA
{
	Class cls;
	float grades;
};

class User
{
public:
	User();
	~User();
	Class** list_all_classes();
	static int nUser;
	char* getPswd();
	int getId();
	int getAuthority();
	char* getName();
	friend ofstream& operator<<(ofstream& ofs, User& usr);
	friend ifstream& operator>>(ifstream& ifs, User& usr);
protected:
	int authority;	// to distinguish pupils and teachers, 0 for stus, 1 for teachers.
	int id;	// id of user; unique to all
	char name[20];
	//int** cid_list; // the list of class id
	char pswd[20]; //password
};

