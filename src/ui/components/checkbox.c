/*
 * checkbox.c -- Checkbox, used to make multiple selections in a set of
 * options, or mark the status of an option.
 *
 * Copyright (c) 2019, Liu chao <lc-soft@live.cn> All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of LCUI nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <LCUI.h>
#include <LCUI/timer.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textview.h>
#include <LCDesign/ui/components/icon.h>
#include <LCDesign/ui/components/checkbox.h>

typedef struct CheckBoxRec_ {
	LCUI_Widget inner;
	LCUI_Widget content;
	LCUI_BOOL checked;
} CheckBoxRec, *CheckBox;

static struct CheckBoxModule {
	LCUI_WidgetPrototype prototype;
} self;

static void CheckBox_OnClick(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCUI_WidgetEventRec ev;
	CheckBox data = Widget_GetData(w, self.prototype);

	if (w->disabled) {
		return;
	}
	CheckBox_SetChecked(w, !data->checked);
	LCUI_InitWidgetEvent(&ev, "change");
	ev.cancel_bubble = TRUE;
	Widget_TriggerEvent(w, &ev, NULL);
}

static void CheckBox_OnInit(LCUI_Widget w)
{
	LCUI_Widget icon;
	CheckBox data = Widget_AddData(w, self.prototype, sizeof(CheckBoxRec));

	data->checked = FALSE;
	data->content = NULL;
	data->inner = LCUIWidget_New(NULL);
	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "check");
	Widget_AddClass(w, "checkbox");
	Widget_AddClass(icon, "checkbox-inner-icon");
	Widget_AddClass(data->inner, "checkbox-inner");
	Widget_Append(data->inner, icon);
	Widget_Append(w, data->inner);
	Widget_BindEvent(w, "click", CheckBox_OnClick, NULL, NULL);
}

static CheckBox_OnSetText(LCUI_Widget w, const char *text)
{
	CheckBox data = Widget_GetData(w, self.prototype);

	if (!data->content) {
		data->content = LCUIWidget_New("span");
		Widget_AddClass(data->content, "checkbox-text");
		Widget_Append(w, data->content);
	}
	TextView_SetText(data->content, text);
}

static void CheckBox_OnSetAttribute(LCUI_Widget w, const char *name,
				  const char *value)
{
	if (strcmp(name, "checked") == 0) {
		CheckBox_SetChecked(w, strcmp(value, "checked") == 0);
	}
}

LCUI_BOOL CheckBox_IsChecked(LCUI_Widget w)
{
	CheckBox data = Widget_GetData(w, self.prototype);

	return data->checked;
}

void CheckBox_SetChecked(LCUI_Widget w, LCUI_BOOL checked)
{
	CheckBox data = Widget_GetData(w, self.prototype);

	data->checked = checked;
	if (data->checked) {
		Widget_AddClass(w, "checked");
	} else {
		Widget_RemoveClass(w, "checked");
	}
}

void LCDesign_InitCheckBox(void)
{
	self.prototype = LCUIWidget_NewPrototype("checkbox", NULL);
	self.prototype->init = CheckBox_OnInit;
	self.prototype->settext = CheckBox_OnSetText;
	self.prototype->setattr = CheckBox_OnSetAttribute;
}
