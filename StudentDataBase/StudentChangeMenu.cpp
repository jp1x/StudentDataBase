#include "StudentChangeMenu.h"

void StudentChangeMenu::UseMenu(const char* menuItems[], size_t length)
{
	int menuItemNumber;
	while (true)
	{
		cin.clear();
		system("cls");
		_dataBaseIO.PrintChangeMenuItems(menuItems, length, *_student);
		menuItemNumber = _dataBaseIO.InputMenuItemNumber();
		system("cls");

		switch (menuItemNumber)
		{
		case 1:
		{
			char* surname = _dataBaseIO.InputSurname();
			if (!_studentValidator.SurnameIsValid(surname))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Surname, surname);
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 2:
		{
			char* name = _dataBaseIO.InputName();
			if (!_studentValidator.NameIsValid(name))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Name, name);
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 3:
		{
			char* patronymic = _dataBaseIO.InputPatronymic();
			if (!_studentValidator.PatronymicIsValid(patronymic))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Patronymic, patronymic);
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 4:
		{
			Date birthday = _dataBaseIO.InputDate();
			if (!_studentValidator.DateIsValid(birthday))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			_student->Birthday = birthday;
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 5:
		{
			short universityYear = _dataBaseIO.InputUniversityYear();
			if (!_studentValidator.UnivesityYearIsValid(universityYear, _student->Birthday))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			_student->UniversityYear = universityYear;
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 6:
		{
			char* faculty = _dataBaseIO.InputFaculty();
			if (!_studentValidator.FacultyIsValid(faculty))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Faculty, faculty);
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 7:
		{
			char* department = _dataBaseIO.InputDepartment();
			if (!_studentValidator.DeartmentIsValid(department))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Department, department);
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 8:
		{
			char* group = _dataBaseIO.InputGroup();
			if (!_studentValidator.GroupIsValid(group))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Group, group);
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 9:
		{
			char* gradebookNumber = _dataBaseIO.InputGradebookNumber();
			if (!_studentValidator.GradebookNumberIsValid(gradebookNumber))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->GradebookNumber, gradebookNumber);
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 10:
		{
			char* gender = _dataBaseIO.InputGender();
			if (!_studentValidator.GenderIsValid(gender))
			{
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Gender, gender);
			cout << "Поле студента успешно изменено.\n";
			cout << "Для продолжения нажмите любую кнопку...\n";
			(void)getchar();
			break;
		}
		case 11:
		{

		}
		case 12:
		{
			cout << "Вы уверены, что хотите сохранить изменения?\n";
			cout << "1. Да\n";
			cout << "2. Нет\n";
			switch (_dataBaseIO.InputMenuItemNumber())
			{
			case 1:
			{
				_studentService.UpdateStudent(*_student, _sourceGradebookNumber);
				cout << "Для продолжения нажмите любую кнопку...\n";
				(void)getchar();
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
		"7. Кафедра",
		"8. Группа",
		"9. Номер зачётной книжки",
		"10. Пол",
		"11. Меню оценок.",
		"12. Сохранить.",
		"13. Не сохранять."
	};

	return changeMenu;
}
