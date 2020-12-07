#include "ActionChangeCourseCode.h"

ActionChangeCourseCode::ActionChangeCourseCode(Registrar* p) :Action(p)
{
}

bool ActionChangeCourseCode::Execute() {
	GUI* pGUI = pReg->getGUI();
	pGUI->PrintMsg("press on the course ypo want to change");
	ActionData actData = pGUI->GetUserAction();
	double x_point, y_point;
	if (actData.actType == DRAW_AREA) {
		//get coord where user clicked
		x_point = actData.x;
		y_point = actData.y;
		StudyPlan* pS = pReg->getStudyPlay();
		double* point = pS->DeleteCourse(x_point, y_point);
		pGUI->PrintMsg("Enter the new course Code(e.g. CIE202)");
		Course_Code code = pGUI->GetSrting();   // add input validation
		CourseInfo* cinfo;
		cinfo = pReg->getcourseinfo(code);
		ActionData actData = pGUI->GetUserAction("click on year you want to add the new course to");
		int x, y;
		if (actData.actType == DRAW_AREA)	//user clicked inside drawing area
		{
			//get coord where user clicked
			x = actData.x;
			y = actData.y;
			graphicsInfo gInfo{ x, y };
			string Title = cinfo->Title;
			int crd = cinfo->Credits;
			Course* pC = new Course(code, Title, crd);
			pC->setGfxInfo(gInfo);
			StudyPlan* pS = pReg->getStudyPlay();
			pS->AddCourse(pC, 1, FALL);
		}
	}
    return true;
}

ActionChangeCourseCode::~ActionChangeCourseCode()
{
}
