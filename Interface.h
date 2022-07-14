#pragma once
#include "User.h"
#include "Teacher.h"
#include "Student.h"
#include "Class.h"


class Interface		// Interface of the Users
{
public:
	Interface();
	~Interface();
	void init();	// to initiate the interface using user's info file and class info file;
	int login(User* &usr);	// return the authority of the user (0 for students, 1 for teachers)
	void save();	// save all info into one file
	void addUser();	// add one user
	int locOfId(int id);	// return the subindex of User who had the same id in the User array, 
							// or return -1 if no match exists.
	void list_all_classes(Class**& clsptr, int& clsNum);	// make a list of all the classes the User attended to or lectured in
														// and transfer it into a array of Class ptrs and the total num of this array
	User** getUsers();
	int getUserNum();
protected:
	//--------------data--------------
	User** users;	// all users in the system
	User* lgUsr;	// the logined user
	int uNum;
};

