#include "Class.h"

Class::Class(int cid, char* tch, char* clsn) {
	cId = cid;
	strcpy(teacher, tch);
	strcpy(clsname, clsn);
}