#pragma once
#include <vector>
#include <string>
#include "Student.h"
#include "Teacher.h"

class Class {
public:
	//Class();
	Class(int cid, int crdt, User* const teacher1,char* clsn,ListOfStdts* ptr = NULL);
	int cId; // class id
	int credit;
	User* teacher; // the teacher of the class
	char clsName[20]; // the name of the class
	ListOfStdts* stdts;	// Students and their grades
	friend ofstream& operator<< (ofstream& ofs,const Class& cls);
	friend ifstream& operator>> (ifstream& ifs,Class& cls);
	bool addStudent(User* usr);
};


