#include "DataBaseIO.h"
#define BufClean cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall()
using namespace std;

Student DataBaseIO::InputStudent()
{
	char surname[20];
	char name[20];
	char patronymic[20];
	unsigned short dd, mm, yyyy;
	short universityYear;
	char faculty[9];
	char department[7];
	char group[11];
	char gradebookNumber[8];
	char gender[8];

	cout << "Фамилия: ";
	cin.getline(surname, 20);
	BufClean;

	cout << "Имя: ";
	cin.getline(name, 20);
	BufClean;

	cout << "Отчество: ";
	cin.getline(patronymic, 20);
	BufClean;

	cout << "Дата рождения(DD MM YYYY): ";
	cin >> dd >> mm >> yyyy;
	Date birthday(dd, mm, yyyy);
	BufClean;

	cout << "Год поступления: ";
	cin >> universityYear;
	BufClean;

	cout << "Факультет: ";
	cin.getline(faculty, 9);
	BufClean;

	cout << "Кафедра: ";
	cin.getline(department, 7);
	BufClean;

	cout << "Группа: ";
	cin.getline(group, 11);
	BufClean;

	cout << "Номер зачетной книжки: ";
	cin.getline(gradebookNumber, 8);
	BufClean;

	cout << "Пол: ";
	cin.getline(gender, 8);
	BufClean;

	Student person
	(
		surname,
		name,
		patronymic,
		birthday,
		universityYear,
		faculty,
		department,
		group,
		gradebookNumber,
		gender
	);
	
	return person;
}

char* DataBaseIO::InputGradebookNum()
{
	char gradebookNumber[8];
	cout << "Введите номер зачетной книжки студента: ";
	cin.getline(gradebookNumber, 8);
	BufClean;

	return gradebookNumber;
}

Education DataBaseIO::InputGrades()
{
	char gradebookNumber[8];
	short sessionNumber;
	short subjectsAmount;
	
	cout << "Номер зачетной книжки: ";
	cin.getline(gradebookNumber, 8);
	BufClean;

	cout << "Номер сессии: ";
	cin >> sessionNumber;
	BufClean;

	cout << "Количество дисциплин: ";
	cin >> subjectsAmount;
	BufClean;

	Subject* Subjects = new Subject[subjectsAmount];

	for (short i = 0; i < subjectsAmount; i++)
	{
		cout << "Дисциплина " << i + 1 << ": ";
		cin.getline(Subjects->title, 30);
		BufClean;

		cout << "Оценка: ";
		cin >> Subjects->mark;
		BufClean;
	}

	Education session
	(
		gradebookNumber,
		sessionNumber,
		subjectsAmount,
		Subjects
	);

	delete[] Subjects;

	return session;
}

void DataBaseIO::OutputStudent(list<Student> students)
{	
	cout << setfill('=') << setw(120) << "=" << "\n";
	for (const Student& student : students)
	{
		cout << '|' << setfill(' ') << setw(19) << left << student.Surname <<
			'|' << setfill(' ') << setw(19) << left << student.Name <<
			'|' << setfill(' ') << setw(19) << left << student.Patronymic <<
			'|' << setfill('0') << setw(2) << right << student.Birthday.day <<
			"." << setfill('0') << setw(2) << right << student.Birthday.month <<
			"." << student.Birthday.year <<
			'|' << setfill(' ') << setw(4) << left << student.UniversityYear <<
			'|' << setfill(' ') << setw(8) << left << student.Faculty <<
			'|' << setfill(' ') << setw(6) << left << student.Department <<
			'|' << setfill(' ') << setw(10) << left << student.Group <<
			'|' << setfill(' ') << setw(7) << left << student.GradebookNumber <<
			'|' << setfill(' ') << setw(7) << left << student.Gender << '|' << "\n";
		cout << setfill('=') << setw(120) << "=" << "\n";
	}
}

void DataBaseIO::PrintMenuItems(const char* menuItems[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << menuItems[i] << "\n";
	}
}

void DataBaseIO::PrintGradeMenuItems(const char* gradeMenuItems[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << gradeMenuItems[i] << "\n";
	}
}

int DataBaseIO::InputMenuItemNumber()
{
	int number;
	cout << "Введите номер пункта меню: ";
	cin >> number;
	while (getchar() != '\n');
	return number;
}
