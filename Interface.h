#pragma once
#include "User.h"
#include "Teacher.h"
#include "Student.h"
#include "Class.h"


class Interface		//Interface of the Users
{
public:
	Interface();
	~Interface();

	//to initiate the interface using user's info file
	void init();

	//INPUT: usr, can be any User* ptr, will be modified to fit the login user
	//OUTPUT: return the arthority of the user if login successes.
	int login(User* &usr);	

	//save all user info into one file
	void save();

	//add one user to the system
	void addUser();	

	//OUTPUT: return the subindex of User who had the same id in the User array, 
	//	or return -1 if no match exists.
	int locOfId(int id);	

	//make a list of all the classes the User attended to or lectured in
	//and transfer it into a array of Class ptrs and the total num of this array
	void list_all_classes(Class**& clsptr, int& clsNum);	

	User** getUsers();
	int getUserNum();
protected:
	//--------------data--------------

	//all users in the system
	User** users;	
	 
	//the logined user
	User* lgUsr;	
	
	//total number of the users
	int uNum;
};

