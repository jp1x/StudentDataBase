#include "GradeService.h"
#include "GradeRepository.h"

void GradeService::AddGrade(Education session)
{
	bool studentExists = _gradeRepository.StudentExistsByNum(session.GradebookNumber);

	if (studentExists)
	{
		cout << "������� � ������ " << session.GradebookNumber << " ��� ����������.\n";
		return;
	}

	_gradeRepository.AddGrade(session);
}

