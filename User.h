#pragma once
#include "Class.h"
#include <string>

class User
{
public:
	User(int a,int id,Class** cls,int num);
	~User();
	Class** list_all_classes();
	void Add_Class(Class cls);
	void Dlt_Class(Class cls);
	static int nUser;
private:
	int authority;	// to distinguish pupils and teachers, 0 for stus, 1 for teachers.
	int id;	// id of user; unique to all
	string name;
	//int** cid_list; // the list of class id
	int nCls; // number of classes
	Class** cList; // the list of classes.
	string pswd;
};

