/*
 * dismiss.c -- The widget dismissal controller.
 *
 * Copyright (c) 2018, Liu chao <lc-soft@live.cn> All rights reserved.
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
#include <LCDesign/ui/components.h>
#include <LCDesign/ui/dismiss.h>

#define HANDLERS_COUNT 3

typedef struct LCDesign_DismissHandlerRec_ {
	const char *name;
	void(*dismiss)(LCUI_Widget);
} LCDesign_DismissHandlerRec, *LCDesign_DismissHandler;

static struct LCDesign_DismissModule {
	LCDesign_DismissHandlerRec handlers[HANDLERS_COUNT];
} self = {
	{
		{ "modal", Modal_Hide },
{ "alert", Widget_Destroy },
{ "toast", Widget_Destroy }
	}
};

static void OnClick(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	int i;
	const char *name = NULL;
	LCDesign_DismissHandler handler;

	if (e->target) {
		name = Widget_GetAttribute(e->target, "data-dismiss");
	}
	if (!name) {
		return;
	}
	for (i = 0; i < HANDLERS_COUNT; ++i) {
		handler = &self.handlers[i];
		if (strcmp(handler->name, name) != 0) {
			continue;
		}
		for (w = e->target->parent; w; w = w->parent) {
			if (Widget_CheckType(w, handler->name) ||
			    Widget_HasClass(w, handler->name)) {
				handler->dismiss(w);
				break;
			}
		}
		break;
	}
}

void LCDesign_InitDismiss(void)
{
	LCUI_Widget root = LCUIWidget_GetRoot();
	Widget_BindEvent(root, "click", OnClick, NULL, NULL);
}
