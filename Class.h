#pragma once
#include <vector>
#include <string>
#include "Student.h"
#include "Teacher.h"

class Class {
public:
	//Class();
	//---------------Data---------------
	Class(int cid, int crdt, User* const teacher1,char* clsn,ListOfStdts* ptr = NULL);
	int cId; // class id
	int credit;
	User* teacher; // the teacher of the class
	char clsName[20]; // the name of the class
	ListOfStdts* stdts;	// Students and their grades

	//-------------operator-------------
	friend ofstream& operator<< (ofstream& ofs,const Class& cls);
	friend ifstream& operator>> (ifstream& ifs,Class& cls);

	//-------------function-------------
	bool addStudent(User* usr);	// add one student to the list
	bool deleteStudent(User* usr);	// delete one student from the list
	double getAveGPA();	// calculate average GPA of all students in this class.
	ListOfStdts* getHighestStu();
	double getHighestGPA();	// return the highest GPA in this class, -1 if none has any grade
	double getLowestGPA();	// return the lowest  GPA in this class, -1 if none has any grade
	ListOfStdts* getLowestStu();
	ListOfStdts* getFailedStu();
	ListOfStdts* getPassedStu();
	int failedStuNum();
	int passedStuNum();
};


