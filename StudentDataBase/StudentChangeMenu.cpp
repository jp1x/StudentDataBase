#include "StudentChangeMenu.h"

void StudentChangeMenu::UseMenu(const char* menuItems[], size_t length)
{
	int menuItemNumber;
	while (true)
	{
		cin.clear();
		system("cls");
		_dataBaseIO.PrintChangeMenuItems(menuItems, length);
		menuItemNumber = _dataBaseIO.InputMenuItemNumber();
		system("cls");

		switch (menuItemNumber)
		{
		case 1:
		{
			
		}
		case 2:
		{

		}
		case 3:
		{

		}
		case 4:
		{

		}
		case 5:
		{

		}
		case 6:
		{

		}
		case 7:
		{

		}
		case 8:
		{

		}
		case 9:
		{

		}
		case 10:
		{

		}
		case 11:
		{

		}
		case 12:
		{

		}
		case 13:
		{
			cout << "�� �������, ��� ������ �������� ���������?\n";
			cout << "1. ��\n";
			cout << "2. ���\n";
			switch (_dataBaseIO.InputMenuItemNumber())
			{
			case 1:
			{
				cin.clear();
				return;
			}
			case 2:
			{
				cin.clear();
				break;
			}
			}
			break;
		}

		}
	}
}

const char** StudentChangeMenu::GetMenuItems()
{
	static const char* changeMenu[] =
	{
		"1. �������",
		"2. ���",
		"3. ��������",
		"4. ���� ��������",
		"5. ��� �����������",
		"6. ���������",
		"7. �������",
		"8. ������",
		"9. ����� �������� ������",
		"10. ���",
		"11. ���� ������.",
		"12. ���������.",
		"13. �� ���������."
	};

	return changeMenu;
}
