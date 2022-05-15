#pragma once
#include <iostream>
#include "Student.h"
#include "StudentRepository.h"

class StudentService
{
private:
	StudentRepository _studentRepository;
	GradeRepository _gradeRepository;
	GradeService _gradeService;

public:
	void AddStudent(Student student);
	//void UpdateStudent(list<Student> students);
	void DeleteStudent(char* gradebookNum);
	list<Student> GetAllStudents();
	void Task54();
	list<Student> GetStudentsByGroupAndGender(char* group, char* gender, int sessionNum);
	list<Student> SortStudentsByAverageMark(list<Student> students, int size);
};
