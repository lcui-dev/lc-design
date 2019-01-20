/*
 * icon.c -- Icon component.
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
#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include <LCUI/gui/widget.h>

#define CLASS_NAME		"icon"
#define CLASS_PREFIX_NAME	"icon-"

typedef struct IconRec_ {
	char class_name[256];
} IconRec, *Icon;

static struct LCUIEx_IconModule {
	LCUI_WidgetPrototype proto;
} self;

static void Icon_Init(LCUI_Widget w)
{
	Icon that = Widget_AddData(w, self.proto, sizeof(IconRec));

	that->class_name[0] = 0;
	self.proto->proto->init(w);
	Widget_AddClass(w, CLASS_NAME);
}

int Icon_SetName(LCUI_Widget w, const char *name)
{
	Icon that = Widget_GetData(w, self.proto);

	if (strlen(that->class_name) > 0) {
		Widget_RemoveClass(w, that->class_name);
	}
	strcpy(that->class_name, CLASS_PREFIX_NAME);
	strcat(that->class_name, name);
	return Widget_AddClass(w, that->class_name);
}

static void Icon_SetAttr(LCUI_Widget w, const char *name,
			 const char *value)
{
	if (strcmp(name, "name") == 0) {
		Icon_SetName(w, value);
	}
}

void LCUIEx_InitIcon(void)
{
	self.proto = LCUIWidget_NewPrototype("icon", "textview");
	self.proto->init = Icon_Init;
	self.proto->setattr = Icon_SetAttr;
}
