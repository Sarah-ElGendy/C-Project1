#pragma once
#include "GUI\GUI.h"
#include "Actions\Action.h"
#include "Rules.h"
#include "StudyPlan/StudyPlan.h"


//The maestro class for the application
class Registrar
{
	GUI *pGUI;	//pointer to GUI 
	Rules RegRules;	//Registration rules
	StudyPlan *pSPlan;
	
public:
	Registrar();
	GUI* getGUI() const;
	Action* CreateRequiredAction();
	bool ExecuteAction(Action*);
	void UpdateInterface();
	StudyPlan* getStudyPlay() const;

	void Run();

	~Registrar();
	//function to check if the course if found in course catalog or not
	CourseInfo* getcourseinfo(Course_Code code);
	CourseInfo* checkcourseinfo(Course_Code code);
	Course* checkStudyPlan(Course_Code code);
	
};

