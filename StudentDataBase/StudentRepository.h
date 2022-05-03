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
	void GetAllStudents();
	Student GetStudentByNum(char* gradeBookNum);
	bool StudentExistsByNum(char* gradeBookNum);

};
