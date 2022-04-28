#pragma once
#include "Student.h"
#include <fstream>
using namespace std;

class StudentRepository
{
private:
	fstream _dataBase;

public:
	void AddStudent(Student student);
	bool StudentExistsByNum(char* gradeBookNum);
};
