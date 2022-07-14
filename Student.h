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
	ListOfStdts* nxstdt;	// pointing to the next student;
	double grade;	// the grade of this course;

	ListOfStdts(User* std, double g = -1, ListOfStdts* next = NULL) {
		stdt = std;
		grade = g;
		nxstdt = next;
	}

};