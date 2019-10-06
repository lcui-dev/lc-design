/*
 * switch.c -- Switch, used to represent the switching between two states or
 * on-off state.
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
#include <LCDesign/ui/components/icon.h>
#include <LCDesign/ui/components/switch.h>

typedef struct SwitchRec_ {
	char *checked_text;
	char *checked_icon;
	char *unchecked_text;
	char *unchecked_icon;
	LCUI_Widget content;
	LCUI_Widget inner;
	LCUI_Widget txt_off;
	LCUI_Widget txt_on;
	LCUI_Widget slider;
	LCUI_Widget bar;
	LCUI_BOOL checked;
} SwitchRec, *Switch;

static struct SwitchModule {
	LCUI_WidgetPrototype prototype;
} self;

static void Switch_OnClick(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	LCUI_WidgetEventRec ev;
	Switch data = Widget_GetData(w, self.prototype);

	if (w->disabled) {
		return;
	}
	Switch_SetChecked(w, !data->checked);
	LCUI_InitWidgetEvent(&ev, "change");
	ev.cancel_bubble = TRUE;
	Widget_TriggerEvent(w, &ev, NULL);
}

static void Switch_ResetChildren(LCUI_Widget w)
{
	Switch data = Widget_GetData(w, self.prototype);

	if (data->txt_off) {
		Widget_Destroy(data->txt_off);
		data->txt_off = NULL;
	}
	if (data->txt_on) {
		Widget_Destroy(data->txt_on);
		data->txt_on = NULL;
	}
	if (data->checked_icon) {
		data->txt_on = LCUIWidget_New("icon");
		Icon_SetName(data->txt_on, data->checked_icon);
	} else {
		data->txt_on = LCUIWidget_New("textview");
		if (data->checked_text) {
			TextView_SetText(data->txt_on, data->checked_text);
		}
	}
	if (data->unchecked_icon) {
		data->txt_off = LCUIWidget_New("icon");
		Icon_SetName(data->txt_off, data->unchecked_icon);
	} else {
		data->txt_off = LCUIWidget_New("textview");
		if (data->unchecked_text) {
			TextView_SetText(data->txt_off, data->unchecked_text);
		}
	}
	Widget_AddClass(data->txt_on, "switch-inner-on-block");
	Widget_AddClass(data->txt_off, "switch-inner-off-block");
	Widget_Append(data->bar, data->txt_on);
	Widget_Append(data->bar, data->slider);
	Widget_Append(data->bar, data->txt_off);
}

static void Switch_OnInit(LCUI_Widget w)
{
	const size_t data_size = sizeof(SwitchRec);
	Switch data = Widget_AddData(w, self.prototype, data_size);

	data->checked = FALSE;
	data->content = NULL;
	data->inner = LCUIWidget_New(NULL);
	data->bar = LCUIWidget_New(NULL);
	data->slider = LCUIWidget_New(NULL);
	data->checked_text = NULL;
	data->checked_icon = NULL;
	data->unchecked_text = NULL;
	data->unchecked_icon = NULL;
	data->txt_off = NULL;
	data->txt_on = NULL;
	Widget_AddClass(w, "switch");
	Widget_AddClass(data->inner, "switch-inner");
	Widget_AddClass(data->bar, "switch-inner-bar");
	Widget_AddClass(data->slider, "switch-inner-slider");
	Widget_Append(data->inner, data->bar);
	Widget_Append(w, data->inner);
	Widget_BindEvent(w, "click", Switch_OnClick, NULL, NULL);
	Switch_ResetChildren(w);
}

static void Switch_OnSetAttribute(LCUI_Widget w, const char *name,
				  const char *value)
{
	if (strcmp(name, "checked-icon") == 0) {
		Switch_SetCheckedIcon(w, value);
	} else if (strcmp(name, "unchecked-icon") == 0) {
		Switch_SetUncheckedIcon(w, value);
	} else if (strcmp(name, "checked-text") == 0) {
		Switch_SetCheckedText(w, value);
	} else if (strcmp(name, "unchecked-text") == 0) {
		Switch_SetUncheckedText(w, value);
	} else if (strcmp(name, "checked") == 0) {
		Switch_SetChecked(w, strcmp(value, "checked") == 0);
	}
}

LCUI_BOOL Switch_IsChecked(LCUI_Widget w)
{
	Switch data = Widget_GetData(w, self.prototype);

	return data->checked;
}

void Switch_SetChecked(LCUI_Widget w, LCUI_BOOL checked)
{
	Switch data = Widget_GetData(w, self.prototype);

	data->checked = checked;
	if (data->checked) {
		Widget_AddClass(w, "checked");
	} else {
		Widget_RemoveClass(w, "checked");
	}
}

void Switch_SetCheckedText(LCUI_Widget w, const char *text)
{
	Switch data = Widget_GetData(w, self.prototype);

	if (data->checked_text) {
		free(data->checked_text);
		data->checked_text = NULL;
	}
	if (text) {
		data->checked_text = strdup2(text);
		if (data->checked_icon) {
			free(data->checked_icon);
			data->checked_icon = NULL;
		}
	}
	Switch_ResetChildren(w);
}

void Switch_SetUncheckedText(LCUI_Widget w, const char *text)
{
	Switch data = Widget_GetData(w, self.prototype);

	if (data->unchecked_text) {
		free(data->unchecked_text);
		data->unchecked_text = NULL;
	}
	if (text) {
		data->unchecked_text = strdup2(text);
		if (data->unchecked_icon) {
			free(data->unchecked_icon);
			data->unchecked_icon = NULL;
		}
	}
	Switch_ResetChildren(w);
}

void Switch_SetCheckedIcon(LCUI_Widget w, const char *icon_name)
{
	Switch data = Widget_GetData(w, self.prototype);

	if (data->checked_icon) {
		free(data->checked_icon);
		data->checked_text = NULL;
	}
	if (icon_name) {
		data->checked_icon = strdup2(icon_name);
		if (data->checked_text) {
			free(data->checked_text);
			data->checked_text = NULL;
		}
	}
	Switch_ResetChildren(w);
}

void Switch_SetUncheckedIcon(LCUI_Widget w, const char *icon_name)
{
	Switch data = Widget_GetData(w, self.prototype);

	if (data->unchecked_icon) {
		free(data->unchecked_icon);
		data->unchecked_icon = NULL;
	}
	if (icon_name) {
		data->unchecked_icon = strdup2(icon_name);
		if (data->unchecked_text) {
			free(data->unchecked_text);
			data->unchecked_text = NULL;
		}
	}
	Switch_ResetChildren(w);
}

static void Switch_OnSetText(LCUI_Widget w, const char *text)
{
	Switch data = Widget_GetData(w, self.prototype);

	if (!data->content) {
		data->content = LCUIWidget_New("span");
		Widget_AddClass(data->content, "switch-text");
		Widget_Append(w, data->content);
	}
	TextView_SetText(data->content, text);
}

void LCDesign_InitSwitch(void)
{
	self.prototype = LCUIWidget_NewPrototype("switch", NULL);
	self.prototype->setattr = Switch_OnSetAttribute;
	self.prototype->settext = Switch_OnSetText;
	self.prototype->init = Switch_OnInit;
}
