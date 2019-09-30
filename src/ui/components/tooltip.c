/*
 * tooltip.c -- tooltip
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

#include <math.h>
#include <LCUI.h>
#include <LCUI/timer.h>
#include <LCUI/gui/widget.h>
#include <LCUI/gui/widget/textview.h>
#include <LCDesign/ui/components/tooltip.h>

typedef enum TooltipPlacement {
	PLACEMENT_TOP,
	PLACEMENT_RIGHT,
	PLACEMENT_BOTTOM,
	PLACEMENT_LEFT
} TooltipPlacement;

static struct {
	LCUI_WidgetPrototype proto;
	LinkedList tooltips;
} tooltip_module;

typedef struct TooltipRec_ {
	LCUI_Widget target;
	LCUI_Widget content;
	LCUI_Widget arrow;
	LCUI_BOOL visible;
	LinkedListNode node;
	TooltipPlacement placement;
	int delay;
	int timer_show;
	int timer_hide;
} TooltipRec, *Tooltip;

static void Tooltip_UpdatePlacement(LCUI_Widget w)
{
	float left, top;
	const char *placement;
	Tooltip tooltip = Widget_GetData(w, tooltip_module.proto);

	switch (tooltip->placement) {
	case PLACEMENT_TOP:
		Widget_RemoveClass(w, "tooltip-top");
		break;
	case PLACEMENT_RIGHT:
		Widget_RemoveClass(w, "tooltip-right");
		break;
	case PLACEMENT_BOTTOM:
		Widget_RemoveClass(w, "tooltip-bottom");
		break;
	case PLACEMENT_LEFT:
		Widget_RemoveClass(w, "tooltip-left");
		break;
	}
	placement = Widget_GetAttribute(tooltip->target, "data-placement");
	if (!placement || strcmp(placement, "top") == 0) {
		Widget_AddClass(w, "tooltip-top");
		tooltip->placement = PLACEMENT_TOP;
	} else if (strcmp(placement, "right") == 0) {
		Widget_AddClass(w, "tooltip-right");
		tooltip->placement = PLACEMENT_RIGHT;
	} else if (strcmp(placement, "bottom") == 0) {
		Widget_AddClass(w, "tooltip-bottom");
		tooltip->placement = PLACEMENT_BOTTOM;
	} else if (strcmp(placement, "left") == 0) {
		Widget_AddClass(w, "tooltip-left");
		tooltip->placement = PLACEMENT_LEFT;
	}
	Widget_GetOffset(tooltip->target, NULL, &left, &top);
	switch (tooltip->placement) {
	case PLACEMENT_TOP:
		top -= w->height;
		left -= (w->width - tooltip->target->width) / 2;
		break;
	case PLACEMENT_RIGHT:
		left += tooltip->target->width;
		top -= (w->height - tooltip->target->height) / 2;
		break;
	case PLACEMENT_BOTTOM:
		top += tooltip->target->height;
		left -= (w->width - tooltip->target->width) / 2;
		break;
	case PLACEMENT_LEFT:
		top -= (w->height - tooltip->target->height) / 2;
		left -= w->width;
		break;
	}
	Widget_Move(w, left, top);
}

static void Tooltip_OnInit(LCUI_Widget w)
{
	Tooltip tooltip =
	    Widget_AddData(w, tooltip_module.proto, sizeof(TooltipRec));

	tooltip->target = NULL;
	tooltip->delay = 100;
	tooltip->visible = FALSE;
	tooltip->node.data = w;
	tooltip->timer_hide = 0;
	tooltip->timer_show = 0;
	tooltip->node.next = tooltip->node.prev = NULL;
	tooltip->content = LCUIWidget_New("textview");
	tooltip->arrow = LCUIWidget_New(NULL);
	tooltip->placement = PLACEMENT_TOP;
	Widget_AddClass(tooltip->arrow, "tooltip-arrow");
	Widget_AddClass(tooltip->content, "tooltip-inner");
	Widget_Append(w, tooltip->content);
	Widget_Append(w, tooltip->arrow);
	Widget_AddClass(w, "tooltip");
	LinkedList_AppendNode(&tooltip_module.tooltips, &tooltip->node);
}

static void OnTargetDestroy(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	Tooltip tooltip;

	tooltip = Widget_GetData(e->data, tooltip_module.proto);
	tooltip->target= NULL;
}

static void Tooltip_OnDestroy(LCUI_Widget w)
{
	Tooltip tooltip = Widget_GetData(w, tooltip_module.proto);

	if (tooltip->timer_hide) {
		LCUITimer_Free(tooltip->timer_hide);
		tooltip->timer_hide = 0;
	}
	if (tooltip->timer_show) {
		LCUITimer_Free(tooltip->timer_show);
		tooltip->timer_show = 0;
	}
	if (tooltip->target) {
		Widget_UnbindEvent(tooltip->target, "destroy", OnTargetDestroy);
	}
	LinkedList_Unlink(&tooltip_module.tooltips, &tooltip->node);
}

static void Tooltip_Show(LCUI_Widget w, LCUI_Widget target)
{
	Tooltip tooltip = Widget_GetData(w, tooltip_module.proto);

	tooltip->visible = TRUE;
	tooltip->timer_show = 0;
	Widget_AddClass(w, "show");
	Widget_Show(w);
	Tooltip_UpdatePlacement(w);
}

static void Tooltip_SetContent(LCUI_Widget w, const char *str)
{
	Tooltip tooltip = Widget_GetData(w, tooltip_module.proto);

	TextView_SetText(tooltip->content, str);
}

static void Tooltip_Hide(LCUI_Widget w)
{
	Tooltip tooltip = Widget_GetData(w, tooltip_module.proto);

	tooltip->visible = FALSE;
	tooltip->timer_hide = 0;
	Widget_RemoveClass(w, "show");
	Widget_Hide(w);
}

static void Tooltip_DelayShow(LCUI_Widget w)
{
	Tooltip tooltip;

	tooltip = Widget_GetData(w, tooltip_module.proto);
	if (tooltip->timer_hide) {
		LCUITimer_Free(tooltip->timer_hide);
		tooltip->timer_hide = 0;
	}
	if (tooltip->timer_show) {
		return;
	}
	tooltip->timer_show =
	    LCUI_SetTimeout(tooltip->delay, (TimerCallback)Tooltip_Show, w);
}

static void Tooltip_DelayHide(LCUI_Widget w)
{
	Tooltip tooltip;

	tooltip = Widget_GetData(w, tooltip_module.proto);
	if (tooltip->timer_show) {
		LCUITimer_Free(tooltip->timer_show);
		tooltip->timer_show = 0;
	}
	if (tooltip->timer_hide) {
		return;
	}
	tooltip->timer_hide =
	    LCUI_SetTimeout(tooltip->delay, (TimerCallback)Tooltip_Hide, w);
}

static void OnTargetMouseOut(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	Tooltip tooltip;

	tooltip = Widget_GetData(e->data, tooltip_module.proto);
	Tooltip_DelayHide(e->data);
}

static void OnTooltipReady(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	Tooltip_UpdatePlacement(w);
	Widget_UnbindEvent(w, "ready", OnTooltipReady);
}

static LCUI_Widget SetupTooltip(LCUI_Widget target)
{
	Tooltip tooltip;
	LinkedListNode *node;
	LCUI_Widget w = NULL;
	const char *title;

	title = Widget_GetAttribute(target, "title");
	if (!title) {
		return NULL;
	}
	for (LinkedList_Each(node, &tooltip_module.tooltips)) {
		tooltip = Widget_GetData(node->data, tooltip_module.proto);
		if (tooltip->target == target) {
			w = node->data;
			break;
		}
	}
	if (!w) {
		w = LCUIWidget_New("tooltip");
		Widget_Append(LCUIWidget_GetRoot(), w);
		Widget_BindEvent(w, "ready", OnTooltipReady, NULL, NULL);
		Widget_BindEvent(target, "mouseout", OnTargetMouseOut, w, NULL);
		Widget_BindEvent(target, "destroy", OnTargetDestroy, w, NULL);
	}
	tooltip = Widget_GetData(w, tooltip_module.proto);
	tooltip->target = target;
	Tooltip_SetContent(w, title);
	return w;
}

static void OnFocus(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
}

static void OnMouseMove(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	const char *value = Widget_GetAttribute(e->target, "data-toggle");

	if (!value || strcmp(value, "tooltip") != 0) {
		return;
	}
	w = SetupTooltip(e->target);
	if (!w) {
		return;
	}
	Tooltip_DelayShow(w);
}

void LCDesign_InitTooltip(void)
{
	LCUI_Widget root = LCUIWidget_GetRoot();

	LinkedList_Init(&tooltip_module.tooltips);
	tooltip_module.proto = LCUIWidget_NewPrototype("tooltip", NULL);
	tooltip_module.proto->init = Tooltip_OnInit;
	tooltip_module.proto->destroy = Tooltip_OnDestroy;
	Widget_BindEvent(root, "focus", OnFocus, NULL, NULL);
	Widget_BindEvent(root, "mousemove", OnMouseMove, NULL, NULL);
}
