#include <LCUI.h>
#include <LCDesign.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/builder.h>
#include <LCUI/timer.h>
#include <LCUI/display.h>
#include "ui.h"

int main(int argc, char **argv)
{
	LCUI_Widget root, pack;

	LCUI_Init();
	LCDesign_Init();
	LCUIDisplay_SetSize(1280, 800);
	root = LCUIWidget_GetRoot();
	pack = LCUIBuilder_LoadFile("assets/views/main.xml");
	if (!pack) {
		return -1;
	}
	Logger_SetLevel(LOGGER_LEVEL_ALL);
	Widget_Append(root, pack);
	Widget_Unwrap(pack);
	Widget_SetTitleW(root, L"LC Design - A UI component framework for building LCUI application.");
	Navigation_Init();
	Navbar_Init();
	return LCUI_Main();
}
