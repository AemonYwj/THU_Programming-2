#pragma once
#include "User.h"

class Student:public User{
public:
	Student(int idCode,char* names,char* password);
	~Student();
private:

};

