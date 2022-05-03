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
	void OutputStudent(list<Student> students);
	void PrintMenuItems(const char* menuItems[], size_t length);
	int InputMenuItemNumber();
};
