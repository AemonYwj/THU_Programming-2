#pragma once
#include "Interface.h"
#include "Student.h"
#include<fstream>
#define StdFile "studentInfo.txt"
using namespace std;


class GPA :public Class, public Student {

};

class StudentInterface :public Interface, public Student {
public:
	virtual void menu();
	
};