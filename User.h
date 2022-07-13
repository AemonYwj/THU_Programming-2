#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class clsls // class list
{
public:
	int cid;
	clsls* next;
	clsls(int cId, clsls* nx = NULL) {
		cid = cId;
		next = nx;
	}
};


class User
{
public:
	User();
	~User();
	static int nUser;
	char* getPswd();
	int getId();
	int getAuthority();
	char* getName();
	friend ofstream& operator<<(ofstream& ofs, User& usr);
	friend ifstream& operator>>(ifstream& ifs, User& usr);
	clsls* getcIds();
	bool registerClass(int cid);	// cid meaning the id of the class this user wish to attend/lecture/withdraw
	bool withdrawClass(int cid);
protected:
	clsls* cIds; // the list of class ids
	int authority;	// to distinguish pupils and teachers, 0 for stus, 1 for teachers.
	int id;	// id of user; unique to all
	char name[20];
	//int** cid_list; // the list of class id
	char pswd[20]; //password
};

