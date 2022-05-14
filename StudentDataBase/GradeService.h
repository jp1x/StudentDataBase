#pragma once
#include <iostream>
#include "GradeRepository.h"

class GradeService
{
	GradeRepository _gradeRepository;

public:
	void AddGrade(Education session);
};
