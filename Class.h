#pragma once
#include <vector>
#include <string>
#include "Student.h"
#include "Teacher.h"
#include <map>



class Class {
public:
	//Class();
	//---------------Data---------------
	Class(int cid, int crdt, User* const teacher1,char* clsn,ListOfStdts* ptr = NULL);
	int cId; //class id
	int credit;
	User* teacher; //the teacher of the class
	char clsName[20]; //the name of the class
	ListOfStdts* stdts;	//Students and their grades

	//-------------operator-------------
	friend ofstream& operator<< (ofstream& ofs,const Class& cls);
	friend ifstream& operator>> (ifstream& ifs,Class& cls);

	//-------------function-------------
	bool addStudent(User* usr);	//add one student to the list
	bool deleteStudent(User* usr);	//delete one student from the list
	double getAveGPA();	//calculate average GPA of all students in this class.
	ListOfStdts* getHighestStu();
	double getHighestGPA();	//return the highest GPA in this class, -1 if none has any grade
	double getLowestGPA();	//return the lowest  GPA in this class, -1 if none has any grade
	ListOfStdts* getLowestStu();
	ListOfStdts* getFailedStu();
	ListOfStdts* getPassedStu();
	int failedStuNum();
	int passedStuNum();
};




//TODO:
/*忽然想起来C++里是有一些容器的，课上也讲过，查了一下C++的Dictionary叫做map，就是映射的意思吧，
* 忽然觉得自己存储学生和课程对应关系的方式很傻逼……
* 为啥两边都要存一次……简直离谱……
* 下次改下次改
*/

/*22.08.23
* 救命已经看不懂我的代码了。
* 好久好久没动这个项目了……
* 好像还有很多bug……
* 日复一日修bug
* 字典的事有空再去管吧，但是肯定又得大改程序……yysy不如重写呢……
* 说不定重写更快……寄
*/
