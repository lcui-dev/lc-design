#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/builder.h>
#include <LCUI/timer.h>
#include <LCUIEx.h>
#include "ui.h"

int main(int argc, char **argv)
{
	LCUI_Widget root, pack;

	LCUI_Init();
	LCUIEx_Init();
	root = LCUIWidget_GetRoot();
	pack = LCUIBuilder_LoadFile("assets/views/main.xml");
	if (!pack) {
		return -1;
	}
	Widget_Append(root, pack);
	Widget_Unwrap(pack);
	Widget_SetTitleW(root, L"LCUI.css - A UI component framework for building LCUI application.");
	Navigation_Init();
	Navbar_Init();
	return LCUI_Main();
}
