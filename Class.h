#pragma once
#include <vector>
#include <string>

class Class {
public:
	Class(int cid,char* tch,char* clsn);
	void Add_Stu(int sid);
	void saveCls();
private:
	int cId; // class id
	char teacher[20]; // the name of the teacher
	char clsname[20]; // the name of the class
};

class GPA :public Student, public Class {
public:

private:
};