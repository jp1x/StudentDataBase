#include "StudentService.h"
#include "StudentRepository.h"
using namespace std;

void StudentService::AddStudent(Student student)
{
	bool studentExists = _studentRepository.StudentExistsByNum(student.GradebookNumber);
	if (studentExists)
	{
		cout << "������� � ������ " << student.GradebookNumber << " ��� ����������.\n";
		return;
	}

	bool dateIsValid = Date::DateIsValid(student.Birthday);
	if (!dateIsValid)
	{
		cout << "������������ ���� ��������.\n";
		return;
	}

	bool uniYearIsValid = Student::UniversityYearIsValid(student.UniversityYear, student.Birthday);
	if (!uniYearIsValid)
	{
		cout << "������� � ��������� ����� 16 ��� �� ����� ��������� � ���.\n";
		cout << "��� ����� ��� ��� ����������� ��� �� ��������.\n";
		return;
	}

	bool surnameIsValid = student.InitialsAreValid(student.Surname);
	if (!surnameIsValid)
	{
		cout << "������� �������� ����� ����������� �������.\n";
		return;
	}

	bool nameIsValid = student.InitialsAreValid(student.Name);
	if (!nameIsValid)
	{
		cout << "��� �������� ����� ����������� �������.\n";
		return;
	}

	bool patronymicIsValid = student.InitialsAreValid(student.Patronymic);
	if (!patronymicIsValid)
	{
		cout << "�������� �������� ����� ����������� �������.\n";
		return;
	}

	bool facultyIsValid = student.CharFieldIsValid(student.Faculty, 9);
	if (!facultyIsValid)
	{
		cout << "��������� �������� ����� ����������� �������.\n";
		return;
	}

	bool departmentIsValid = student.CharFieldIsValid(student.Department, 7);
	if (!departmentIsValid)
	{
		cout << "������� �������� ����� ����������� �������.\n";
		return;
	}

	bool groupIsValid = student.CharFieldIsValid(student.Group, 11);
	if (!groupIsValid)
	{
		cout << "������ �������� ����� ����������� �������.\n";
		return;
	}

	bool gradebookIsValid = student.CharFieldIsValid(student.GradebookNumber, 8);
	if (!gradebookIsValid)
	{
		cout << "���� �������� ����� ����������� �������.\n";
		return;
	}

	bool genderIsValid = student.CharFieldIsValid(student.Gender, 8);
	if (!genderIsValid)
	{
		cout << "��� �������� ����� ����������� �������.\n";
		return;
	}

	_studentRepository.AddStudent(student);
}

void StudentService::DeleteStudent(char* gradebookNum)
{
	bool databaseExists = _studentRepository.DatabaseExists();
	if (!databaseExists)
	{
		cout << "���� ������ ��� �� �������.\n";
		return;
	}

	bool studentExists = _studentRepository.StudentExistsByNum(gradebookNum);
	if (!studentExists)
	{
		cout << "�������� � ������ " << gradebookNum << " �� ����������.\n";
		return;
	}

	_studentRepository.DeleteStudent(gradebookNum);
}

//void StudentService::UpdateStudent(list<Student> students)
//{
//	_studentRepository.UpdateStudent(students);
//}

list<Student> StudentService::GetAllStudents()
{
	return _studentRepository.GetAllStudents();
}
