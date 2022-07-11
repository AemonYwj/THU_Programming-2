#pragma once
#include <vector>
#include <string>

class Class {
public:
	Class(int cId, int** sIdList);
	void Add_Stu(int sid);
private:
	int cId; // class id
	int** sIdList;	// the list of students attending this class
};