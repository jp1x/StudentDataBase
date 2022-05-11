#pragma once
#include "DataBaseIO.h"
#include "StudentService.h"

class Menu
{
protected:
	DataBaseIO _dataBaseIO;
	StudentService _studentService;

public:
	virtual void UseMenu(const char* MenuItems[], size_t length) = 0;
	virtual const char** GetMenuItems() = 0;
	//virtual const char** GetChangeMenuItems() = 0;



};
