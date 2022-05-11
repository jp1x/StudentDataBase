#pragma once
#include <iostream>
#include "Student.h"
#include "StudentRepository.h"

class StudentService
{
private:
	StudentRepository _studentRepository;

public:
	void AddStudent(Student student);
	//void UpdateStudent(list<Student> students);
	void DeleteStudent(list<Student> students);
	list<Student> GetAllStudents();
	int ExitMenu();
};
