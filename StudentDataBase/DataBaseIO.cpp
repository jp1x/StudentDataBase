#include <iostream>
#include <string>
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
	char gradeBookNumber[9];
	char gender[9];

	cout << "�������: ";
	cin.getline(surname, 20);

	cout << "���: ";
	cin.getline(name, 20);

	cout << "��������: ";
	cin.getline(patronymic, 20);

	Date birthday;
	for (; 1;)
	{
		cout << "���� ��������(DD MM YYYY): ";
		cin >> dd >> mm >> yyyy;
		while (getchar() != '\n');
		Date _birthday(dd, mm, yyyy);

		if (_birthday.DateIsValid(_birthday))
			birthday = _birthday;
			break;
		cout << "�������� ����. ������� ��������.\n";
	}

	for (; 1;)
	{
		cout << "��� �����������: ";
		cin >> universityYear;
		while (getchar() != '\n');

		if (Student::UniversityYearIsvalid(universityYear, birthday))
			break;
		cout << "������� � ��������� ����� 16 ��� �� ����� ��������� � ���.\n";
	}

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
