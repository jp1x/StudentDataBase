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
	bool DatabaseExists();

public:
	void AddStudent(Student student);
	void DeleteStudent(list<Student> students);
	list<Student> GetNewList(list<Student> students, char* gradeBookNum);
	list<Student> GetAllStudents();
	void ReWriteDataBase(list<Student> students);
	Student GetStudentByNum(char* gradeBookNum);
	bool StudentExistsByNum(char* gradeBookNum);
};
