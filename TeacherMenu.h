#pragma once
#include "Menu.h"
#include "Teacher.h"


class TeacherMenu:public Menu,public Teacher
{
public:
	virtual int showMenu();
	virtual int show1stMenu();
	virtual int show4thMenu();
private:

};
