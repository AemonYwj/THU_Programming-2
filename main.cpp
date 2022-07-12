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
using namespace std;

int showMenu(Menu* &mn,const int ath,int level) {	// a universal template for showing menus by checking authority and the level of menus needed.
	int choice;
	if (ath == 0)
		mn = new StudentMenu;
	else if (ath == 1)
		mn = new TeacherMenu;
	else
		cout << "WRONG Authority! Please check!\n";
	switch (level)
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
	default:
		break;
	}

}

int main() {
	Interface itf;
	int ath = 0;	// authority of the login user
	User* usr;
	ath = itf.login(usr);
	Menu* menu;
	int level = 0;
	int chc;	// the choice of the user
	chc = showMenu(menu, ath, level);
	switch (chc)
	{
		int chc1;
	case 0:	// Exit System
		cout << "See you next time!\n";
		exit(0);
		break;
	default:
		chc1 = showMenu(menu, ath, chc);
		break;
	}

	return 0;
}