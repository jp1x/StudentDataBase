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

	bool dateIsValid = Date::DateIsValid(student.Birthday);
	if (!dateIsValid)
	{
		cout << "Некорректная дата рождения.\n";
		return;
	}

	bool uniYearIsValid = Student::UniversityYearIsValid(student.UniversityYear, student.Birthday);
	if (!uniYearIsValid)
	{
		cout << "Студент с возрастом менее 16 лет не может поступить в ВУЗ.\n";
		cout << "Или такой год для поступления ещё не наступил.\n";
		return;
	}

	bool surnameIsValid = student.InitialsAreValid(student.Surname);
	if (!surnameIsValid)
	{
		cout << "Фамилия студента имеет запрещенные символы.\n";
		return;
	}

	bool nameIsValid = student.InitialsAreValid(student.Name);
	if (!nameIsValid)
	{
		cout << "Имя студента имеет запрещенные символы.\n";
		return;
	}

	bool patronymicIsValid = student.InitialsAreValid(student.Patronymic);
	if (!patronymicIsValid)
	{
		cout << "Отчество студента имеет запрещенные символы.\n";
		return;
	}

	bool facultyIsValid = student.CharFieldIsValid(student.Faculty, 9);
	if (!facultyIsValid)
	{
		cout << "Факультет студента имеет запрещенные символы.\n";
		return;
	}

	bool departmentIsValid = student.CharFieldIsValid(student.Department, 7);
	if (!departmentIsValid)
	{
		cout << "Кафедра студента имеет запрещенные символы.\n";
		return;
	}

	bool groupIsValid = student.CharFieldIsValid(student.Group, 11);
	if (!groupIsValid)
	{
		cout << "Группа студента имеет запрещенные символы.\n";
		return;
	}

	bool gradebookIsValid = student.CharFieldIsValid(student.GradebookNumber, 8);
	if (!gradebookIsValid)
	{
		cout << "Шифр студента имеет запрещенные символы.\n";
		return;
	}

	bool genderIsValid = student.CharFieldIsValid(student.Gender, 8);
	if (!genderIsValid)
	{
		cout << "Пол студента имеет запрещенные символы.\n";
		return;
	}

	_studentRepository.AddStudent(student);
}

void StudentService::DeleteStudent(char* gradebookNum)
{
	bool databaseExists = _studentRepository.DatabaseExists();
	if (!databaseExists)
	{
		cout << "База данных ещё не создана.\n";
		return;
	}

	bool studentExists = _studentRepository.StudentExistsByNum(gradebookNum);
	if (!studentExists)
	{
		cout << "Студента с шифром " << gradebookNum << " не существует.\n";
		return;
	}

	_studentRepository.DeleteStudent(gradebookNum);
}

//void StudentService::UpdateStudent(list<Student> students)
//{
//	_studentRepository.UpdateStudent(students);
//}

list<Student> StudentService::GetAllStudents()
{
	return _studentRepository.GetAllStudents();
}
