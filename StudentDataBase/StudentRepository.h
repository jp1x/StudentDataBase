#pragma once
#include "Student.h"
#include "DataBaseIO.h"
#include <fstream>
using namespace std;

class StudentRepository
{
private:
	fstream _dataBase;
	DataBaseIO _dataBaseIO;
	bool DatabaseExists();

public:
	void AddStudent(Student student);
	Student GetStudentByNum(char* gradeBookNum);
	bool StudentExistsByNum(char* gradeBookNum);

};
