#pragma once
#include <array>
#include "Menu.h"

class StudentMenu : public Menu
{
public:
	void UseMenu(const char* menuItems[], size_t length);
	const char** GetMenuItems();
	//const char** GetChangeMenuItems();
};
