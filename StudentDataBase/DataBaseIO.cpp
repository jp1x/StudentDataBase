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

	cout << "�������: ";
	cin.getline(surname, 20);

	cout << "���: ";
	cin.getline(name, 20);

	cout << "��������: ";
	cin.getline(patronymic, 20);

	cout << "��� �����������: ";
	cin >> universityYear;
	while (getchar() != '\n');

	cout << "���������: ";
	cin.getline(faculty, 9);

	cout << "�������: ";
	cin.getline(department, 7);

	cout << "������: ";
	cin.getline(group, 11);

	cout << "����� �������� ������: ";
	cin.getline(gradeBookNumber, 9);

	cout << "���: ";
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
