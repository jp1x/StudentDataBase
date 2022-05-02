#include <iostream>
#include "StudentService.h"
#include "StudentRepository.h"
using namespace std;

void StudentService::AddStudent(Student student)
{
	bool studentExists = _studentRepository.StudentExistsByNum(student.GradebookNumber);

	if (studentExists)
	{
		cout << "Студент с шифром " << student.GradebookNumber << " уже существует.";
		return;
	}


	//TODO
	//провалидировать остальные поля

	_studentRepository.AddStudent(student);
}
