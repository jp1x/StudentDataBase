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
			(void)getchar();
			break;
		}
		case 2:
		{
			char* gradebookNumber = _dataBaseIO.InputGradebookNumber();
			if (!_studentService.StudentExistsByNum(gradebookNumber))
			{
				cout << "�������� � ������ " << gradebookNumber << " �� ����������.\n";
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}

			StudentChangeMenu studentChangeMenu(gradebookNumber);
			studentChangeMenu.UseMenu(studentChangeMenu.GetMenuItems(), 13);
			break;
		}
		case 3:
		{
			char* gradebookNumber = _dataBaseIO.InputGradebookNumber();
			_studentService.DeleteStudent(gradebookNumber);
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 4:
		{
			list<Student> students = _studentService.GetAllStudents();
			_dataBaseIO.OutputStudent(students);
			cout << "��� ����������� ������� ����� ������...\n";
			(void)getchar();
			break;
		}
		case 5:
		{
			gradeMenu.UseMenu(gradeMenu.GetMenuItems(), 4);
			break;
		}
		case 6:
		{
			cout << "1. ��������� ���������� �� ��� ������.\n";
			cout << "2. ��������� ���������� �� ���������� ������.\n";
			switch (_dataBaseIO.InputMenuItemNumber())
			{
			case 1:
			{
				system("cls");
				cin.clear();
				char* group = _dataBaseIO.InputGroup();
				char* gender = _dataBaseIO.InputGender();
				list<Student> studentsInGroup = _studentService.GetStudentsByGroupAndGenderForAllSessions(
					group, gender);

				_dataBaseIO.OutPutStudentsInGroupForAllSessions(studentsInGroup);
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}
			case 2:
			{
				system("cls");
				cin.clear();
				char* group = _dataBaseIO.InputGroup();
				char* gender = _dataBaseIO.InputGender();
				int sessionNum = _dataBaseIO.InputSessionNumber();
				list<Student> studentsInGroup = _studentService.GetStudentsByGroupAndGenderForOneSession(
					group, gender, sessionNum);

				_dataBaseIO.OutPutStudentsInGroupForOneSession(studentsInGroup);
				cout << "��� ����������� ������� ����� ������...\n";
				(void)getchar();
				break;
			}
			}
			break;
		}
		case 7:
		{
			cout << "����� �� ���������...\n";
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
		"6. ��������� ������� �54.",
		"7. ����� �� ���������."
	};

	return Menu;
}
