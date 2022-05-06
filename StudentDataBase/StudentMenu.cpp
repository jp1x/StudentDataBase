#include "StudentMenu.h"

void StudentMenu::UseMenu(const char* menuItems[], size_t length)
{
	_dataBaseIO.PrintMenuItems(menuItems, length);
	
	while (true)
	{
		cin.clear();
		switch(_dataBaseIO.InputMenuItemNumber())
		{
		case 1:
		{
			Student student = _dataBaseIO.InputStudent();
			_studentService.AddStudent(student);
			break;
		}
		case 3:
		{
			list<Student> students = _studentService.GetAllStudents();
			_studentService.DeleteStudent(students);
			break;
		}
		case 4:
		{
			list<Student> students = _studentService.GetAllStudents();
			_dataBaseIO.OutputStudent(students);
			break;
		}
		}
	}
}

const char** StudentMenu::GetMenuItems()
{
	static const char* Menu[] =
	{
		"1. �������� ������ � ��������.",
		"2. �������� ������ � ��������.",
		"3. ������� ������ � ��������.",
		"4. ������� ���� ���������.",
		"5. ���� ������.",
		"6. �����."
	};

	return Menu;
}
