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
		cout << "Студент с шифром " << gradebookNum << " уже существует.\n";
		return true;
	}
	return false;
}

bool StudentValidator::DateIsValid(Date birthday)
{
	if (!Date::DateIsValid(birthday))
	{
		cout << "Некорректная дата рождения. Границы: 1930-текущая.\n";
		return false;
	}
	return true;
}

bool StudentValidator::UnivesityYearIsValid(short universityYear, Date birthday)
{
	if (!Student::UniversityYearIsValid(universityYear, birthday))
	{
		cout << "Студент с возрастом менее 16 лет не может поступить в ВУЗ.\n";
		cout << "Или такой год для поступления ещё не наступил.\n";
		return false;
	}
	return true;
}

bool StudentValidator::SurnameIsValid(char* surname)
{
	if (!InitialsAreValid(surname))
	{
		cout << "Фамилия студента имеет запрещенные символы.\n";
		return false;
	}
	return true;
}

bool StudentValidator::NameIsValid(char* name)
{
	if (!InitialsAreValid(name))
	{
		cout << "Имя студента имеет запрещенные символы.\n";
		return false;
	}
	return true;
}

bool StudentValidator::PatronymicIsValid(char* patronymic)
{
	if (!InitialsAreValid(patronymic))
	{
		cout << "Отчество студента имеет запрещенные символы.\n";
		return false;
	}
	return true;
}

bool StudentValidator::FacultyIsValid(char* faculty)
{
	if (!CharFieldIsValid(faculty, 9))
	{
		cout << "Факультет студента имеет запрещенные символы.\n";
		return false;
	}
	return true;
}

bool StudentValidator::DeartmentIsValid(char* department)
{
	if (!CharFieldIsValid(department, 7))
	{
		cout << "Кафедра студента имеет запрещенные символы.\n";
		return false;
	}
	return true;
}

bool StudentValidator::GroupIsValid(char* group)
{
	if (!CharFieldIsValid(group, 11))
	{
		cout << "Группа студента имеет запрещенные символы.\n";
		return false;
	}
	return true;
}

bool StudentValidator::GradebookNumberIsValid(char* gradebookNum)
{
	if (!CharFieldIsValid(gradebookNum, 8))
	{
		cout << "Шифр студента имеет запрещенные символы.\n";
		return false;
	}
	return true;
}

bool StudentValidator::GenderIsValid(char* gender)
{
	if (!CharFieldIsValid(gender, 8))
	{
		cout << "Пол студента имеет запрещенные символы.\n";
		return false;
	}

	if (!strcmp("мужской", gender) || !strcmp("Мужской", gender) ||
		!strcmp("женский", gender) || !strcmp("Женский", gender))
		return true;
	else
	{
		cout << "Пол студента введён неверно.\n";
		return false;
	}
}
