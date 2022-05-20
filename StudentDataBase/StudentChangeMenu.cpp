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
			cout << "Вы уверены, что хотите сбросить изменения?\n";
			cout << "1. Да\n";
			cout << "2. Нет\n";
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
		"1. Фамилия",
		"2. Имя",
		"3. Отчество",
		"4. Дата рождения",
		"5. Год поступления",
		"6. Факультет",
		"7. Кфаедра",
		"8. Группа",
		"9. Номер зачётной книжки",
		"10. Пол",
		"11. Меню оценок.",
		"12. Сохранить.",
		"13. Не сохранять."
	};

	return changeMenu;
}
