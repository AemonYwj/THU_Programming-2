#pragma once
#include "User.h"

class Student:public User{
public:
	Student(int idCode,char* names,char* password,clsls* cids);
	~Student();
private:

};



class ListOfStdts {
public:
	User* stdt;

	//pointing to the next student;
	ListOfStdts* nxstdt;	

	//the grade of this course;
	double grade;	
	
	//INPUT: User* std, the ptr to the stud that is wished to be added to the LisfOfStdts object
	//	double g, the grade of the student. -1 by default, meaning no grade have been uploaded yet
	//	ListOfStdts* next, pointing to the next ListOfStdts object, in most times self
	ListOfStdts(User* std, double g = -1, ListOfStdts* next = NULL) {
		stdt = std;
		grade = g;
		nxstdt = next;
	}
};