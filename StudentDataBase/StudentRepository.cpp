#include "StudentRepository.h"

bool StudentRepository::StudentExistsByNum(char* gradeBookNum)
{
	return true;
}

void StudentRepository::AddStudent(Student student)
{
	_dataBase.open("Students.txt", ios::binary | ios::out | ios::app);
	_dataBase.write((char*)&student, sizeof(student));
	_dataBase.close();
}