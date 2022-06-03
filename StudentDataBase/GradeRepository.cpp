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

list<Education> GradeRepository::RemoveGradeFromList(list<Education> grades, char* gradebookNum)
{
	list<Education>::iterator i = grades.begin();
	list<Education>::iterator iTemp = grades.begin();
	while (i != grades.end())
	{
		if (!strcmp(i->GradebookNumber, gradebookNum))
		{
			iTemp = i;
			grades.erase(iTemp);
			cout << "ќценки студента были успешно удалены.\n";
			if (grades.empty())
			{
				break;
			}
			i = grades.begin();
		}
		if (strcmp(i->GradebookNumber, gradebookNum))
		{
			Education iEnd = grades.back();
			if (!strcmp(i->GradebookNumber, iEnd.GradebookNumber) && grades.size() == 1)
				break;
			i++;
		}
	}
	return grades;
}

void GradeRepository::DeleteGrade(char* gradebookNum)
{
	list<Education> grades = GetAllGrades();

	list<Education> newList = RemoveGradeFromList(grades, gradebookNum);

	RewriteGradeDataBase(newList);
}

void GradeRepository::RewriteGradeDataBase(list<Education> grades)
{
	_gradeDataBase.open("Grades.txt", ios::binary | ios::out | ios::trunc);
	for (const Education& grade : grades)
	{
		_gradeDataBase.write((char*)&grade, sizeof(Education));
	}
	_gradeDataBase.close();
}

float GradeRepository::GetRatingForOneSession(int sessionNum, char* gradebookNum)
{
	float averageMark = 0;
	list<Education> grades = GetAllGrades();

	for (const Education& grade : grades)
	{
		if (!strcmp(grade.GradebookNumber, gradebookNum))
		{
			if (grade.SessionNumber == sessionNum)
			{
				averageMark = grade.AverageMark(grade);
			}
		}
	}

	return averageMark;
}

float GradeRepository::GetRatingForAllSessions(char* gradebookNumber)
{
	float averageMark = 0;
	int k = 1;
	list<Education> grades = GetAllGrades();

	for (const Education& grade : grades)
	{
		if (!strcmp(grade.GradebookNumber, gradebookNumber))
		{
			if (grade.CountMarks(grade) != 0)
			averageMark += (grade.CountFives(grade) * 5
				+ grade.CountFours(grade) * 4
				+ grade.CountThrees(grade) * 3
				+ grade.CountTwos(grade) * 2)
				/ (grade.CountMarks(grade));
			k++;
		}
	}
	
	if (k != 1)
		k -= 1;
	return round((averageMark/k)*100)/100;
}
