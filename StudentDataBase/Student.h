#pragma once
#include "Date.h"
#include <cstring>
class Student
{
public:
    char Surname[20];
    char Name[20];
    char Patronymic[20];
    Date Birthday;
    short UniversityYear;
    char Faculty[9];
    char Department[7];
    char Group[11];
    char GradebookNumber[9];
    char Gender[9];

    Student() {};

    Student(
		char* surname,
        char* name,
        char* patronymic,
        Date birthday,
        short universityYear,
        char* faculty,
        char* department,
        char* group,
        char* gradebookNumber,
        char* gender)
    {
        strcpy_s(Surname, surname);
        strcpy_s(Name, name);
        strcpy_s(Patronymic,  patronymic);
        Birthday = birthday;
        UniversityYear = universityYear;
        strcpy_s(Faculty,  faculty);
        strcpy_s(Department,  department);
        strcpy_s(Group,  group);
        strcpy_s(GradebookNumber,  gradebookNumber);
        strcpy_s(Gender, gender);
    }

    static Student DefaultStudent()
    {
        Student student
        (
            nullptr,
            nullptr,
            nullptr,
            Date::DefaultDate(),
            0,
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr
        );

        return student;
    }

    static bool UniversityYearIsvalid(short univerYear, Date date)
    {
        return ((univerYear - date.year) >= 16);
    }

    bool operator == (const Student other)
    {
        return !strcmp(this->Name, other.Name) &&
            !strcmp(this->Surname, other.Surname) &&
            !strcmp(this->Patronymic, other.Patronymic) &&
            this->Birthday == other.Birthday &&
            this->UniversityYear == other.UniversityYear &&
            !strcmp(this->Faculty, other.Faculty) &&
            !strcmp(this->Department, other.Department) &&
            !strcmp(this->Group, other.Group) &&
            !strcmp(this->GradebookNumber, other.GradebookNumber) &&
            !strcmp(this->Gender, other.Gender);
    }

    bool operator != (const Student other)
    {
        return !(*this == other);
    }
};
