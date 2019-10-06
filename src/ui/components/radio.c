/*
 * radio.c -- Radio, used to select one of a set of options.
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
#include <LCDesign/build.h>
#include <LCDesign/ui/components/radio.h>
#include <LCDesign/ui/components/radio-group.h>

typedef struct RadioRec_ {
	LCUI_Widget inner;
	LCUI_Widget content;
	LCUI_BOOL checked;
} RadioRec, *Radio;

static struct RadioModule {
	LCUI_WidgetPrototype prototype;
} self;

static void Radio_OnClick(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCUI_WidgetEventRec ev;
	Radio data = Widget_GetData(w, self.prototype);

	if (w->disabled || data->checked) {
		return;
	}
	if (w->parent && Widget_CheckType(w->parent, "radio-group")) {
		RadioGroup_SetValue(w->parent, Widget_GetAttribute(w, "value"));
	} else {
		Radio_SetChecked(w, TRUE);
	}
	LCUI_InitWidgetEvent(&ev, "change");
	ev.cancel_bubble = TRUE;
	Widget_TriggerEvent(w, &ev, NULL);
}

static void Radio_OnInit(LCUI_Widget w)
{
	LCUI_Widget icon;
	Radio data = Widget_AddData(w, self.prototype, sizeof(RadioRec));

	data->checked = FALSE;
	data->content = NULL;
	data->inner = LCUIWidget_New(NULL);
	icon = LCUIWidget_New(NULL);
	Widget_AddClass(w, "radio");
	Widget_AddClass(icon, "radio-inner-icon");
	Widget_AddClass(data->inner, "radio-inner");
	Widget_Append(data->inner, icon);
	Widget_Append(w, data->inner);
	Widget_BindEvent(w, "click", Radio_OnClick, NULL, NULL);
}

static void Radio_OnSetText(LCUI_Widget w, const char *text)
{
	Radio data = Widget_GetData(w, self.prototype);

	if (!data->content) {
		data->content = LCUIWidget_New("span");
		Widget_AddClass(data->content, "radio-text");
		Widget_Append(w, data->content);
	}
	TextView_SetText(data->content, text);
}

static void Radio_OnSetAttribute(LCUI_Widget w, const char *name,
				 const char *value)
{
	if (strcmp(name, "checked") == 0) {
		Radio_SetChecked(w, strcmp(value, "checked") == 0);
	}
}

LCUI_BOOL Radio_IsChecked(LCUI_Widget w)
{
	Radio data = Widget_GetData(w, self.prototype);

	return data->checked;
}

void Radio_SetChecked(LCUI_Widget w, LCUI_BOOL checked)
{
	Radio data = Widget_GetData(w, self.prototype);

	data->checked = checked;
	if (data->checked) {
		Widget_AddClass(w, "checked");
	} else {
		Widget_RemoveClass(w, "checked");
	}
}

void LCDesign_InitRadio(void)
{
	self.prototype = LCUIWidget_NewPrototype("radio", NULL);
	self.prototype->init = Radio_OnInit;
	self.prototype->settext = Radio_OnSetText;
	self.prototype->setattr = Radio_OnSetAttribute;
}
