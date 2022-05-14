#include "StudentMenu.h"

void StudentMenu::UseMenu(const char* menuItems[], size_t length)
{
	int menuItemNumber;
	while (true)
	{
		cin.clear();
		system("cls");
		_dataBaseIO.PrintMenuItems(menuItems, length);
		menuItemNumber = _dataBaseIO.InputMenuItemNumber();
		system("cls");

		switch(menuItemNumber)
		{
		case 1:
		{
			Student student = _dataBaseIO.InputStudent();
			_studentService.AddStudent(student);
			cout << "��� ����������� ������� ����� ������...\n";
			getchar();
			break;
		}
		case 2:
		{
			char* gradebookNum = _dataBaseIO.InputGradebookNum();
			system("cls");
			break;
		}
		case 3:
		{
			char* gradebookNum = _dataBaseIO.InputGradebookNum();
			_studentService.DeleteStudent(gradebookNum);
			cout << "��� ����������� ������� ����� ������...\n";
			getchar();
			break;
		}
		case 4:
		{
			list<Student> students = _studentService.GetAllStudents();
			_dataBaseIO.OutputStudent(students);
			cout << "��� ����������� ������� ����� ������...\n";
			getchar();
			break;
		}
		case 5:
		{
			gradeMenu.UseMenu(gradeMenu.GetMenuItems(), 5);
			break;
		}
		case 6:
		{
			_studentService.ExitMenu();
			return;
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
		"6. ����� �� ���������."
	};

	return Menu;
}



//const char** StudentMenu::GetChangeMenuItems()
//{
//	static const char* Changemenu[] =
//	{
//		"1. �������",
//		"2. ���",
//		"3. ��������",
//		"4. ���� ��������",
//		"5. ��� �����������",
//		"6. ���������",
//		"7. �������",
//		"8. ������",
//		"9. ����� �������� ������",
//		"10. ���",
//		"11. �����"
//	};
//
//	return Changemenu;
//}
