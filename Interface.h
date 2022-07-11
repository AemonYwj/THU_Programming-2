#pragma once
#include "User.h"



class Interface
{
public:
	Interface();
	~Interface();
	void init();	// to initiate the interface using user's info file and class info file;
	int login();	// return the authority of the user (0 for students, 1 for teachers)
	void save();	// save all info into one file
	void addUser();
	int isIdExist(int id);	// return the subindex of User who had the same id in the User array, 
							// or return -1 if no match exists.
	virtual void menu();
protected:
	User** users;
	int Unum;
};

