#pragma once
#include "DataBaseIO.h"
#include "StudentService.h"

class Menu
{
private:
	DataBaseIO _dataBaseIO;
	StudentService _studentService;

public:
	void AddStudent();
};
