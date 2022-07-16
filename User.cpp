#include "User.h"
#include <fstream>
#include <iostream>
using namespace std;

User::~User() {
	//delete[] cIds;
}

User::User(){
	cIds = NULL;
}

int User::getId() {
	return id;
}

int User::getAuthority() {
	return authority;
}

char* User::getName() {
	return name;
}

clsls* User::getcIds() {
	return cIds;
}

void User::alterCids(clsls* cids) {
	cIds = cids;
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
	ofs << endl;
	return ofs;
}

ifstream& operator>>(ifstream& ifs, User& usr) {
	char temp[20];
	char temp1[20];
	char temp2[20];
	char temp3[20];
	ifs >> temp >> usr.id >> temp1 >> usr.authority >> temp2
		>> usr.name >> temp3 >> usr.pswd;
	int cId;
	char space;
	space = ifs.get();
	usr.cIds = NULL;
	while (space != '\n' && !ifs.eof())
	{
		ifs >> cId;
		usr.cIds = new clsls(cId, usr.cIds);
		space = ifs.get();
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
	clsls* ptr = cIds;
	clsls* tempPtr = ptr;
	int i = 0;
	while (ptr != NULL)
	{
		if (cid == ptr->cid)
		{
			tempPtr->next = ptr->next;
			if (i==0)
			{
				cIds = cIds->next;
			}
			delete[] ptr;
			return true;
		}
		tempPtr = ptr;
		ptr = ptr->next;
		i++;
	}
	return false;
}