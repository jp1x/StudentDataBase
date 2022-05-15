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
	char* InputGradebookNum();
	Education InputGrades();
	void OutputStudent(list<Student> students);
	void OutputGrade(list<Education> grades);
	void OutPutStudentsInGroupForOneSession(list<Student> studentsInGroup);
	void PrintMenuItems(const char* menuItems[], size_t length);
	void PrintGradeMenuItems(const char* gradeMenuItems[], size_t length);
	int InputMenuItemNumber();
	char* InputGroup();
	char* InputGender();
	int InputSessionNumber();
};
