#pragma once
#include <array>
#include "StudentService.h"
#include "Menu.h"

class StudentChangeMenu : public Menu
{
private:
	Student* _student;
	char* _SourceGradebookNumber;

public:
	void UseMenu(const char* menuItems[], size_t length);
	const char** GetMenuItems();

	StudentChangeMenu(char* gradebookNum)
	{
		_SourceGradebookNumber = gradebookNum;
		_student = new Student(_studentService.GetStudentByNum(gradebookNum));
	}

	~StudentChangeMenu()
	{
		delete _student;
	}
};
