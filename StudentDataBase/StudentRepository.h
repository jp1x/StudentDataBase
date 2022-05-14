#pragma once
#include "Student.h"
#include "DataBaseIO.h"
#include <fstream>
#include <list>
using namespace std;

class StudentRepository
{
private:
	fstream _dataBase;
	DataBaseIO _dataBaseIO;

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
};
