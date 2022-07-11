#include "Teacher.h"

Teacher::Teacher(int idCode, char* names, char* password) {
	id = idCode;
	strcpy(name, names);
	strcpy(pswd, password);
	authority = 1;
}