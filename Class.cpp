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


