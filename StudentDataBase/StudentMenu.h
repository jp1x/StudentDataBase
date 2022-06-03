#pragma once
#include <array>
#include "Encryptor.h"
#include "Menu.h"
#include "GradeMenu.h"
#include "StudentChangeMenu.h"

class StudentMenu : public Menu
{
private:
	Encryptor _encryptor;

public:
	GradeMenu gradeMenu;
	void UseMenu(const char* menuItems[], size_t length);
	const char** GetMenuItems();
};
