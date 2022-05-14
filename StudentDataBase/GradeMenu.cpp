#include "GradeMenu.h"

void GradeMenu::UseMenu(const char* gradeMenuItems[], size_t length)
{
	int menuItemNumber;
	while (true)
	{
		cin.clear();
		system("cls");
		_dataBaseIO.PrintGradeMenuItems(gradeMenuItems, length);
		menuItemNumber = _dataBaseIO.InputMenuItemNumber();
		system("cls");

		switch(menuItemNumber)
		{
		case 1:
		{
			Education session = _dataBaseIO.InputGrades();
			_gradeService.AddGrade(session);
			cout << "��� ����������� ������� ����� ������...\n";
			getchar();
			break;
		}
		case 2:
		{
			system("cls");
			break;
		}
		case 3:
		{
			list<Education> grades = _gradeService.GetAllGrades();
			_dataBaseIO.OutputGrade(grades);
			cout << "��� ����������� ������� ����� ������...\n";
			getchar();
			break;
		}
		case 4:
		{
			return;
		}
		}
	}
}

const char** GradeMenu::GetMenuItems()
{
	static const char* gradeMenu[] =
	{
		"1. �������� ������ ��������.",
		"2. �������� ������ ��������.",
		"3. ������� ������ ���� ���������.",
		"4. �����."
	};

	return gradeMenu;
}
