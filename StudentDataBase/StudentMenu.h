#pragma once
#include <array>
#include "Menu.h"
#include "GradeMenu.h"
#include "StudentChangeMenu.h"

class StudentMenu : public Menu
{
public:
	GradeMenu gradeMenu;
	void UseMenu(const char* menuItems[], size_t length);
	const char** GetMenuItems();
};
