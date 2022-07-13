#include "Student.h"


Student::Student(int idCode, char* names, char* password, clsls* cids){
	id = idCode;
	strcpy(name, names);
	strcpy(pswd, password);
	cIds = cids;
	authority = 0;
}