#pragma once
#include "Student.h"
#include "DataBaseIO.h"
#include "GradeRepository.h"
#include "GradeService.h"
#include <fstream>
#include <list>
using namespace std;

class StudentRepository
{
private:
	fstream _dataBase;
	DataBaseIO _dataBaseIO;
	GradeRepository _gradeRepository;

public:
	bool DatabaseExists();
	void AddStudent(Student student);
	//void UpdateStudent(list<Student> students);
	void DeleteStudent(char* gradebookNum);
	list<Student> RemoveStudentFromList(
		list<Student> students, char* gradebookNum);
	list<Student> GetAllStudents();
	void ReWriteDataBase(list<Student> students);
	Student GetStudentByNum(char* gradebookNum);
	bool StudentExistsByNum(char* gradebookNum);
	list<Student> GetStudentsByGroupAndGenderForOneSession(
char* group, char* gender, int sessionNum);
	list<Student> GetStudentsByGroupAndGenderForAllSessions(
		char* group, char* gender);
};
