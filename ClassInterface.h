#pragma once
#include "Class.h"
#include "Student.h"
#include "Teacher.h"
#include "Interface.h"


//ClassInterface is used to control the class infomation stored in the system
//DATA ATTRIBUTES include:
//	Class** classes (store all the exsiting classes)
//	int cNum (the number of classes)
//	Interface* itfPtr (points to the Interface object created in the program)
class ClassInterface
{
public:
	ClassInterface(Interface& intf);
	~ClassInterface(); 

	//INPUT: the Interface object created in the system
	//to initiate the classinterface using class info file;
	void init(Interface &intf);

	//save all info into one file
	void save();	

	//add one Class to the 'classes' attributes in this class
	void addClass();	

	//return the subindex of class which had the same id in the Class array, 
	//or return -1 if no match exists.
	int locOfcId(int cid);	

	//for teacher
	//INPUT: User* usr
	//shows the ave GPA of all the classes taught by the input
	void showAllClassInfo(User* usr);	

	//for teacher
	//INPUT: User* usr, a teacher
	//NOTE: shows the detailed Info of one specific class
	//	including the highest score, lowest s.. total stu number,
	//	and how many studs failed the class
	void showDetailedInfo(User* usr);	

	//For TEACHER
	//INPUT: User* usr, a teacher
	//NOTE shows the Raw data of one specific class the INPUT teached
	//	including stud ID, namd, grade
	void showRawData(User* usr);	

	//For TEACHER
	//INPUT: User* usr, a teacher
	//NOTE: this func is used to add one teacher (INPUT) to one existing class as its teacher
	//	(I am not sure if I really used this func)
	void lectureClass(User* usr);	

	//For TEACHER
	//INPUT: User* usr, a teacher
	//NOTE; this function lets the INPUT upload GPA info to one specific class it teached
	void uploadGPA(User* usr);		

	//For STUDENT
	//INPUT: User* usr, a student
	//NOTE: shows GPA of all the classes attended by the INPUT
	void showAllGPAInfo(User* usr);	

	//For STUDENT
	//INPUT: User* usr, a student
	//NOTE: shows GPA info of one Specific class
	//	actually, a little useless when you think of it, as we already got
	//	the above 'showAllGPAInfo' function
	void showOneSpecGPAInfo(User* usr);

	//For STUDENT
	//INPUT: User* usr, a student
	//NOTE: calculate the average GPA among all the classes attended by the INPUT,
	//	whose GPA info has already been uploaded.
	void calGPA(User* usr);

	//Input: User* usr
	//Output: void
	//add the user to one exsiting class
	void registerClass(User* usr);

	//Input: User* usr
	//Output: void
	//delete the user from one exsiting class
	void withdrawClass(User* usr);

	//--------------data--------------

	//the list of classes in the system
	Class** classes;	

	//the total number of classes
	int cNum;	

	//points to the Interface object created in the program, which is used to control user infos
	Interface* itfPtr;	
};
