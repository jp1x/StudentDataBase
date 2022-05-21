#include "DataBaseIO.h"
#define BufClean cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); _flushall();
using namespace std;

Student DataBaseIO::InputStudent()
{
	char surname[20];
	char name[20];
	char patronymic[20];
	unsigned short dd, mm, yyyy;
	short universityYear;
	char faculty[9];
	char department[7];
	char group[11];
	char gradebookNumber[8];
	char gender[8];

	cout << "Фамилия: ";
	cin.getline(surname, 20);
	BufClean;

	cout << "Имя: ";
	cin.getline(name, 20);
	BufClean;

	cout << "Отчество: ";
	cin.getline(patronymic, 20);
	BufClean;

	cout << "Дата рождения(DD MM YYYY): ";
	cin >> dd >> mm >> yyyy;
	Date birthday(dd, mm, yyyy);
	BufClean;

	cout << "Год поступления: ";
	cin >> universityYear;
	BufClean;

	cout << "Факультет: ";
	cin.getline(faculty, 9);
	BufClean;

	cout << "Кафедра: ";
	cin.getline(department, 7);
	BufClean;

	cout << "Группа: ";
	cin.getline(group, 11);
	BufClean;

	cout << "Номер зачетной книжки: ";
	cin.getline(gradebookNumber, 8);
	BufClean;

	cout << "Пол: ";
	cin.getline(gender, 8);
	BufClean;

	Student person
	(
		surname,
		name,
		patronymic,
		birthday,
		universityYear,
		faculty,
		department,
		group,
		gradebookNumber,
		gender,
		0,
		0
	);
	
	return person;
}

Education DataBaseIO::InputGrades()
{
	char gradebookNumber[8];
	short sessionNumber;
	short subjectsAmount;
	
	cout << "Номер зачетной книжки: ";
	cin.getline(gradebookNumber, 8);
	BufClean;

	cout << "Номер сессии: ";
	cin >> sessionNumber;
	while (getchar() != '\n');
	BufClean;

	while (true)
	{
		cout << "Количество дисциплин: ";
		cin >> subjectsAmount;
		while (getchar() != '\n');
		BufClean;

		if (subjectsAmount < 1 || subjectsAmount > 10)
			cout << "Неверное количество дисциплин. Макс. количество - 10\n";

		break;
	}

	Subject* Subjects = new Subject[subjectsAmount];

	for (short i = 0; i < subjectsAmount; i++)
	{
		cout << "Дисциплина " << i + 1 << ": ";
		cin.getline(Subjects[i].Title, 30);
		BufClean;

		cout << "(2) - незачёт\n";
		cout << "(3) - удовлетворительно\n";
		cout << "(4) - хорошо\n";
		cout << "(5) - отлично\n";

		cout << "Оценка: ";
		cin >> Subjects[i].Mark;
		while (getchar() != '\n');
		BufClean;
	}

	Education session
	(
		gradebookNumber,
		sessionNumber,
		subjectsAmount,
		Subjects
	);

	delete[] Subjects;

	return session;
}

void DataBaseIO::OutputStudent(list<Student> students)
{	
	if (students.empty())
	{
		cout << "База данных пуста.\n";
		return;
	}
	cout << setfill('=') << setw(120) << "=" << "\n";
	for (const Student& student : students)
	{
		cout << '|' << setfill(' ') << setw(19) << left << student.Surname <<
			'|' << setfill(' ') << setw(19) << left << student.Name <<
			'|' << setfill(' ') << setw(19) << left << student.Patronymic <<
			'|' << setfill('0') << setw(2) << right << student.Birthday.day <<
			"." << setfill('0') << setw(2) << right << student.Birthday.month <<
			"." << student.Birthday.year <<
			'|' << setfill(' ') << setw(4) << left << student.UniversityYear <<
			'|' << setfill(' ') << setw(8) << left << student.Faculty <<
			'|' << setfill(' ') << setw(6) << left << student.Department <<
			'|' << setfill(' ') << setw(10) << left << student.Group <<
			'|' << setfill(' ') << setw(7) << left << student.GradebookNumber <<
			'|' << setfill(' ') << setw(7) << left << student.Gender << '|' << "\n";
		cout << setfill('=') << setw(120) << "=" << "\n";
	}
}

void DataBaseIO::OutputGrade(list<Education> grades)
{
	if (grades.empty())
	{
		cout << "База данных с оценками пуста.\n";
		return;
	}
	cout << setfill('=') << setw(70) << "=" << "\n";
	for (const Education& grade : grades)
	{
		cout << '|' << setfill(' ') << setw(8) << left << grade.GradebookNumber <<
			'|' << "Сессия " << grade.SessionNumber <<
			'|' << "[5]: " << setfill(' ') << setw(2) << left << grade.CountFives(grade) <<
			'|' << "[4]: " << setfill(' ') << setw(2) << left << grade.CountFours(grade) <<
			'|' << "[3]: " << setfill(' ') << setw(2) << left << grade.CountThrees(grade) <<
			'|' << "[2]: " << setfill(' ') << setw(2) << left << grade.CountTwos(grade) <<
			'|' << "Средний балл: " << setfill(' ') << setw(4) << left <<
			grade.AverageMark(grade) << '|' << "\n";
		cout << setfill('=') << setw(70) << "=" << "\n";
	}
}

void DataBaseIO::OutPutStudentsInGroupForOneSession(list<Student> studentsInGroup)
{
	if (studentsInGroup.empty())
	{
		cout << "В нужной группе студентов нужного пола нет.\n";
		return;
	}
	
	cout << setfill('=') << setw(139) << "=" << "\n";
	for (const Student& student : studentsInGroup)
	{
		cout << '|' << setfill(' ') << setw(19) << left << student.Surname <<
			'|' << setfill(' ') << setw(19) << left << student.Name <<
			'|' << setfill(' ') << setw(19) << left << student.Patronymic <<
			'|' << setfill('0') << setw(2) << right << student.Birthday.day <<
			"." << setfill('0') << setw(2) << right << student.Birthday.month <<
			"." << student.Birthday.year <<
			'|' << setfill(' ') << setw(4) << left << student.UniversityYear <<
			'|' << setfill(' ') << setw(8) << left << student.Faculty <<
			'|' << setfill(' ') << setw(6) << left << student.Department <<
			'|' << setfill(' ') << setw(10) << left << student.Group <<
			'|' << setfill(' ') << setw(7) << left << student.GradebookNumber <<
			'|' << setfill(' ') << setw(7) << left << student.Gender << 
			'|' << "Средний балл: " << setfill(' ') << setw(4) <<
			student.AverageMarkForOneSession << '|' << "\n";
		cout << setfill('=') << setw(139) << "=" << "\n";
	}
}

void DataBaseIO::OutPutStudentsInGroupForAllSessions(list<Student> studentsInGroup)
{
	if (studentsInGroup.empty())
	{
		cout << "В нужной группе студентов нужного пола нет.\n";
		return;
	}

	cout << setfill('=') << setw(139) << "=" << "\n";
	for (const Student& student : studentsInGroup)
	{
		cout << '|' << setfill(' ') << setw(19) << left << student.Surname <<
			'|' << setfill(' ') << setw(19) << left << student.Name <<
			'|' << setfill(' ') << setw(19) << left << student.Patronymic <<
			'|' << setfill('0') << setw(2) << right << student.Birthday.day <<
			"." << setfill('0') << setw(2) << right << student.Birthday.month <<
			"." << student.Birthday.year <<
			'|' << setfill(' ') << setw(4) << left << student.UniversityYear <<
			'|' << setfill(' ') << setw(8) << left << student.Faculty <<
			'|' << setfill(' ') << setw(6) << left << student.Department <<
			'|' << setfill(' ') << setw(10) << left << student.Group <<
			'|' << setfill(' ') << setw(7) << left << student.GradebookNumber <<
			'|' << setfill(' ') << setw(7) << left << student.Gender <<
			'|' << "Средний балл: " << setfill(' ') << setw(4) <<
			student.AverageMarkForAllSessions << '|' << "\n";
		cout << setfill('=') << setw(139) << "=" << "\n";
	}
}

void DataBaseIO::PrintMenuItems(const char* menuItems[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << menuItems[i] << "\n";
	}
}

void DataBaseIO::PrintGradeMenuItems(const char* gradeMenuItems[], size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		cout << gradeMenuItems[i] << "\n";
	}
}

void DataBaseIO::PrintChangeMenuItems(const char* changeMenuItems[], size_t length, Student student)
{
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[0] << ' ' << student.Surname << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[1] << ' ' << student.Name << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[2] << ' ' << student.Patronymic << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[3] << ' ' << setfill('0') << setw(2) <<
		right << student.Birthday.day << "." << setfill('0') <<
		setw(2) << right << student.Birthday.month << "." <<
		student.Birthday.year << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[4] << ' ' << student.UniversityYear << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[5] << ' ' << student.Faculty << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[6] << ' ' << student.Department << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[7] << ' ' << student.Group << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[8] << ' ' << student.GradebookNumber << "\n";
	cout << setfill(' ') << setw(30) << left <<
		changeMenuItems[9] << ' ' << student.Gender << "\n";
	for (size_t i = 10; i < 13; i++)
	{
		cout << changeMenuItems[i] << "\n";
	}
}

int DataBaseIO::InputMenuItemNumber()
{
	int number;
	cout << "Введите номер пункта меню: ";
	cin >> number;
	while (getchar() != '\n');
	return number;
}

char surname[20];
char* DataBaseIO::InputSurname()
{
	cout << "Введите фамилию: ";
	cin.getline(surname, 20);
	BufClean;
	return surname;
}

char name[20];
char* DataBaseIO::InputName()
{
	cout << "Введите имя: ";
	cin.getline(name, 20);
	BufClean;
	return name;
}

char patronymic[20];
char* DataBaseIO::InputPatronymic()
{
	cout << "Введите отчество: ";
	cin.getline(patronymic, 20);
	BufClean;
	return patronymic;
}

Date DataBaseIO::InputDate()
{
	Date birthday;
	cout << "Введите дату рождения: ";
	cin >> birthday.day >> birthday.month >> birthday.year;
	BufClean;
	return birthday;
}

short DataBaseIO::InputUniversityYear()
{
	short universityYear;
	cout << "Введите год поступления: ";
	cin >> universityYear;
	BufClean;
	return universityYear;
}

char faculty[9];
char* DataBaseIO::InputFaculty()
{
	cout << "Введите факультет: ";
	cin.getline(faculty, 9);
	BufClean;
	return faculty;
}

char department[7];
char* DataBaseIO::InputDepartment()
{
	cout << "Введите кафедру: ";
	cin.getline(department, 7);
	BufClean;
	return department;
}

char group[11];
char* DataBaseIO::InputGroup()
{
	cout << "Введите группу: ";
	cin.getline(group, 11);
	BufClean;
	return group;
}

char gradebookNumber[8];
char* DataBaseIO::InputGradebookNumber()
{
	cout << "Введите номер зачетной книжки студента: ";
	cin.getline(gradebookNumber, 8);
	BufClean;
	return gradebookNumber;
}

char gender[8];
char* DataBaseIO::InputGender()
{
	cout << "Введите пол: ";
	cin.getline(gender, 8);
	BufClean;
	return gender;
}

int DataBaseIO::InputSessionNumber()
{
	int sessionNum;
	cout << "Введите номер сессии: ";
	cin >> sessionNum;
	while (getchar() != '\n');
	return sessionNum;
}
