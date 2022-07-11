#pragma once
#pragma once
#include "User.h"

class Teacher :public User {
public:
	Teacher(int idCode, char* names, char* password);
	~Teacher();
private:

};