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
	_gradeDataBase.write((char*)&session, sizeof(session));
	_gradeDataBase.close();
	cout << "ќценки студента были успешно добавлены.\n";
}

bool GradeRepository::StudentExistsByNum(char* gradebookNum, short sessionNum)
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
			if (session.SessionNumber == sessionNum)
			{
				exists = true;
				break;
			}
		}
	}
	_gradeDataBase.close();

	return exists;
}

list<Education> GradeRepository::GetAllGrades()
{
	list<Education> grades;

	Education* grade = new Education;

	_gradeDataBase.open("Grades.txt", ios::binary | ios::in);
	while (_gradeDataBase.peek() != EOF)
	{
		_gradeDataBase.read((char*)grade, sizeof(Education));
		Education temp(*grade);
		grades.push_back(temp);
	}
	_gradeDataBase.close();
	delete grade;

	return grades;
}
