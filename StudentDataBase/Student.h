#pragma once
#include "Date.h"
#include <cstring>

class Student
{
    const char* incorrectSimbols[27] = { "/", ".", ",", "[", "]", "(", ")",
        "{", "}", "`", "!", "@", "#", "¹", "$", ";", "%", "^", ":", "&",
        "?", "*", "|", "<", ">", "+", "=" };
    const char* incorrectSimbolsAndNums[37] = { "/", ".", ",", "[", "]", "(", ")",
        "{", "}", "`", "!", "@", "#", "¹", "$", ";", "%", "^", ":", "&",
        "?", "*", "|", "<", ">", "+", "=", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
public:
    char Surname[20];
    char Name[20];
    char Patronymic[20];
    Date Birthday;
    short UniversityYear;
    char Faculty[9];
    char Department[7];
    char Group[11];
    char GradebookNumber[8];
    char Gender[8];
    float AverageMarkForOneSession;

    Student() = default;

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
        char* gender,
        float averageMarkForOneSession)
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
        AverageMarkForOneSession = averageMarkForOneSession;
    }

    Student(const Student& student)
    {
        strcpy_s(Surname, student.Surname);
        strcpy_s(Name, student.Name);
        strcpy_s(Patronymic, student.Patronymic);
        Birthday = student.Birthday;
        UniversityYear = student.UniversityYear;
        strcpy_s(Faculty, student.Faculty);
        strcpy_s(Department, student.Department);
        strcpy_s(Group, student.Group);
        strcpy_s(GradebookNumber, student.GradebookNumber);
        strcpy_s(Gender, student.Gender);
        AverageMarkForOneSession = student.AverageMarkForOneSession;
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
            nullptr,
            0
        );

        return student;
    }

    static bool UniversityYearIsValid(short univerYear, Date date)
    {
        tm Tm;
        time_t now = time(nullptr);
        localtime_s(&Tm, &now);

        if (!((univerYear - date.year) >= 16))
            return false;

        if ((univerYear > (Tm.tm_year + 1900)))
            return false;

        return true;
    }

    bool InitialsAreValid(char* value)
    {
        for (short i = 0; i < 20; i++)
        {
            for (short j = 0; j < 37; j++)
            {
                if (value[i] == *incorrectSimbolsAndNums[j])
                    return false;
            }
        }

        return true;
    }

    bool CharFieldIsValid(char* value, short length)
    {
        for (short i = 0; i < length; i++)
        {
            for (short j = 0; j < 27; j++)
            {
                if (value[i] == *incorrectSimbols[j])
                    return false;
            }
        }

        return true;
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

class Subject
{
public:
    char Title[30];
    short Mark;

    Subject()
    {
        *Title = '-';
        Mark = 0;
    }
};

class Education
{
    const char* incorrectSimbols[27] = { "/", ".", ",", "[", "]", "(", ")",
        "{", "}", "`", "!", "@", "#", "¹", "$", ";", "%", "^", ":", "&",
        "?", "*", "|", "<", ">", "+", "=" };
    const char* incorrectSimbolsAndNums[37] = { "/", ".", ",", "[", "]", "(", ")",
        "{", "}", "`", "!", "@", "#", "¹", "$", ";", "%", "^", ":", "&",
        "?", "*", "|", "<", ">", "+", "=", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
public:
    char GradebookNumber[8];
    short SessionNumber;
    short SubjectsAmount;
    Subject Subjects[10];

    Education() = default;

    Education(
        char* gradebookNumber,
        short sessionNumber,
        short subjectAmount,
        Subject subjects[])
    {
        strcpy_s(GradebookNumber, gradebookNumber);
        SessionNumber = sessionNumber;
        SubjectsAmount = subjectAmount;
        for (short i = 0; i < subjectAmount; i++)
        {
            Subjects[i] = subjects[i];
        }
    }

    bool SubjectIsValid(char* title)
    {
        for (short i = 0; i < 30; i++)
        {
            for (short j = 0; j < 37; j++)
            {
                if (title[i] == *incorrectSimbolsAndNums[j])
                    return false;
            }
        }

        return true;
    }

    bool GradebookNumberIsValid(char* gradebookNum)
    {
        for (short i = 0; i < 8; i++)
        {
            for (short j = 0; j < 27; j++)
            {
                if (gradebookNum[i] == *incorrectSimbols[j])
                    return false;
            }
        }

        return true;
    }

    static float CountFives(Education session)
    {
        short countFives = 0;
        for (short i = 0; i < session.SubjectsAmount; i++)
        {
            if (session.Subjects[i].Mark == 5)
                countFives++;
        }
        return countFives;
    }

    static float CountFours(Education session)
    {
        short countFours = 0;
        for (short i = 0; i < session.SubjectsAmount; i++)
        {
            if (session.Subjects[i].Mark == 4)
                countFours++;
        }
        return countFours;
    }

    static float CountThrees(Education session)
    {
        short countThrees = 0;
        for (short i = 0; i < session.SubjectsAmount; i++)
        {
            if (session.Subjects[i].Mark == 3)
                countThrees++;
        }
        return countThrees;
    }

    static float CountTwos(Education session)
    {
        short countTwos = 0;
        for (short i = 0; i < session.SubjectsAmount; i++)
        {
            if (session.Subjects[i].Mark == 2)
                countTwos++;
        }
        return countTwos;
    }

    static float CountMarks(Education session)
    {
        return CountFives(session) + CountFours(session) +
            CountThrees(session) + CountTwos(session);
    }

    static float AverageMark(Education session)
    {
        float averageMark = 0;
        averageMark = (CountFives(session) * 5 + CountFours(session) * 4
            + CountThrees(session) * 3 + CountTwos(session) * 2) / (CountMarks(session));
        return round(averageMark*100)/100;
    }
};
