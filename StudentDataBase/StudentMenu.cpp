#include "StudentMenu.h"

void StudentMenu::UseMenu(const char* menuItems[], size_t length)
{
	_dataBaseIO.PrintMenuItems(menuItems, length);
	
	short program = 1;
	while (program)
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
		case 2:
		{
			system("cls");
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
		case 6:
		{
			program = 0;
			_studentService.ExitMenu();
			break;
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
		"6. Выход."
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
