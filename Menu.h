#pragma once

class Menu
{
public:
	virtual int showMenu() = 0;
	virtual int show1stMenu() { return 0; };
	virtual int show2ndMenu() { return 0; };
	virtual int show3thMenu() { return 0; };
	virtual int show4thMenu() { return 0; };

};

