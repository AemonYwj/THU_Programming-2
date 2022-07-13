#include "User.h"
#include <fstream>
#include <iostream>
using namespace std;

User::~User() {
	nUser -= 1;
}

User::User(){
	nUser += 1;
	cIds = NULL;
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

clsls* User::getcIds() {
	return cIds;
}

ofstream& operator<<(ofstream& ofs, User& usr) {
	ofs << "Id: " << usr.id << " Authority: " << usr.authority << " name: "
		<< usr.name << " Password: " << usr.pswd;
	clsls* clsptr = usr.cIds;
	while (clsptr != NULL)
	{
		ofs << " " << clsptr->cid;
		clsptr = clsptr->next;
	}
	return ofs;
}

ifstream& operator>>(ifstream& ifs, User& usr) {
	char temp[20];
	char temp1[20];
	char temp2[20];
	ifs >> temp >> usr.id >> usr.authority >> temp1
		>> usr.name >> temp2 >> usr.pswd;
	int cId;
	while (ifs >> cId)
	{

	}
	return ifs;
}

char* User::getPswd() {
	return this->pswd;
}

bool User::registerClass(int cid) {
	clsls* ptr = cIds;
	while (ptr != NULL)
	{
		if (cid == ptr->cid)
		{
			cout << "You have already attended this class. Please try again.\n";
			return false;
		}
		ptr = ptr->next;
	}
	cIds = new clsls(cid, cIds);
	return true;
}

bool User::withdrawClass(int cid) {
	//clsls* ptr = cIds;
	//clsls* tempPte = NULL;
	//while (ptr != NULL)
	//{
	//	if (cid == ptr->cid)
	//	{
	//		
	//	}
	//	ptr = ptr->next;
	//}
}