/*
 * radio-group.c -- Radio group
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
#include <LCUI/gui/widget.h>
#include <LCDesign/ui/components/radio.h>
#include <LCDesign/ui/components/radio-group.h>

typedef struct RadioGroupRec_ {
	LCUI_Widget checked_radio;
} RadioGroupRec, *RadioGroup;

static struct RadioGroupModule {
	LCUI_WidgetPrototype prototype;
} self;

static void RadioGroup_OnInit(LCUI_Widget w)
{
	RadioGroup data =
	    Widget_AddData(w, self.prototype, sizeof(RadioGroupRec));

	data->checked_radio = NULL;
}

int RadioGroup_SetCheckedRadio(LCUI_Widget w, LCUI_Widget radio)
{
	LCUI_Widget parent;
	RadioGroup data = Widget_GetData(w, self.prototype);

	for (parent = radio->parent; parent; parent = parent->parent) {
		if (parent == w) {
			break;
		}
	}
	if (parent != w) {
		return -1;
	}
	data->checked_radio = radio;
	return 0;
}

int RadioGroup_SetValue(LCUI_Widget w, const char *value)
{
	int found = -1;
	LCUI_Widget child;
	LinkedListNode *node;
	RadioGroup data = Widget_GetData(w, self.prototype);

	data->checked_radio = NULL;
	for (LinkedList_Each(node, &w->children)) {
		child = node->data;
		if (!Widget_CheckType(child, "radio")) {
			continue;
		}
		if (strcmp(value, Widget_GetAttribute(child, "value")) == 0) {
			Radio_SetChecked(child, TRUE);
			data->checked_radio = child;
			found = 0;
		} else {
			Radio_SetChecked(child, FALSE);
		}
	}
	return found;
}

const char *RadioGroup_GetValue(LCUI_Widget w)
{
	RadioGroup data = Widget_GetData(w, self.prototype);

	if (data->checked_radio) {
		return Widget_GetAttribute(data->checked_radio, "value");
	}
	return NULL;
}

void LCDesign_InitRadioGroup(void)
{
	self.prototype = LCUIWidget_NewPrototype("radio-group", NULL);
	self.prototype->init = RadioGroup_OnInit;
}
