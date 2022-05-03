#pragma once
#include <iostream>
#include <iomanip>
#include <list>
#include "Student.h"

class DataBaseIO
{
public:
	Student InputStudent();
	void OutputStudent(/*list<Student> _students*/Student student);
};
