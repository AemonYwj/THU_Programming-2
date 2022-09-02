#pragma once
#include <fstream>
#include <iostream>
using namespace std;

//clsls is a list of classes Á´±í
//DATA ATTRIBUTES:
//	int cid (the id of a class)
//	clsls* next (ptr pointed to the next clsls)
class clsls
{
public:
	int cid;
	clsls* next;
	clsls(int cId, clsls* nx = NULL) {
		cid = cId;
		next = nx;
	}
};

//User is a class used to store User info and do modifications to one user
//DATA ATTRIBUTES:
//	clsls* cIds
//	int authority (0 for stud, 1 for tch)
//	int id
//	char name[20]
//	char pswd[20]
class User
{
public:
	User();
	~User();
	char* getPswd();
	int getId();
	int getAuthority();
	char* getName();

	friend ofstream& operator<<(ofstream& ofs, User& usr);

	friend ifstream& operator>>(ifstream& ifs, User& usr);

	clsls* getcIds();

	//INPUT: cid, the id of the class this user wish to attend/lecture
	//OUTPUT: true if success
	//Note: this function changes the clsls distribution of object usr,
	//	but do not save the data.
	bool registerClass(int cid);

	//INPUT: cid, the id of the class this user wish to withdraw from
	//OUTPUT: true if success, false if otherwise
	bool withdrawClass(int cid);

	//NOTE: change the object's data attribute cIds to the INPUT
	void alterCids(clsls* cids);
protected:
	//the list of class ids
	clsls* cIds; 

	//to distinguish pupils and teachers, 0 for stus, 1 for teachers.
	int authority;	

	//id of user; unique to all
	int id;	

	//name of the user
	char name[20];
	
	//password of the user, used to login the system
	char pswd[20]; 
};

