#include "User.h"

User::User(int a, int id, Class** cls, int ncls):authority(a),id(id),nCls(ncls){
	cList = cls;
	nUser += 1;
}

User::~User() {
	nUser -= 1;
	delete[] cList;
}