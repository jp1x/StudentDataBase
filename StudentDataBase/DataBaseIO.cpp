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
	cin.getline(gradeBookNumber, 8);

	cout << "���: ";
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

void DataBaseIO::OutputStudent(/*list<Student> _students*/Student student)
{	
	//list<Student>::iterator it;
	//for (it = _students.begin(); it != _students.end(); ++it)
	//{
	cout << "\n";
	cout << '|' << setfill(' ') << setw(19) << left << student.Surname <<
		'|' << setfill(' ') << setw(19) << left << student.Name <<
		'|' << setfill(' ') << setw(19) << left << student.Patronymic <<
		'|' << setfill(' ') << setw(2) << right << student.Birthday.day <<
		"." << setfill(' ') << setw(2) << right << student.Birthday.month <<
		"." << student.Birthday.year <<
		'|' << setfill(' ') << setw(4) << left << student.UniversityYear <<
		'|' << setfill(' ') << setw(8) << left << student.Faculty <<
		'|' << setfill(' ') << setw(6) << left << student.Department <<
		'|' << setfill(' ') << setw(10) << left << student.Group <<
		'|' << setfill(' ') << setw(7) << left << student.GradebookNumber <<
		'|' << setfill(' ') << setw(7) << left << student.Gender << '|' << "\n\n";
	cout << setfill('=') << setw(120) << "=" << "\n";

	//}
}
