#include "Class.h"

Class::Class(int cid, int crdt, User* const teacher1, char* clsn, ListOfStdts* ptr) {
	cId = cid;
	credit = crdt;
	teacher = teacher1;
	strcpy(clsName, clsn);
	stdts = ptr;
}

//Class::Class() {
//	stdts = NULL;
//}

ofstream& operator<< (ofstream& ofs, const Class& cls) {
	ofs << cls.cId << " "
		<< cls.credit << " "
		<< cls.clsName << " "
		<< cls.teacher->getId() << " ";
	ListOfStdts* newptr = cls.stdts;
	while (newptr != NULL)
	{
		ofs << " GPA " << newptr->stdt->getId() << " "
			<< newptr->grade;
		newptr = newptr->nxstdt;
	}
	ofs << endl;
	return ofs;
}

ifstream& operator>> (ifstream& ifs, Class& cls) {
	int tchId;
	ifs >> cls.cId
		>> cls.credit
		>> cls.clsName;
	char temp[20];
	return ifs;
}

bool Class::addStudent(User* usr) {
	ListOfStdts* ptr = stdts;
	int id = usr->getId();
	while (ptr!=NULL)	// judging if this student already exist.
	{
		if (id == ptr->stdt->getId()) {
			cout << "This Student already Exist, Please try again.\n";
			return false;
		}
		ptr = ptr->nxstdt;
	}
	stdts = new ListOfStdts(usr, -1, stdts);
	return true;
}

bool Class::deleteStudent(User* usr) {
	ListOfStdts* ptr = stdts;
	ListOfStdts* tmpPtr = ptr;
	int id = usr->getId();
	int i = 0;
	while (ptr != NULL)	// judging if this student already exist.
	{
		if (id == ptr->stdt->getId()) {	// going through all students in the class
			if (ptr->grade == -1) {
				tmpPtr->nxstdt = ptr->nxstdt;
				if (i == 0)
				{
					stdts = stdts->nxstdt;
				}
				delete[] ptr;
				cout << "Successfully withdrawed from class " << clsName << endl;
				system("pause");
				return true;
			}
			else
			{
				cout << "The grade of this class have already been uploaded, you may not withdraw from this class.\n";
				return false;
			}
		}
		i++;
		tmpPtr = ptr;	// the last student in the class
		ptr = ptr->nxstdt;
	}
	return false;
}


double Class::getAveGPA() {
	ListOfStdts* ptr = stdts;
	double totalGPA = 0.0;
	int stdtNum = 0;
	while (ptr != NULL)
	{
		if (ptr->grade != -1)	// if there is no grade info, the grade of students will be set to the default -1
		{
			totalGPA += 1;
			stdtNum += 1;
		}
		ptr = ptr->nxstdt;
	}
	double aveGPA = totalGPA / stdtNum;
	return aveGPA;
}

double Class::getHighestGPA() {
	ListOfStdts* ptr = stdts;
	double maxGPA = -1.0;
	while (ptr != NULL)
	{
		if (ptr->grade > maxGPA)
		{
			maxGPA = ptr->grade;
		}
		ptr = ptr->nxstdt;
	}
	return maxGPA;
}


double Class::getLowestGPA() {
	ListOfStdts* ptr = stdts;
	double minGPA = 10.0;
	while (ptr != NULL)
	{
		if (ptr->grade < minGPA && ptr->grade != -1)
		{
			minGPA = ptr->grade;
		}
		ptr = ptr->nxstdt;
	}
	if (minGPA != 10.0)
	{
		return minGPA;
	}
	else
	{
		return -1.0;
	}

}

ListOfStdts* Class::getHighestStu() {
	double maxGPA = getHighestGPA();
	ListOfStdts* ptr = stdts;
	ListOfStdts* output = NULL;
	if (maxGPA == -1)
	{
		cout << "No grade have been uploaded, please upload the grade infomation first.\n";
		return NULL;
	}
	else
	{
		while (ptr != NULL)
		{
			if (maxGPA == ptr->grade)
			{
				output = new ListOfStdts(ptr->stdt, ptr->grade, output);
			}
			ptr = ptr->nxstdt;
		}
	}
	return output;
}

ListOfStdts* Class::getLowestStu() {
	double minGPA = getLowestGPA();
	ListOfStdts* ptr = stdts;
	ListOfStdts* output = NULL;
	if (minGPA == -1)
	{
		cout << "No grade have been uploaded, please upload the grade infomation first.\n";
		return NULL;
	}
	else
	{
		while (ptr != NULL)
		{
			if (minGPA == ptr->grade)
			{
				output = new ListOfStdts(ptr->stdt, ptr->grade, output);
			}
			ptr = ptr->nxstdt;
		}
	}
	return output;
}


ListOfStdts* Class::getFailedStu() {
	double maxGPA = getHighestGPA();
	ListOfStdts* ptr = stdts;
	ListOfStdts* output = NULL;
	if (maxGPA == -1)
	{
		cout << "No grade have been uploaded, please upload the grade infomation first.\n";
		return NULL;
	}
	else
	{
		while (ptr != NULL)
		{
			if (ptr->grade < 1.0)
			{
				output = new ListOfStdts(ptr->stdt, ptr->grade, output);
			}
			ptr = ptr->nxstdt;
		}
	}
	return output;
}

ListOfStdts* Class::getPassedStu() {
	double maxGPA = getHighestGPA();
	ListOfStdts* ptr = stdts;
	ListOfStdts* output = NULL;
	if (maxGPA == -1)
	{
		cout << "No grade have been uploaded, please upload the grade infomation first.\n";
		return NULL;
	}
	else
	{
		while (ptr != NULL)
		{
			if (ptr->grade > 1.0)
			{
				output = new ListOfStdts(ptr->stdt, ptr->grade, output);
			}
			ptr = ptr->nxstdt;
		}
	}
	return output;
}

int Class::failedStuNum() {
	ListOfStdts* failed = this->getFailedStu();
	ListOfStdts* ptr = failed;
	int output = 0;
	while (ptr != NULL) {
		output += 1;
		ptr = ptr->nxstdt;
	}
	delete[] failed;
	return output;
}

int Class::passedStuNum() {
	ListOfStdts* passed = this->getPassedStu();
	ListOfStdts* ptr = passed;
	int output = 0;
	while (ptr != NULL) {
		output += 1;
		ptr = ptr->nxstdt;
	}
	delete[] passed;
	return output;
}