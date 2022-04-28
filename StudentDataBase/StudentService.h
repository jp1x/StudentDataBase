#pragma once
#include "Student.h"
#include "StudentRepository.h"

class StudentService
{
private:
	StudentRepository _studentRepository;

public:
	void AddStudent(Student student);
};
