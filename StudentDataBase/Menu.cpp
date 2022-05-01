#include "Menu.h"
#include "Student.h"

void Menu::AddStudent()
{
	Student student = _dataBaseIO.InputStudent();
	_studentService.AddStudent(student);
}
