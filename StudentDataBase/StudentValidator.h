#pragma once
#include "Student.h"
#include "StudentRepository.h"

class StudentValidator
{
private:
	const char* incorrectSimbols[27] = { "/", ".", ",", "[", "]", "(", ")",
		"{", "}", "`", "!", "@", "#", "¹", "$", ";", "%", "^", ":", "&",
		"?", "*", "|", "<", ">", "+", "=" };
	const char* incorrectSimbolsAndNums[37] = { "/", ".", ",", "[", "]", "(", ")",
		"{", "}", "`", "!", "@", "#", "¹", "$", ";", "%", "^", ":", "&",
		"?", "*", "|", "<", ">", "+", "=", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	StudentRepository _studentRepository;

public:
	bool InitialsAreValid(char* value);
	bool CharFieldIsValid(char* value, short length);
	bool StudentExistsByNum(char* gradebookNum);
	bool DateIsValid(Date birthday);
	bool UnivesityYearIsValid(short universityYear, Date birthday);
	bool SurnameIsValid(char* surname);
	bool NameIsValid(char* name);
	bool PatronymicIsValid(char* patronymic);
	bool FacultyIsValid(char* faculty);
	bool DeartmentIsValid(char* department);
	bool GroupIsValid(char* group);
	bool GradebookNumberIsValid(char* gradebookNum);
	bool GenderIsValid(char* gender);
};
