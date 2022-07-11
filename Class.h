#pragma once
#include <vector>
#include <string>

class Class {
public:
	Class(int cId,char* teacher);
	void Add_Stu(int sid);
	void saveCls();
private:
	int cId; // class id
	char teacher[20]; // the name of the teacher
	char clsname[20]; // the name of the class
};