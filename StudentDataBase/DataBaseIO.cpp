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
	char gradeBookNumber[9];

	cout << "�������: ";
	cin >> surname;

	cout << "���: ";
	cin >> name;

	cout << "��������: ";
	cin >> patronymic;

	cout << "����� �������� ������: ";
	cin >> gradeBookNumber;

	Student person =
	{
		surname,
		name,
		patronymic,
		gradeBookNumber
	};
	
	return person;
}
