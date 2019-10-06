/*
 * notification.c -- Display a notification message globally.
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
#include <LCDesign/ui/components/notification.h>

#define $NAME "notification-notice"
#define $CONTAINER

typedef struct NotificationNoticeRec_ {
	int timer;
	LCUI_Widget icon;
	LCUI_Widget title;
	LCUI_Widget description;
} NotificationNoticeRec, *NotificationNotice;

struct LCDesign_Notification {
	LCUI_Widget top_left_container;
	LCUI_Widget top_right_container;
	LCUI_Widget bottom_left_container;
	LCUI_Widget bottom_right_container;
	LCUI_Widget custom_container;
	LCUI_WidgetPrototype notice_proto;
} self;

static void OnClickCloseButton(LCUI_Widget w, LCUI_WidgetEvent e, void *arg)
{
	Widget_Destroy(e->data);
}

static void NotificationNotice_OnInit(LCUI_Widget w)
{
	LCUI_Widget close;
	LCUI_Widget content;
	NotificationNotice notice;

	Widget_AddData(w, self.notice_proto, sizeof(NotificationNoticeRec));
	notice = Widget_GetData(w, self.notice_proto);
	notice->timer = 0;

	content = LCUIWidget_New(NULL);
	close = LCUIWidget_New("icon");
	notice->icon = 0;
	notice->timer = 0;
	notice->title = LCUIWidget_New("text");
	notice->description = LCUIWidget_New("text");
	Icon_SetName(close, "close");
	Widget_AddClass(w, $NAME);
	Widget_AddClass(close, $NAME "-close");
	Widget_AddClass(notice->title, $NAME "-title");
	Widget_AddClass(notice->description, $NAME "-description");
	Widget_AddClass(content, $NAME "-content");
	Widget_BindEvent(close, "click", OnClickCloseButton, w, NULL);
	Widget_Append(content, notice->title);
	Widget_Append(content, notice->description);
	Widget_Append(w, content);
	Widget_Append(w, close);
}

static void NotificationNotice_OnDestroy(LCUI_Widget w)
{
	NotificationNotice notice;

	notice = Widget_GetData(w, self.notice_proto);
	if (notice->timer) {
		LCUITimer_Free(notice->timer);
	}
}

static void NotificationNotice_SetConfig(LCUI_Widget w,
					 LCDesign_NotificationConfig config)
{
	NotificationNotice notice;

	notice = Widget_GetData(w, self.notice_proto);
	if (notice->timer) {
		LCUITimer_Free(notice->timer);
		notice->timer = 0;
	}
	if (notice->icon) {
		Widget_Destroy(notice->icon);
		notice->icon = NULL;
	}
	if (config->icon) {
		config->icon = config->icon;
		Widget_AddClass(w, $NAME "-has-icon");
		Widget_AddClass(config->icon, $NAME "-icon");
		Widget_Append(w, config->icon);
	} else {
		Widget_RemoveClass(w, $NAME "-has-icon");
	}
	if (config->duration > 0) {
		notice->timer = LCUI_SetTimeout(
		    config->duration, (TimerCallback)Widget_Destroy, w);
	}
	TextView_SetTextW(notice->title, config->title);
	TextView_SetTextW(notice->description, config->description);
}

void LCDesign_SetNotificationContainer(LCUI_Widget w)
{
	self.custom_container = w;
}

LCUI_Widget LCDesign_OpenNotification(LCDesign_NotificationConfig config)
{
	LCUI_Widget notice;
	LCUI_Widget container;

	const char *placement = config->placement;

	if (!placement) {
		placement = "top-right";
	}
	if (self.custom_container) {
		container = self.custom_container;
	} else if (strcmp(placement, "top-left") == 0) {
		container = self.top_left_container;
		if (!container) {
			container = LCUIWidget_New(NULL);
			self.top_left_container = container;
			Widget_AddClass(container,
					"notification-container "
					"notification-container-top-left");
			Widget_Append(LCUIWidget_GetRoot(), container);
		}
	} else if (strcmp(placement, "bottom-left") == 0) {
		container = self.bottom_left_container;
		if (!container) {
			container = LCUIWidget_New(NULL);
			self.bottom_left_container = container;
			Widget_AddClass(container,
					"notification-container "
					"notification-container-bottom-left");
			Widget_Append(LCUIWidget_GetRoot(), container);
		}
	} else if (strcmp(placement, "bottom-right") == 0) {
		container = self.bottom_right_container;
		if (!container) {
			container = LCUIWidget_New(NULL);
			self.bottom_right_container = container;
			Widget_AddClass(container,
					"notification-container "
					"notification-container-bottom-right");
			Widget_Append(LCUIWidget_GetRoot(), container);
		}
	} else {
		container = self.top_right_container;
		if (!container) {
			container = LCUIWidget_New(NULL);
			self.top_right_container = container;
			Widget_AddClass(container,
					"notification-container "
					"notification-container-top-right");
			Widget_Append(LCUIWidget_GetRoot(), container);
		}
	}
	notice = LCUIWidget_New($NAME);
	NotificationNotice_SetConfig(notice, config);
	Widget_Append(container, notice);
	return notice;
}

void LCDesign_CloseNotification(LCUI_Widget noti)
{
	Widget_Destroy(noti);
}

LCUI_Widget LCDesign_OpenNormalNotification(const wchar_t *title,
					    const wchar_t *description,
					    const char *placement,
					    long duration)
{
	LCDesign_NotificationConfigRec config;

	config.icon = NULL;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

LCUI_Widget LCDesign_OpenSuccessNotification(const wchar_t *title,
					     const wchar_t *description,
					     const char *placement,
					     long duration)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "check-circle-outline");
	Widget_AddClass(icon, $NAME "-icon-success");

	config.icon = icon;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

LCUI_Widget LCDesign_OpenInfoNotification(const wchar_t *title,
					  const wchar_t *description,
					  const char *placement, long duration)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "information-outline");
	Widget_AddClass(icon, $NAME "-icon-info");

	config.icon = icon;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

LCUI_Widget LCDesign_OpenWarningNotification(const wchar_t *title,
					     const wchar_t *description,
					     const char *placement,
					     long duration)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "alert-circle-outline");
	Widget_AddClass(icon, $NAME "-icon-warning");

	config.icon = icon;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

LCUI_Widget LCDesign_OpenErrorNotification(const wchar_t *title,
					   const wchar_t *description,
					   const char *placement, long duration)
{
	LCUI_Widget icon;
	LCDesign_NotificationConfigRec config;

	icon = LCUIWidget_New("icon");
	Icon_SetName(icon, "close-circle-outline");
	Widget_AddClass(icon, $NAME "-icon-error");

	config.icon = icon;
	config.title = title;
	config.placement = placement;
	config.description = description;
	config.duration = duration;
	return LCDesign_OpenNotification(&config);
}

void LCDesign_InitNotification(void)
{
	self.notice_proto = LCUIWidget_NewPrototype($NAME, NULL);
	self.notice_proto->init = NotificationNotice_OnInit;
	self.notice_proto->destroy = NotificationNotice_OnDestroy;
}
