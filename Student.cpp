#include "Student.h"


Student::Student(int idCode, char* names, char* password){
	id = idCode;
	strcpy(name, names);
	strcpy(pswd, password);
	authority = 0;
}