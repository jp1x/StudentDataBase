#include "GradeService.h"
#include "GradeRepository.h"

void GradeService::AddGrade(Education session)
{
	bool studentExists = _gradeRepository.StudentExistsByNum(session.GradebookNumber, session.SessionNumber);
	if (studentExists)
	{
		cout << "������ �������� � ������ " << session.GradebookNumber << " �� "
			<< session.SessionNumber << " ������ ��� ���������.\n";
		return;
	}

	bool gradebookIsValid = session.GradebookNumberIsValid(session.GradebookNumber);
	if (!gradebookIsValid)
	{
		cout << "���� �������� ����� ����������� �������.\n";
		return;
	}

	if (session.SessionNumber < 1 || session.SessionNumber > 9)
	{
		cout << "�������� ����� ������. ����. ���������� ������ - 9\n";
		return;
	}

	for (short i = 0; i < session.SubjectsAmount; i++)
	{
		bool subjectIsValid = session.SubjectIsValid(session.Subjects[i].Title);
		if (!subjectIsValid)
		{
			cout << "������� ���������� " << i + 1 << " ����� ����������� �������.\n";
			return;
		}

		if (session.Subjects[i].Mark < 2 || session.Subjects[i].Mark > 5)
		{
			cout << "�������� ������ ���������� " << i + 1 << ".\n";
			return;
		}
	}

	_gradeRepository.AddGrade(session);
}
