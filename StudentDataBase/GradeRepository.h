#pragma once
#include "Student.h"
#include "DataBaseIO.h"
#include <fstream>
#include <list>

class GradeRepository
{
	fstream _gradeDataBase;
	DataBaseIO _gradeDataBaseIO;
	bool GradeDatabaseExists();

public:
	void AddGrade(Education session);
	list<Education> GetAllGrades();
	bool StudentExistsByNum(char* gradebookNum, short sessionNum);
};
