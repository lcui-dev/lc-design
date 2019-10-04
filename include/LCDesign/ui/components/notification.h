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

LCUI_API void LCDesign_SetNotificationContainer(LCUI_Widget w);

LCUI_API LCUI_Widget
LCDesign_OpenNotification(LCDesign_NotificationConfig config);

LCUI_API void LCDesign_CloseNotification(LCUI_Widget message);

LCUI_API LCUI_Widget LCDesign_OpenNormalNotification(const wchar_t *title,
						     const wchar_t *description,
						     const char *placement,
						     long duration);

LCUI_API LCUI_Widget LCDesign_OpenSuccessNotification(
    const wchar_t *title, const wchar_t *description, const char *placement,
    long duration);

LCUI_API LCUI_Widget LCDesign_OpenInfoNotification(const wchar_t *title,
						   const wchar_t *description,
						   const char *placement,
						   long duration);

LCUI_API LCUI_Widget LCDesign_OpenWarningNotification(
    const wchar_t *title, const wchar_t *description, const char *placement,
    long duration);

LCUI_API LCUI_Widget LCDesign_OpenErrorNotification(const wchar_t *title,
						    const wchar_t *description,
						    const char *placement,
						    long duration);

#endif
