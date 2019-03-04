#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/display.h>
#include <LCUI/gui/widget.h>
#include "ui.h"

void ActiveLink(LCUI_Widget parent, const char *link_id)
{
	LCUI_Widget link;
	LCUI_WidgetEventRec ev = { 0 };

	if (!link_id) {
		return;
	}
	link = LCUIWidget_GetById(link_id);
	if (!link) {
		return;
	}
	ev.type = LCUI_WEVENT_CLICK;
	ev.button.button = 1;
	Widget_TriggerEvent(link, &ev, NULL);
}
