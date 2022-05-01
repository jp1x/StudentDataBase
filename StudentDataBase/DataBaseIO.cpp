#include <iostream>
#include <string>
#include "DataBaseIO.h"
#include "Student.h"
using namespace std;

Student DataBaseIO::InputStudent()
{
	char name[20];
	char surname[20];
	char patronymic[20];
	short universityYear;
	char faculty[9];
	char department[7];
	char group[11];
	char gender[9];
	char gradeBookNumber[9];

	cout << "Фамилия: ";
	cin.getline(surname, 20);

	cout << "Имя: ";
	cin.getline(name, 20);

	cout << "Отчество: ";
	cin.getline(patronymic, 20);

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
	cin.getline(gradeBookNumber, 9);

	cout << "Пол: ";
	cin.getline(gender, 9);

	Student person =
	{
		surname,
		name,
		patronymic,
		universityYear,
		faculty,
		department,
		group,
		gradeBookNumber,
		gender
	};
	
	return person;
}
