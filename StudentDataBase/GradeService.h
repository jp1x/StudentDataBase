#pragma once
#include <iostream>
#include "GradeRepository.h"

class GradeService
{
public:
	GradeRepository _gradeRepository;
	void AddGrade(Education session);
	list<Education> GetAllGrades();
};
