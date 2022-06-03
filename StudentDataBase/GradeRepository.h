#pragma once
#include "Student.h"
#include "DataBaseIO.h"
#include <fstream>
#include <list>

class GradeRepository
{
private:
	fstream _gradeDataBase;
	DataBaseIO _gradeDataBaseIO;

public:
	bool GradeDatabaseExists();
	bool StudentExistsByNum(char* gradebookNum, short sessionNum);
	bool StudentExistsByNum(char* gradebookNum);
	void AddGrade(Education session);
	void DeleteGrade(char* gradebookNum);
	list<Education> RemoveGradeFromList(
		list<Education> grades, char* gradebookNum);
	list<Education> GetAllGrades();
	void RewriteGradeDataBase(list<Education> grades);
	float GetRatingForOneSession(int sessionNum, char* gradebookNum);
	float GetRatingForAllSessions(char* gradebookNum);
};
