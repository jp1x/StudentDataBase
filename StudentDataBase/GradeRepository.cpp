#include <iostream>
#include "GradeRepository.h"

bool GradeRepository::GradeDatabaseExists()
{
	ifstream infile("Grades.txt");
	return infile.good();
}

void GradeRepository::AddGrade(Education session)
{
	_gradeDataBase.open("Grades.txt", ios::binary | ios::out | ios::app);
	_gradeDataBase.write((char*)&session, sizeof(Education));
	_gradeDataBase.close();
	cout << "ќценки студента были успешно добавлен.\n";
}

bool GradeRepository::StudentExistsByNum(char* gradebookNum)
{
	if (!GradeDatabaseExists())
		return false;

	Education session;
	bool exists = false;

	_gradeDataBase.open("Grades.txt", ios::binary | ios::in);
	while (!_gradeDataBase.eof())
	{
		_gradeDataBase.read((char*)&session, sizeof(session));
		if (!strcmp(session.GradebookNumber, gradebookNum))
		{
			exists = true;
			break;
		}
	}
	_gradeDataBase.close();

	return exists;
}
