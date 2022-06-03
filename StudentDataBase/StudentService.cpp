#include "StudentService.h"
#include "StudentRepository.h"
using namespace std;

bool StudentService::DatabaseExists(const char* databaseName)
{
	return _studentRepository.DatabaseExists(databaseName);
}

void StudentService::AddStudent(Student student)
{
	if (_studentValidator.StudentExistsByNum(student.GradebookNumber))
		return;

	if (!_studentValidator.DateIsValid(student.Birthday))
		return;

	if (!_studentValidator.UnivesityYearIsValid(student.UniversityYear, student.Birthday))
		return;

	if (!_studentValidator.SurnameIsValid(student.Surname))
		return;

	if (!_studentValidator.NameIsValid(student.Name))
		return;

	if (!_studentValidator.PatronymicIsValid(student.Patronymic))
		return;

	if (!_studentValidator.FacultyIsValid(student.Faculty))
		return;

	if (!_studentValidator.DeartmentIsValid(student.Department))
		return;

	if (!_studentValidator.GroupIsValid(student.Group))
		return;

	if (!_studentValidator.GradebookNumberIsValid(student.GradebookNumber))
		return;

	if (!_studentValidator.GenderIsValid(student.Gender))
		return;

	_studentRepository.AddStudent(student);
}

void StudentService::DeleteStudent(char* gradebookNum)
{
	bool databaseExists = _studentRepository.DatabaseExists("Students.txt");
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

	bool gradeDatabaseExists = _gradeRepository.GradeDatabaseExists();
	if (!gradeDatabaseExists)
	{
		cout << "База данных с оценками ещё не создана.\n";
	}

	bool studentGradesExists = _gradeRepository.StudentExistsByNum(gradebookNum);
	if (!studentGradesExists)
	{
		cout << "У студента с шифром " << gradebookNum << " не было оценок.\n";
	}

	_gradeRepository.DeleteGrade(gradebookNum);
	_studentRepository.DeleteStudent(gradebookNum);
}

bool StudentService::StudentExistsByNum(char* gradebookNum)
{
	return _studentRepository.StudentExistsByNum(gradebookNum);
}

void StudentService::UpdateStudent(Student student, char* gradebookNum)
{
	_studentRepository.UpdateStudent(student, gradebookNum);
}

Student StudentService::GetStudentByNum(char* gradebookNum)
{
	return _studentRepository.GetStudentByNum(gradebookNum);
}

list<Student> StudentService::GetAllStudents()
{
	return _studentRepository.GetAllStudents();
}

list<Student> StudentService::GetStudentsByGroupAndGenderForOneSession(
	char* group, char* gender, int sessionNum)
{
	list<Student> studentsInGroup = _studentRepository.GetStudentsByGroupAndGenderForOneSession(
		group, gender, sessionNum);

	studentsInGroup.sort([](const Student& st1, const Student& st2)
		{
			return st1.AverageMarkForOneSession > st2.AverageMarkForOneSession;
		});

	return studentsInGroup;
}

list<Student> StudentService::GetStudentsByGroupAndGenderForAllSessions(
	char* group, char* gender)
{
	list<Student> studentsInGroup = _studentRepository.GetStudentsByGroupAndGenderForAllSessions(
		group, gender);

	studentsInGroup.sort([](const Student& st1, const Student& st2)
		{
			return st1.AverageMarkForAllSessions > st2.AverageMarkForAllSessions;
		});

	return studentsInGroup;
}
