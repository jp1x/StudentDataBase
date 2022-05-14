#pragma once
#include <array>
#include "Menu.h"

class GradeMenu : public Menu
{
public:
	void UseMenu(const char* gradeMenuItems[], size_t length);
	const char** GetMenuItems();
};
