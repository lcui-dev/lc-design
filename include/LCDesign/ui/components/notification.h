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

#ifndef LCDESIGN_NOTIFICATION_H
#define LCDESIGN_NOTIFICATION_H

typedef struct LCDesign_NotificationConfigRec_ {
	/** Customized Icon */
	LCUI_Widget icon;

	/** The title of notification box (required) */
	const wchar_t *title;

	/** The content of notification box (required) */
	const wchar_t *description;

	/** Position of Notification, can be one of top-left, top-right,
	 * bottom-left, bottom-right */
	const char *placement;

	/** time(milliseconds) before auto-dismiss, don't dismiss if set to 0 */
	long duration;
} LCDesign_NotificationConfigRec, *LCDesign_NotificationConfig;

LCDESIGN_API void LCDesign_SetNotificationContainer(LCUI_Widget w);

LCDESIGN_API LCUI_Widget
LCDesign_OpenNotification(LCDesign_NotificationConfig config);

LCDESIGN_API void LCDesign_CloseNotification(LCUI_Widget message);

LCDESIGN_API LCUI_Widget LCDesign_OpenNormalNotification(const wchar_t *title,
						     const wchar_t *description,
						     const char *placement,
						     long duration);

LCDESIGN_API LCUI_Widget LCDesign_OpenSuccessNotification(
    const wchar_t *title, const wchar_t *description, const char *placement,
    long duration);

LCDESIGN_API LCUI_Widget LCDesign_OpenInfoNotification(const wchar_t *title,
						   const wchar_t *description,
						   const char *placement,
						   long duration);

LCDESIGN_API LCUI_Widget LCDesign_OpenWarningNotification(
    const wchar_t *title, const wchar_t *description, const char *placement,
    long duration);

LCDESIGN_API LCUI_Widget LCDesign_OpenErrorNotification(const wchar_t *title,
						    const wchar_t *description,
						    const char *placement,
						    long duration);

LCDESIGN_API void LCDesign_InitNotification(void);

#endif
