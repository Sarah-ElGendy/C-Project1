#include "Registrar.h"
#include "Rules.h"
#include "Actions/ActionAddCourse.h"
#include "StudyPlan\StudyPlan.h"
#include "StudyPlan\AcademicYear.h"
#include <iostream>
using namespace std;


Registrar::Registrar()
{
	pGUI = new GUI;	//create interface object
	pSPlan = new StudyPlan;	//create a study plan.
}

//returns a pointer to GUI
GUI* Registrar::getGUI() const
{
	return pGUI;
}

//returns the study plan
StudyPlan* Registrar::getStudyPlay() const
{
	return pSPlan;
}

Action* Registrar::CreateRequiredAction() 
{	
	ActionData actData = pGUI->GetUserAction("Pick and action...");
	Action* RequiredAction = nullptr;

	switch (actData.actType)
	{
	case ADD_CRS:	//add_course action
		RequiredAction = new ActionAddCourse(this);
		break;

	//TODO: Add case for each action
	
	/*case EXIT:
		break;
		*/
	}
	return RequiredAction;
}

//Executes the action, Releases its memory, and return true if done, false if cancelled
bool Registrar::ExecuteAction(Action* pAct)
{
	bool done = pAct->Execute();
	delete pAct;	//free memory of that action object (either action is exec or cancelled)
	return done;
}

void Registrar::Run()
{
	while (true)
	{
		//update interface here as CMU Lib doesn't refresh itself
		//when window is minimized then restored
		UpdateInterface();

		Action* pAct = CreateRequiredAction();
		if (pAct)	//if user doesn't cancel
		{
			if (ExecuteAction(pAct))	//if action is not cancelled
				UpdateInterface();
		}
	}
}


void Registrar::UpdateInterface()
{
	pGUI->UpdateInterface();	//update interface items
	pSPlan->DrawMe(pGUI);		//make study plan draw itself
}

Registrar::~Registrar()
{
	delete pGUI;
}

//this function checks if the course is found in course catalog or not
//it takes the input course code from the user and then it compare it with other code courses catalog
CourseInfo* Registrar::getcourseinfo(Course_Code code) {
	
	for (int i = 0; i < RegRules.CourseCatalog.size(); i++) {
		if (RegRules.CourseCatalog[i].Code == code) {
			return &RegRules.CourseCatalog[i];
		}
		else {
			return nullptr;
		}
	}
	return nullptr;
}
CourseInfo* Registrar::checkcourseinfo(Course_Code code) {
	for (int n = 0; n < RegRules.CourseCatalog.size(); n++) {
		if (RegRules.CourseCatalog[n].Code == code) {
			GUI* pGUI = getGUI();
			pGUI->PrintMsg("enter the new course code");
			Course_Code NewCode = pGUI->GetSrting();
			RegRules.CourseCatalog[n].Code = NewCode;
			return &RegRules.CourseCatalog[n];
		}
		else {
			return nullptr;
		}
	}
	return nullptr;
}

/*void Registrar::LoadPlan(ifstream &finput) {
	CourseInfo cinfo = getcourseinfo(code);
	Course* pc = new Course(code, cinfo.Title, cinfo.Credits);
}*/