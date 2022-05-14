#include "GradeMenu.h"

void GradeMenu::UseMenu(const char* gradeMenuItems[], size_t length)
{
	_dataBaseIO.PrintGradeMenuItems(gradeMenuItems, length);

	while (true)
	{
		cin.clear();
		switch (_dataBaseIO.InputMenuItemNumber())
		{
		case 1:
		{
			Education session = _dataBaseIO.InputGrades();
			_gradeService.AddGrade(session);
			break;
		}
		case 2:
		{
			system("cls");
			break;
		}
		case 3:
		{

		}
		case 4:
		{

		}
		case 5:
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
		"3. ������� ������ ��������.",
		"4. ������� ���� ���������.",
		"5. �����."
	};

	return gradeMenu;
}
