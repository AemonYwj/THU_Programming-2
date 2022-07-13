#include "Class.h"
#include "Interface.h"
#include "Student.h"
#include "StudentInterface.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "StudentMenu.h"
#include "TeacherMenu.h"
#include "ClassInterface.h"
using namespace std;

int showMenu(Menu* &mn,const int ath,int choice) {	// a universal template for showing menus by checking authority and the choice of menus needed.
	if (ath == 0)
		mn = new StudentMenu;
	else if (ath == 1)
		mn = new TeacherMenu;
	else
		cout << "WRONG Authority! Please check!\n";
	switch (choice)
	{
	case 0:
		return mn->showMenu();
		break;
	case 1:
		return mn->show1stMenu();
		break;
	case 2:
		return mn->show2ndMenu();
		break;
	case 3:
		return mn->show3thMenu();
	default:
		break;
	}

}

void WrapUpMenu(Interface& itf, ClassInterface& clsItf, User* usr, int const ath) {
	bool flag = true;	
	bool flag1 = true;	
	int chc, chc1;	// to store the choice user made in secondary menu
	Menu* mn;
	while (flag)
	{
		chc = showMenu(mn, ath, 0);	
		switch (ath)	// take different measures with different users
		{
		case 0:		// students
			while (flag1)
			{
				switch (chc)
				{
				case 1:	// choose show grade
					chc1 = showMenu(mn, ath, chc);
					switch (chc1)
					{
					case 1:
						clsItf.showAllGPAInfo(usr);
						break;
					case 2:
						clsItf.showOneSpecGPAInfo(usr);
						break;
					case 3:
						clsItf.calGPA(usr);
						break;
					default:
						flag1 = false;
						break;
					}
					break;
				case 2:	// choose Register class
					clsItf.registerClass(usr);
					break;
				case 3:	// withdraw from one class
					clsItf.withdrawClass(usr);
					break
				default:	// Exit System
					cout << "See you next time!\n";
					exit(0);
					break;
				}
			}
			break;
		default:
			

			break;
		}
	}
}


int main() {
	Interface itf;
	ClassInterface clsItf(itf);
	int ath = 0;	// authority of the login user
	User* usr;	// current User
	ath = itf.login(usr);
	Menu* menu;
	int level = 0;
	int chc;	// the choice of the user
	chc = showMenu(menu, ath, level);	// show the first level menu
	int chc1;
	switch (chc)
	{
	case 0:	// Exit System
		cout << "See you next time!\n";
		exit(0);
		break;
	default:
		chc1 = showMenu(menu, ath, chc);	// show the secondary menu
		break;
	}









	return 0;
}