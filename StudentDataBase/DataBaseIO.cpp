#include "DataBaseIO.h"
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
	char gradeBookNumber[8];
	char gender[8];

	cout << "Фамилия: ";
	cin.getline(surname, 20);

	cout << "Имя: ";
	cin.getline(name, 20);

	cout << "Отчество: ";
	cin.getline(patronymic, 20);

	cout << "Дата рождения(DD MM YYYY): ";
	cin >> dd >> mm >> yyyy;
	while (getchar() != '\n');
	Date birthday(dd, mm, yyyy);

	cout << "Год поступления: ";
	cin >> universityYear;
	while (getchar() != '\n');

	cout << "Факультет: ";
	cin.getline(faculty, 9);

	cout << "Кафедра: ";
	cin.getline(department, 7);

	cout << "Группа: ";
	cin.getline(group, 11);

	cout << "Норер зачетной книжки: ";
	cin.getline(gradeBookNumber, 8);

	cout << "Пол: ";
	cin.getline(gender, 8);


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
		gradeBookNumber,
		gender
	);
	
	return person;
}

void DataBaseIO::OutputStudent(list<Student> students)
{	
	cout << setfill('=') << setw(120) << "=" << "\n\n";
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
			'|' << setfill(' ') << setw(7) << left << student.Gender << '|' << "\n\n";
		cout << setfill('=') << setw(120) << "=" << "\n\n";
	}
}

void DataBaseIO::PrintMenuItems(const char* menuItems[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << menuItems[i] << "\n";
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
