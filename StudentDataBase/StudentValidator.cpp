#include "StudentValidator.h"

bool StudentValidator::InitialsAreValid(char* value)
{
	for (short i = 0; i < 20; i++)
	{
		for (short j = 0; j < 37; j++)
		{
			if (value[i] == *incorrectSimbolsAndNums[j])
				return false;
		}
	}

	return true;
}

bool StudentValidator::CharFieldIsValid(char* value, short length)
{
	for (short i = 0; i < length; i++)
	{
		for (short j = 0; j < 27; j++)
		{
			if (value[i] == *incorrectSimbols[j])
				return false;
		}
	}

	return true;
}

bool StudentValidator::StudentExistsByNum(char* gradebookNum)
{
	if (_studentRepository.StudentExistsByNum(gradebookNum))
	{
		cout << "������� � ������ " << gradebookNum << " ��� ����������.\n";
		return true;
	}
	return false;
}

bool StudentValidator::DateIsValid(Date birthday)
{
	if (!Date::DateIsValid(birthday))
	{
		cout << "������������ ���� ��������. �������: 1930-�������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::UnivesityYearIsValid(short universityYear, Date birthday)
{
	if (!Student::UniversityYearIsValid(universityYear, birthday))
	{
		cout << "������� � ��������� ����� 16 ��� �� ����� ��������� � ���.\n";
		cout << "��� ����� ��� ��� ����������� ��� �� ��������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::SurnameIsValid(char* surname)
{
	if (!InitialsAreValid(surname))
	{
		cout << "������� �������� ����� ����������� �������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::NameIsValid(char* name)
{
	if (!InitialsAreValid(name))
	{
		cout << "��� �������� ����� ����������� �������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::PatronymicIsValid(char* patronymic)
{
	if (!InitialsAreValid(patronymic))
	{
		cout << "�������� �������� ����� ����������� �������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::FacultyIsValid(char* faculty)
{
	if (!CharFieldIsValid(faculty, 9))
	{
		cout << "��������� �������� ����� ����������� �������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::DeartmentIsValid(char* department)
{
	if (!CharFieldIsValid(department, 7))
	{
		cout << "������� �������� ����� ����������� �������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::GroupIsValid(char* group)
{
	if (!CharFieldIsValid(group, 11))
	{
		cout << "������ �������� ����� ����������� �������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::GradebookNumberIsValid(char* gradebookNum)
{
	if (!CharFieldIsValid(gradebookNum, 8))
	{
		cout << "���� �������� ����� ����������� �������.\n";
		return false;
	}
	return true;
}

bool StudentValidator::GenderIsValid(char* gender)
{
	if (!CharFieldIsValid(gender, 8))
	{
		cout << "��� �������� ����� ����������� �������.\n";
		return false;
	}

	if (!strcmp("�������", gender) || !strcmp("�������", gender) ||
		!strcmp("�������", gender) || !strcmp("�������", gender))
		return true;
	else
	{
		cout << "��� �������� ����� �������.\n";
		return false;
	}
}
