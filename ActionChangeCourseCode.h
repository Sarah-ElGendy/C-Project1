#pragma once
#pragma once
#include "Actions\Action.h"
#include "Actions\ActionAddCourse.h"
#include "Courses\Course.h"
#include "Registrar.h"
#include "Rules.h"
#include <iostream>

class ActionChangeCourseCode : public Action
{
	ActionChangeCourseCode(Registrar*);
	bool virtual Execute();
	virtual ~ActionChangeCourseCode();
};

