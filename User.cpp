#include "User.h"
#include <fstream>
#include <iostream>
using namespace std;

User::~User() {
	nUser -= 1;
}

User::User(){
	nUser += 1;
}

int User::getId() {
	return this->id;
}

int User::getAuthority() {
	return this->authority;
}

char* User::getName() {
	return this->name;
}

ofstream& operator<<(ofstream& ofs, User& usr) {
	ofs << "Id: " << usr.id << " Authority: " << usr.authority << " name: "
		<< usr.name << " Password: " << usr.pswd << endl;
	return ofs;
}

ifstream& operator>>(ifstream& ifs, User& usr) {
	char temp[20];
	char temp2[20];
	ifs >> usr.id >> usr.authority >> temp
		>> usr.name >> temp2 >> usr.pswd;
	return ifs;
}



char* User::getPswd() {
	return this->pswd;
}

