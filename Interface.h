#pragma once
class Interface
{
public:
	Interface();
	virtual void init() = 0;	// to initiate the interface using user's info
	void alter_GPA();
	void show_GPA();
	virtual void login() = 0;
	virtual void save() = 0;
private:
	int authority;	// representing the identity of users, 0 for students, 1 for teachers
	int id;	// the identification code of users
	int cid;	// the identification code of class
	User** usrs;	// array of users
};

