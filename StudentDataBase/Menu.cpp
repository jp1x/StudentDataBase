#include "Menu.h"
#include "Student.h"

void Menu::AddStudent()
{
	Student student = _dataBaseIO.InputStudent();
	_studentService.AddStudent(student);
}

void Menu::PrintDataBase()
{
	cout << setfill('=') << setw(120) << "=" << "\n";
	_studentService.GetAllStudents();
}
