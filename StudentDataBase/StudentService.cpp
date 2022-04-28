#include <iostream>
#include "StudentService.h"
#include "StudentRepository.h"
using namespace std;

void StudentService::AddStudent(Student student)
{
	bool exists = _studentRepository.StudentExistsByNum(student.GradebookNumber);

	if (!exists)
	{
		cout << "Студента с шифром " << student.GradebookNumber << " не существует.";
		return;
	}

	//TODO
	//провалидировать остальные поля

	_studentRepository.AddStudent(student);
}
