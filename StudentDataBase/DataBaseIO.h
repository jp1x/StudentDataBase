#pragma once
#include <iostream>
#include <iomanip>
#include <list>
#include "Student.h"
using namespace std;

class DataBaseIO
{
public:
	Student InputStudent();
	char* InputSurname();
	char* InputName();
	char* InputPatronymic();
	Date InputDate();
	short InputUniversityYear();
	char* InputFaculty();
	char* InputDepartment();
	char* InputGroup();
	char* InputGradebookNumber();
	char* InputGender();
	Education InputGrades();
	void OutputStudent(list<Student> students);
	void OutputGrade(list<Education> grades);
	void OutPutStudentsInGroupForOneSession(list<Student> studentsInGroup);
	void OutPutStudentsInGroupForAllSessions(list<Student> studentsInGroup);
	void PrintMenuItems(const char* menuItems[], size_t length);
	void PrintGradeMenuItems(const char* gradeMenuItems[], size_t length);
	void PrintChangeMenuItems(const char* gradeMenuItems[], size_t length, Student student);
	int InputMenuItemNumber();
	int InputSessionNumber();
};
