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
	cout << "������� ��� ������� ��������.\n";
}

//void StudentRepository::UpdateStudent(list<Student> students)
//{
//	if (!DatabaseExists())
//	{
//		cout << "���� ������ ��� �� �������.\n";
//		return;
//	}
//
//	char gradeBookNum[8];
//	cout << "������� ���� ��������, �������� ������ ��������: ";
//	cin.getline(gradeBookNum, 8);
//	cin.clear();
//	cin.ignore(cin.rdbuf()->in_avail());
//	_flushall();
//
//	list<Student> newList;
//	newList = GetNewList(students, gradeBookNum);
//
//	Student newStudent = _dataBaseIO.InputStudent();
//
//	newList.push_back(newStudent);
//
//	ReWriteDataBase(newList);
//
//	cout << "������� ��� ������� ������.\n";
//}

list<Student> StudentRepository::GetAllStudents()
{
	list<Student> students;
	if (!DatabaseExists())
	{
		cout << "���� ������ ��� �� �������.\n";
		return students;
	}

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

	cout << "�������� � ����� ������ �� ����������.\n";
	return Student::DefaultStudent();
}

list<Student> StudentRepository::GetNewList(list<Student> students, char* gradeBookNum)
{
	list<Student>::iterator i = students.begin();
	while (i != students.end())
	{
		if (!strcmp(i->GradebookNumber, gradeBookNum))
		{
			students.erase(i);
			cout << "������� ��� ������� �����.\n";
			return students;
		}
		i++;
	}
	cout << "�������� � ����� ������ �� ����������.\n";
	return students;
}

void StudentRepository::DeleteStudent(list<Student> students)
{
	if (!DatabaseExists())
	{
		cout << "���� ������ ��� �� �������.\n";
		return;
	}

	char gradeBookNum[8];
	cout << "������� ���� ��������, �������� ������ �������: ";
	cin.getline(gradeBookNum, 8);
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	_flushall();

	list<Student> newList;
	newList = GetNewList(students, gradeBookNum);

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
