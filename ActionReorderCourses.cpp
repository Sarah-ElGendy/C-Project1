#include "ActionReorderCourses.h"
#include "Actions\Action.h"
#include "Registrar.h"
#include <string>

ActionReorderCourses::ActionReorderCourses(Registrar* p) :Action(p)
{
}
bool ActionReorderCourses::Execute() {
	GUI* pGUI = pReg->getGUI();
	pGUI->PrintMsg("Press on the course you want to re-order");
	ActionData actData = pGUI->GetUserAction();
	double x_point, y_point;
	if (actData.actType == DRAW_AREA) {
		//get coord where user clicked
		x_point = actData.x;
		y_point = actData.y;
	}
	return true;
}