#include "Teacher.h"

Teacher::Teacher(int idCode, char* names, char* password, clsls* cids) {
	id = idCode;
	strcpy(name, names);
	strcpy(pswd, password);
	cIds = cids;
	authority = 1;
}