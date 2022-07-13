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
	Class** classes;
	int cNum;

};
