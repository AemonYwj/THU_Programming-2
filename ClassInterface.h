#pragma once
#include "Class.h"
#include "Student.h"
#include "Teacher.h"
#include "Interface.h"

class ClassInterface
{
public:
	ClassInterface(Interface& intf);
	~ClassInterface(); 
	void init(Interface &intf);	// to initiate the interface using class info file;
	void save();	// save all info into one file
	void addClass();	// add one Class
	int locOfcId(int cid);	// return the subindex of User who had the same id in the User array, 
							// or return -1 if no match exists.

	void showAllClassInfo(User* usr);	// for teacher
	void showDetailedInfo(User* usr);	// for teacher
	void showRawData(User* usr);	// for teacher
	void lectureClass(User* usr);	// for teacher
	void uploadGPA(User* usr);		// for teacher

	void showAllGPAInfo(User* usr);	// for student
	void showOneSpecGPAInfo(User* usr);	// for student
	void calGPA(User* usr);	// for student
	void registerClass(User* usr);
	void withdrawClass(User* usr);

	//--------------data--------------
	Class** classes;
	int cNum;
	Interface* itfPtr;
};
