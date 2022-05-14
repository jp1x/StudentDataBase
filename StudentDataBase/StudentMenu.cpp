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
			cout << "Для продолжения нажмите любую кнопку...\n";
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
			cout << "Для продолжения нажмите любую кнопку...\n";
			getchar();
			break;
		}
		case 4:
		{
			list<Student> students = _studentService.GetAllStudents();
			_dataBaseIO.OutputStudent(students);
			cout << "Для продолжения нажмите любую кнопку...\n";
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
		"1. Добавить запись о студенте.",
		"2. Изменить запись о студенте.",
		"3. Удалить запись о студенте.",
		"4. Вывести всех студентов.",
		"5. Меню оценок.",
		"6. Выход из программы."
	};

	return Menu;
}



//const char** StudentMenu::GetChangeMenuItems()
//{
//	static const char* Changemenu[] =
//	{
//		"1. Фамилия",
//		"2. Имя",
//		"3. Отчество",
//		"4. Дата рождения",
//		"5. Год поступления",
//		"6. Факультет",
//		"7. Кфаедра",
//		"8. Группа",
//		"9. Номер зачётной книжки",
//		"10. Пол",
//		"11. Назад"
//	};
//
//	return Changemenu;
//}
