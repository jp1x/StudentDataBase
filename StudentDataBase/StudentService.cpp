#include "StudentService.h"
#include "StudentRepository.h"
using namespace std;

void StudentService::AddStudent(Student student)
{
	bool studentExists = _studentRepository.StudentExistsByNum(student.GradebookNumber);

	if (studentExists)
	{
		cout << "Студент с шифром " << student.GradebookNumber << " уже существует.\n";
		return;
	}

	bool dateIsvalid = Date::DateIsValid(student.Birthday);

	if (!dateIsvalid)
	{
		cout << "Некорректная дата рождения.\n";
		return;
	}

	bool uniYearIsvalid = Student::UniversityYearIsvalid(student.UniversityYear, student.Birthday);

	if (!uniYearIsvalid)
	{
		cout << "Студент с возрастом менее 16 лет не может поступить в ВУЗ.\n";
		return;
	}


	//TODO
	//провалидировать остальные поля

	_studentRepository.AddStudent(student);
}

list<Student> StudentService::GetAllStudents()
{
	return _studentRepository.GetAllStudents();
}
