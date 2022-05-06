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

	bool dateIsvalid = Date::DateIsValid(student.Birthday);

	if (!dateIsvalid)
	{
		cout << "������������ ���� ��������.\n";
		return;
	}

	bool uniYearIsvalid = Student::UniversityYearIsvalid(student.UniversityYear, student.Birthday);

	if (!uniYearIsvalid)
	{
		cout << "������� � ��������� ����� 16 ��� �� ����� ��������� � ���.\n";
		return;
	}


	//TODO
	//��������������� ��������� ����

	_studentRepository.AddStudent(student);
}

void StudentService::DeleteStudent(list<Student> students)
{
	_studentRepository.DeleteStudent(students);
}

char* StudentService::EnterGradeBookNum()
{
	char _gradeBookNum[8];
	cout << "������� ���� ��������, �������� ������ �������: ";
	cin.getline(_gradeBookNum, 8);
	return _gradeBookNum;
}

list<Student> StudentService::GetAllStudents()
{
	return _studentRepository.GetAllStudents();
}
