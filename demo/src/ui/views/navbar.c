#include <stdio.h>
#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/display.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textview.h>
#include "ui.h"

#define BTN_CHANGE_SCALE	"btn-change-global-scale"
#define DROPDOWN_SCALE		"dropdown-global-scale"

static void OnChangeScale(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	float scale;
	char txt_scale[64];
	LCUI_Widget text, btn = e->data;
	const char *value = Widget_GetAttribute(e->target, "value");

	if (!value || sscanf(value, "%f", &scale) != 1) {
		return;
	}
	text = Widget_GetChild(btn, 0);
	if (scale >= 1.0f && scale <= 2.0f) {
		LCUIMetrics_SetScale(scale);
		sprintf(txt_scale, "%g%%", scale * 100);
		TextView_SetText(text, txt_scale);
		LCUIWidget_RefreshStyle();
	}
}

void Navbar_Init(void)
{
	LCUI_Widget dropdown, btn;

	btn = LCUIWidget_GetById(BTN_CHANGE_SCALE);
	dropdown = LCUIWidget_GetById(DROPDOWN_SCALE);
	Widget_BindEvent(dropdown, "change.dropdown", OnChangeScale, btn, NULL);;
}
