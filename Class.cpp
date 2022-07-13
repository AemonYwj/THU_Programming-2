#include "Class.h"

Class::Class(int cid,User* const teacher1, char* clsn, ListOfStdts* ptr = NULL) {
	cId = cid;
	teacher = teacher1;
	strcpy(clsName, clsn);
	stdts = ptr;
}


ofstream& operator<< (ofstream& ofs, const Class& cls) {
	ofs << cls.cId << " "
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
		>> cls.clsName;
	char temp[20];
	return ifs;
}