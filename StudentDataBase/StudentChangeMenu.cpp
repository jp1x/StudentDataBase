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
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Surname, surname);
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 2:
		{
			char* name = _dataBaseIO.InputName();
			if (!_studentValidator.NameIsValid(name))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Name, name);
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 3:
		{
			char* patronymic = _dataBaseIO.InputPatronymic();
			if (!_studentValidator.PatronymicIsValid(patronymic))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Patronymic, patronymic);
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 4:
		{
			Date birthday = _dataBaseIO.InputDate();
			if (!_studentValidator.DateIsValid(birthday))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			_student->Birthday = birthday;
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 5:
		{
			short universityYear = _dataBaseIO.InputUniversityYear();
			if (!_studentValidator.UnivesityYearIsValid(universityYear, _student->Birthday))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			_student->UniversityYear = universityYear;
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 6:
		{
			char* faculty = _dataBaseIO.InputFaculty();
			if (!_studentValidator.FacultyIsValid(faculty))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Faculty, faculty);
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 7:
		{
			char* department = _dataBaseIO.InputDepartment();
			if (!_studentValidator.DeartmentIsValid(department))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Department, department);
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 8:
		{
			char* group = _dataBaseIO.InputGroup();
			if (!_studentValidator.GroupIsValid(group))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Group, group);
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 9:
		{
			char* gradebookNumber = _dataBaseIO.InputGradebookNumber();
			if (!_studentValidator.GradebookNumberIsValid(gradebookNumber))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->GradebookNumber, gradebookNumber);
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 10:
		{
			char* gender = _dataBaseIO.InputGender();
			if (!_studentValidator.GenderIsValid(gender))
			{
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			strcpy_s(_student->Gender, gender);
			cout << "���� �������� ������� ��������.\n";
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 11:
		{

		}
		case 12:
		{
			cout << "�� �������, ��� ������ ��������� ���������?\n";
			cout << "1. ��\n";
			cout << "2. ���\n";
			switch (_dataBaseIO.InputMenuItemNumber())
			{
			case 1:
			{
				_studentService.UpdateStudent(*_student, _sourceGradebookNumber);
				cout << "��� ����������� ������� ����� ������...\n";
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
