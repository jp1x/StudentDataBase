#include "StudentRepository.h"

bool StudentRepository::DatabaseExists()
{
	ifstream infile("Students.txt");
	return infile.good();
}

bool StudentRepository::StudentExistsByNum(char* gradeBookNum)
{
	if (!DatabaseExists())
		return false;

	Student student;
	bool exists = false;

	_dataBase.open("Students.txt", ios::binary | ios::in);
	while (!_dataBase.eof())
	{
		_dataBase.read((char*)&student, sizeof(student));
		if (!strcmp(student.GradebookNumber, gradeBookNum))
		{
			exists = true;
			break;
		}
	}
	_dataBase.close();

	return exists;
}

void StudentRepository::AddStudent(Student student)
{
	_dataBase.open("Students.txt", ios::binary | ios::out | ios::app);
	_dataBase.write((char*)&student, sizeof(Student));
	_dataBase.close();
}

list<Student> StudentRepository::GetAllStudents()
{
	list<Student> students;
	if (!DatabaseExists())
		return students;

	cout << setfill('=') << setw(120) << "=" << "\n\n";

	Student* person = new Student;
	_dataBase.open("Students.txt", ios::binary | ios::in);
	while (_dataBase.peek() != EOF)
	{
		_dataBase.read((char*)person, sizeof(Student));
		Student temp(*person);
		students.push_back(temp);
	}
	_dataBase.close();
	delete person;

	return students;
}

Student StudentRepository::GetStudentByNum(char* gradeBookNum)
{
	if (!DatabaseExists())
		return Student::DefaultStudent();

	Student student;

	_dataBase.open("Students.txt", ios::binary | ios::in);
	while (!_dataBase.eof())
	{
		_dataBase.read((char*)&student, sizeof(student));
		if (!strcmp(student.GradebookNumber, gradeBookNum))
		{
			_dataBase.close();
			return student;
		}
	}
	_dataBase.close();

	return Student::DefaultStudent();
}
