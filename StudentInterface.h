#pragma once
#include "Interface.h"
#include "Student.h"
#include<fstream>
#define StdFile "studentInfo.txt"
using namespace std;


class StudentInterface :public Interface, public Student {
public:
	void menu();
	void save();
	void init();
};