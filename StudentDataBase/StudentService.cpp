#include <iostream>
#include "StudentService.h"
#include "StudentRepository.h"
using namespace std;

void StudentService::AddStudent(Student student)
{
	bool exists = _studentRepository.StudentExistsByNum(student.GradebookNumber);

	if (exists)
	{
		cout << "������� � ������ " << student.GradebookNumber << " ��� ����������.";
		return;
	}

	//TODO
	//��������������� ��������� ����

	_studentRepository.AddStudent(student);
}
