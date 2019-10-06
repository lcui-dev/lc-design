/*
* rate.c -- Rate component.
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

#include <stdio.h>
#include <LCUI.h>
#include <LCUI/font.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textview.h>
#include <LCDesign/build.h>
#include <LCDesign/ui/components/rate.h>
#include <LCDesign/ui/components/icon.h>

/* clang-format off */

static struct {
	LCUI_WidgetPrototype proto;
} rate_module;

typedef struct RateRec_ {
	unsigned int value;
	unsigned int count;
	wchar_t character;
	const char *icon;
	const char *void_icon;
} RateRec, *Rate;

/* clang-format on */

static void Rate_Update(LCUI_Widget w, unsigned value)
{
	LCUI_Widget child;
	LinkedListNode *node;
	Rate rate = Widget_GetData(w, rate_module.proto);

	for (LinkedList_Each(node, &w->children)) {
		child = node->data;
		if (child->index >= value) {
			break;
		}
		if (!rate->character) {
			Icon_SetName(child, rate->icon);
		}
		Widget_RemoveClass(child, "rate-star-void");
	}
	for (; node; node = node->next) {
		child = node->data;
		if (!rate->character) {
			Icon_SetName(child, rate->void_icon);
		}
		Widget_AddClass(child, "rate-star-void");
	}
}

static void Rate_ResetChildren(LCUI_Widget w)
{
	unsigned i;
	wchar_t text[2];
	LCUI_Widget child;
	Rate rate = Widget_GetData(w, rate_module.proto);

	Widget_Empty(w);
	for (i = 0; i < rate->count; ++i) {
		if (rate->character) {
			text[0] = rate->character;
			text[1] = 0;
			child = LCUIWidget_New("span");
			TextView_SetTextW(child, text);

		} else {
			child = LCUIWidget_New("icon");
			Icon_SetName(child, rate->void_icon);
		}
		Widget_Append(w, child);
	}
	Rate_Update(w, rate->value);
}

static unsigned Rate_GetValueByEvent(LCUI_Widget w, LCUI_WidgetEvent e)
{
	float x, y;
	LCUI_Widget child;
	LCUI_Widget target = NULL;
	LinkedListNode *node;

	Widget_GetOffset(w, NULL, &x, &y);
	x = 1.0f * e->motion.x - x;
	y = 1.0f * e->motion.y - y;
	for (LinkedList_Each(node, &w->children)) {
		child = node->data;
		if (child->x <= x) {
			target = child;
		}
	}
	if (!target) {
		return 0;
	}
	return (unsigned)(target->index + 1);
}

static void Rate_OnMouseMove(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	Rate rate = Widget_GetData(w, rate_module.proto);

	if (w->disabled) {
		return;
	}
	Rate_Update(w, min(rate->count, Rate_GetValueByEvent(w, e)));
}

static void Rate_OnMouseDown(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	Rate rate = Widget_GetData(w, rate_module.proto);

	if (w->disabled) {
		return;
	}
	Rate_SetValue(w, Rate_GetValueByEvent(w, e));
}

static void Rate_OnMouseOut(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	Rate rate = Widget_GetData(w, rate_module.proto);

	if (e->target != w || w->disabled) {
		return;
	}
	Rate_Update(w, rate->value);
}

static void Rate_OnInit(LCUI_Widget w)
{
	Rate rate = Widget_AddData(w, rate_module.proto, sizeof(RateRec));

	rate->value = 0;
	rate->count = 5;
	rate->character = 0;
	rate->icon = "star";
	rate->void_icon = "star-outline";
	Widget_BindEvent(w, "mousemove", Rate_OnMouseMove, NULL, NULL);
	Widget_BindEvent(w, "mousedown", Rate_OnMouseDown, NULL, NULL);
	Widget_BindEvent(w, "mouseout", Rate_OnMouseOut, NULL, NULL);
	Rate_ResetChildren(w);
	Rate_Update(w, rate->value);
}

void Rate_SetValue(LCUI_Widget w, unsigned value)
{
	Rate rate = Widget_GetData(w, rate_module.proto);
	LCUI_WidgetEventRec e;

	rate->value = value;
	Rate_Update(w, value);
	LCUI_InitWidgetEvent(&e, "change");
	Widget_TriggerEvent(w, &e, NULL);
}

unsigned Rate_GetValue(LCUI_Widget w)
{
	Rate rate = Widget_GetData(w, rate_module.proto);

	return rate->value;
}

void Rate_SetCount(LCUI_Widget w, unsigned count)
{
	Rate rate = Widget_GetData(w, rate_module.proto);

	rate->count = count;
	rate->value = min(rate->value, rate->count);
	Rate_ResetChildren(w);
}

void Rate_SetIcon(LCUI_Widget w, const char *void_icon, const char *icon)
{
	Rate rate = Widget_GetData(w, rate_module.proto);

	if (!icon) {
		icon = void_icon;
	}
	if (!void_icon) {
		return;
	}
	rate->character = 0;
	rate->icon = icon;
	rate->void_icon = void_icon;
	Rate_ResetChildren(w);
}

void Rate_SetCharacter(LCUI_Widget w, const wchar_t ch)
{
	Rate rate = Widget_GetData(w, rate_module.proto);

	rate->character = ch;
	Rate_ResetChildren(w);
}

static void Rate_OnSetAttribute(LCUI_Widget w, const char *name,
				const char *value)
{
	wchar_t str[4];
	unsigned count;
	Rate rate = Widget_GetData(w, rate_module.proto);

	if (strcmp(name, "character") == 0) {
		LCUI_DecodeUTF8String(str, value, 4);
		rate->character = str[0];
		Rate_ResetChildren(w);
	} else if (strcmp(name, "icon") == 0) {
		rate->icon = value;
		rate->character = 0;
		Rate_ResetChildren(w);
	} else if (strcmp(name, "void-icon") == 0) {
		rate->void_icon = value;
		rate->character = 0;
		Rate_ResetChildren(w);
	} else if (strcmp(name, "count") == 0) {
		sscanf(value, "%u", &count);
		Rate_SetCount(w, count);
	} else if (strcmp(name, "value") == 0) {
		sscanf(value, "%u", &count);
		Rate_SetValue(w, count);
	}
}

void LCDesign_InitRate(void)
{
	rate_module.proto = LCUIWidget_NewPrototype("rate", NULL);
	rate_module.proto->init = Rate_OnInit;
	rate_module.proto->setattr = Rate_OnSetAttribute;
}
