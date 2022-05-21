#pragma once
#include <array>
#include "Menu.h"
#include "StudentService.h"
#include "StudentValidator.h"

class StudentChangeMenu : public Menu
{
private:
	Student* _student;
	char _sourceGradebookNumber[8];
	StudentValidator _studentValidator;

public:
	void UseMenu(const char* menuItems[], size_t length);
	const char** GetMenuItems();

	StudentChangeMenu(char* gradebookNum)
	{
		strcpy_s(_sourceGradebookNumber, gradebookNum);
		_student = new Student(_studentService.GetStudentByNum(gradebookNum));
	}

	~StudentChangeMenu()
	{
		delete _student;
	}
};
