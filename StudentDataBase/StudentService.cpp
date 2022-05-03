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


	//TODO
	//��������������� ��������� ����

	_studentRepository.AddStudent(student);
}

void StudentService::GetAllStudents()
{
	_studentRepository.GetAllStudents();
}
