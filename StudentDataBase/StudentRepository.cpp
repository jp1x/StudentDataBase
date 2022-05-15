#include "StudentRepository.h"

bool StudentRepository::DatabaseExists()
{
	ifstream infile("Students.txt");
	return infile.good();
}

bool StudentRepository::StudentExistsByNum(char* gradebookNum)
{
	if (!DatabaseExists())
		return false;

	Student student;
	bool exists = false;

	_dataBase.open("Students.txt", ios::binary | ios::in);
	while (!_dataBase.eof())
	{
		_dataBase.read((char*)&student, sizeof(student));
		if (!strcmp(student.GradebookNumber, gradebookNum))
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
	cout << "Студент был успешно добавлен.\n";
}

//void StudentRepository::UpdateStudent(list<Student> students)
//{
//	if (!DatabaseExists())
//	{
//		cout << "База данных ещё не создана.\n";
//		return;
//	}
//
//	char gradebookNum[8];
//	cout << "Введите шифр студента, которого хотите обновить: ";
//	cin.getline(gradebookNum, 8);
//	cin.clear();
//	cin.ignore(cin.rdbuf()->in_avail());
//	_flushall();
//
//	list<Student> newList;
//	newList = GetNewList(students, gradebookNum);
//
//	Student newStudent = _dataBaseIO.InputStudent();
//
//	newList.push_back(newStudent);
//
//	ReWriteDataBase(newList);
//
//	cout << "Студент был успешно изменён.\n";
//}

list<Student> StudentRepository::GetAllStudents()
{
	list<Student> students;

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

Student StudentRepository::GetStudentByNum(char* gradebookNum)
{
	if (!DatabaseExists())
		return Student::DefaultStudent();

	Student student;

	_dataBase.open("Students.txt", ios::binary | ios::in);
	while (!_dataBase.eof())
	{
		_dataBase.read((char*)&student, sizeof(student));
		if (!strcmp(student.GradebookNumber, gradebookNum))
		{
			_dataBase.close();
			return student;
		}
	}
	_dataBase.close();

	cout << "Студента с таким шифром не существует.\n";
	return Student::DefaultStudent();
}

list<Student> StudentRepository::RemoveStudentFromList(list<Student> students, char* gradebookNum)
{
	list<Student>::iterator i = students.begin();
	while (i != students.end())
	{
		if (!strcmp(i->GradebookNumber, gradebookNum))
		{
			students.erase(i);
			cout << "Студент был успешно удалён.\n";
			return students;
		}
		i++;
	}
	return students;
}

void StudentRepository::DeleteStudent(char* gradebookNum)
{
	if (!DatabaseExists())
	{
		cout << "База данных ещё не создана.\n";
		return;
	}

	list<Student> students = GetAllStudents();

	list<Student> newList = RemoveStudentFromList(students, gradebookNum);

	ReWriteDataBase(newList);
}

void StudentRepository::ReWriteDataBase(list<Student> students)
{
	_dataBase.open("Students.txt", ios::binary | ios::out | ios::trunc);
	for (const Student& student : students)
	{
		_dataBase.write((char*)&student, sizeof(Student));
	}
	_dataBase.close();
}

list<Student> StudentRepository::GetStudentsByGroupAndGenderForOneSession(
	char* group, char* gender, int sessionNum)
{
	list<Student> students = GetAllStudents();
	list<Student> studentsInGroup;

	for (Student& student : students)
	{
		if (!strcmp(student.Group, group))
		{
			if (!strcmp(student.Gender, gender))
			{
				student.AverageMarkForOneSession = _gradeRepository.GetRatingForOneSession(
					sessionNum, student.GradebookNumber);
				studentsInGroup.push_back(student);
			}
		}
	}
	return studentsInGroup;
}

list<Student> StudentRepository::GetStudentsByGroupAndGenderForAllSessions(
	char* group, char* gender)
{
	list<Student> students = GetAllStudents();
	list<Student> studentsInGroup;

	for (Student& student : students)
	{
		if (!strcmp(student.Group, group))
		{
			if (!strcmp(student.Gender, gender))
			{
				student.AverageMarkForAllSessions = _gradeRepository.GetRatingForAllSessions(
					student.GradebookNumber);
				studentsInGroup.push_back(student);
			}
		}
	}
	return studentsInGroup;
}
