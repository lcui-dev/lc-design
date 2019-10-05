/*
 * message.c -- Display global messages as feedback in response to user
 * operations.
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
#include <LCDesign/ui/components/message.h>

#define $NAME "message-notice"

static struct LCDesign_Message {
	LCUI_Widget container;
	LCUI_WidgetPrototype notice_proto;
} self;

typedef struct MessageNoticeRec_ {
	int timer;
	LCUI_Widget icon;
	LCUI_Widget content;
} MessageNoticeRec, *MessageNotice;

static void MessageNotice_OnInit(LCUI_Widget w)
{
	MessageNotice notice;

	notice = Widget_AddData(w, self.notice_proto, sizeof(MessageNoticeRec));
	notice->timer = 0;
	notice->icon = NULL;
	notice->content = LCUIWidget_New("text");

	Widget_AddClass(w, $NAME);
	Widget_AddClass(notice->content, $NAME "-content");
	Widget_Append(w, notice->content);
}

static void MessageNotice_OnDestroy(LCUI_Widget w)
{
	MessageNotice notice;

	notice = Widget_GetData(w, self.notice_proto);
	if (notice->timer) {
		LCUITimer_Free(notice->timer);
	}
}

static void MessageNotice_OnTimeout(void *arg)
{
	LCUI_Widget w = arg;

	if (w->parent && Widget_HasClass(w->parent, $NAME "-wrapper")) {
		Widget_Destroy(w->parent);
	} else {
		Widget_Destroy(w);
	}
}

static void MessageNotice_SetConfig(LCUI_Widget w,
				    LCDesign_MessageConfig config)
{
	MessageNotice notice;

	notice = Widget_GetData(w, self.notice_proto);
	if (notice->icon) {
		Widget_Destroy(notice->icon);
		notice->icon = NULL;
	}
	if (config->icon) {
		Widget_AddClass(config->icon, $NAME "-icon");
		Widget_Prepend(w, config->icon);
	}
	if (notice->timer) {
		LCUITimer_Free(notice->timer);
		notice->timer = 0;
	}
	if (config->duration > 0) {
		notice->timer = LCUI_SetTimeout(config->duration,
						MessageNotice_OnTimeout, w);
	}
	TextView_SetTextW(notice->content, config->content);
}

void LCDesign_SetMessageContainer(LCUI_Widget w)
{
	self.container = w;
}

LCUI_Widget LCDesign_OpenMessage(LCDesign_MessageConfig config)
{
	LCUI_Widget wrapper;
	LCUI_Widget message;

	if (!self.container) {
		self.container = LCUIWidget_New(NULL);
		Widget_AddClass(self.container, $NAME "-container");
		Widget_Append(LCUIWidget_GetRoot(), self.container);
	}
	wrapper = LCUIWidget_New(NULL);
	message = LCUIWidget_New($NAME);
	MessageNotice_SetConfig(message, config);
	Widget_AddClass(wrapper, $NAME "-wrapper");
	Widget_Append(wrapper, message);
	Widget_Append(self.container, wrapper);
	return message;
}

void LCDesign_CloseMessage(LCUI_Widget message)
{
	Widget_Destroy(message);
}

LCUI_Widget LCDesign_OpenSuccessMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "check-circle");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, $NAME "-success");
	return message;
}

LCUI_Widget LCDesign_OpenInfoMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "information");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, $NAME "-info");
	return message;
}

LCUI_Widget LCDesign_OpenWarningMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "alert-circle");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, $NAME "-warning");
	return message;
}

LCUI_Widget LCDesign_OpenErrorMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "close-circle");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, $NAME "-error");
	return message;
}

LCUI_Widget LCDesign_OpenLoadingMessage(const wchar_t *content, long duration)
{
	LCUI_Widget icon;
	LCUI_Widget message;
	LCDesign_MessageConfigRec config;

	icon = LCUIWidget_New("spinner");
	Widget_SetAttribute(icon, "type", "ring");

	config.icon = icon;
	config.content = content;
	config.duration = duration;
	message = LCDesign_OpenMessage(&config);
	Widget_AddClass(message, $NAME "-loading");
	return message;
}

void LCDesign_InitMessage(void)
{
	self.notice_proto = LCUIWidget_NewPrototype($NAME, NULL);
	self.notice_proto->init = MessageNotice_OnInit;
	self.notice_proto->destroy = MessageNotice_OnDestroy;
}
