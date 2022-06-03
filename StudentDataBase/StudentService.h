#pragma once
#include <iostream>
#include "Student.h"
#include "StudentValidator.h"
#include "StudentRepository.h"

class StudentService
{
private:
	StudentRepository _studentRepository;
	GradeRepository _gradeRepository;
	StudentValidator _studentValidator;
	GradeService _gradeService;

public:
	bool DatabaseExists(const char* databaseName);
	void AddStudent(Student student);
	void UpdateStudent(Student student, char* gradebookNum);
	void DeleteStudent(char* gradebookNum);
	bool StudentExistsByNum(char* gradebookNum);
	Student GetStudentByNum(char* gradebookNum);
	list<Student> GetAllStudents();
	list<Student> GetStudentsByGroupAndGenderForOneSession(
		char* group, char* gender, int sessionNum);
	list<Student> GetStudentsByGroupAndGenderForAllSessions(
		char* group, char* gender);
};
